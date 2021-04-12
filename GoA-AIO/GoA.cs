using System;
using System.IO;
using System.Text;
using System.Diagnostics;
using System.Runtime.InteropServices;

namespace GoA
{
    class Native
    {
        [DllImport("kernel32.dll")]
        public static extern IntPtr LoadLibrary(string dll);

        [DllImport("kernel32.dll")]
        public static extern IntPtr OpenProcess(int access, bool inherit, int procId);

        [DllImport("kernel32.dll", CharSet = CharSet.Auto)]
        public static extern IntPtr GetModuleHandle(string name);

        [DllImport("kernel32.dll", CharSet = CharSet.Ansi, ExactSpelling = true, SetLastError = true)]
        public static extern IntPtr GetProcAddress(IntPtr module, string procName);

        [DllImport("kernel32.dll", SetLastError = true, ExactSpelling = true)]
        public static extern IntPtr VirtualAllocEx(IntPtr proc, IntPtr funcAddress, uint size, uint allocType, uint protect);

        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern bool WriteProcessMemory(IntPtr proc, IntPtr baseAddress, byte[] buffer, uint size, out UIntPtr numBytesWrote);

        [DllImport("kernel32.dll")]
        public static extern IntPtr CreateRemoteThread(IntPtr proc, IntPtr threadAttribs, uint stackSize, IntPtr startAddress, IntPtr param, uint creationFlags, IntPtr threadId);

        [DllImport("kernel32", CharSet = CharSet.Auto, SetLastError = true)]
        public static extern bool CloseHandle(IntPtr handle);

        public const int PROCESS_CREATE_THREAD = 0x0002;
        public const int PROCESS_QUERY_INFORMATION = 0x0400;
        public const int PROCESS_VM_OPERATION = 0x0008;
        public const int PROCESS_VM_WRITE = 0x0020;
        public const int PROCESS_VM_READ = 0x0010;

        public const int PROCESS_ALL_ACCESS = PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ;

        public const uint MEM_COMMIT = 0x00001000;
        public const uint MEM_RESERVE = 0x00002000;
        public const uint PAGE_READWRITE = 4;

        public const uint MEM_ALL = MEM_COMMIT | MEM_RESERVE;
    }

    public class GoA
    {
        public IntPtr KH2Handle { private set; get; }
        public IntPtr DLLHandle { private set; get; }
        public string DLLPath { private set; get; }

        private IntPtr SetDrivePtr { set; get; }
        private IntPtr DriveParamPtr { set; get; }

        private IntPtr SetChestItemPtr { set; get; }
        private IntPtr SetChestItemParamPtr { set; get; }

        public GoA()
        {
            KH2Handle = IntPtr.Zero;
            DLLPath = Directory.GetCurrentDirectory() + "\\GoA.dll";

            DriveParamPtr = IntPtr.Zero;
        }

        public int GetProcessId(string procName)
        {
            int ret = 0;
            Process[] targetProcesses = Process.GetProcessesByName(procName);
            if (targetProcesses.Length > 0)
                ret = targetProcesses[0].Id;

            return ret;
        }

        public bool Inject(int procId)
        {
            if (KH2Handle != IntPtr.Zero)
                return false;

            uint DLLPathSize = (uint)((DLLPath.Length + 1) * Marshal.SizeOf<char>());

            KH2Handle = Native.OpenProcess(Native.PROCESS_ALL_ACCESS, false, procId);
            if (KH2Handle == IntPtr.Zero)
                return false;

            IntPtr loadLibraryAddress = Native.GetProcAddress(Native.GetModuleHandle("kernel32.dll"), "LoadLibraryA");
            if (loadLibraryAddress == IntPtr.Zero)
                return false;

            IntPtr dllPathAddress = Native.VirtualAllocEx(KH2Handle, IntPtr.Zero, DLLPathSize, Native.MEM_ALL, Native.PAGE_READWRITE);
            if (dllPathAddress == IntPtr.Zero)
                return false;

            UIntPtr bytesWritten;
            if (!Native.WriteProcessMemory(KH2Handle, dllPathAddress, Encoding.Default.GetBytes(DLLPath), DLLPathSize, out bytesWritten))
                return false;

            IntPtr threadHandle = Native.CreateRemoteThread(KH2Handle, IntPtr.Zero, 0, loadLibraryAddress, dllPathAddress, 0, IntPtr.Zero);
            if (threadHandle == IntPtr.Zero)
                return false;
            else
                Native.CloseHandle(threadHandle);

            return true;
        }

        public void Run()
        {
            DLLHandle = Native.LoadLibrary("GoA.dll");

            IntPtr funcPtr = Native.GetProcAddress(DLLHandle, "GoA_Run");
            IntPtr threadHandle = Native.CreateRemoteThread(KH2Handle, IntPtr.Zero, 0, funcPtr, IntPtr.Zero, 0, IntPtr.Zero);
            if (threadHandle != IntPtr.Zero)
                Native.CloseHandle(threadHandle);
        }

        public void SetDrive(byte value)
        {
            if (DriveParamPtr == IntPtr.Zero)
                DriveParamPtr = Native.VirtualAllocEx(KH2Handle, IntPtr.Zero, (uint)Marshal.SizeOf<byte>(), Native.MEM_ALL, Native.PAGE_READWRITE);

            if (SetDrivePtr == IntPtr.Zero)
                SetDrivePtr = Native.GetProcAddress(DLLHandle, "GoA_SetDrive");

            byte[] bytes = { value };

            UIntPtr bytesWritten;
            if (Native.WriteProcessMemory(KH2Handle, DriveParamPtr, bytes, (uint)Marshal.SizeOf<byte>(), out bytesWritten))
            {
                IntPtr threadHandle = Native.CreateRemoteThread(KH2Handle, IntPtr.Zero, 0, SetDrivePtr, DriveParamPtr, 0, IntPtr.Zero);
                if (threadHandle != IntPtr.Zero)
                    Native.CloseHandle(threadHandle);
            }
        }

        struct Chest
        {
            public int offset;
            public short value;
        }

        public void SetChestItem(int offset, short value)
        {
            if (SetChestItemParamPtr == IntPtr.Zero)
                SetChestItemParamPtr = Native.VirtualAllocEx(KH2Handle, IntPtr.Zero, (uint)Marshal.SizeOf<Chest>(), Native.MEM_ALL, Native.PAGE_READWRITE);

            if (SetChestItemPtr == IntPtr.Zero)
                SetChestItemPtr = Native.GetProcAddress(DLLHandle, "GoA_SetChestItem");

            Chest chest = new Chest()
            {
                offset = offset,
                value = value
            };

            //TODO(skettios): better way to do this?
            byte[] bytes = new byte[Marshal.SizeOf<Chest>()];
            IntPtr ptr = Marshal.AllocHGlobal(Marshal.SizeOf<Chest>());
            Marshal.StructureToPtr(chest, ptr, true);
            Marshal.Copy(ptr, bytes, 0, Marshal.SizeOf<Chest>());
            Marshal.FreeHGlobal(ptr);

            UIntPtr bytesWritten;
            Native.WriteProcessMemory(KH2Handle, SetChestItemParamPtr, bytes, (uint)Marshal.SizeOf<Chest>(), out bytesWritten);

            IntPtr threadHandle = Native.CreateRemoteThread(KH2Handle, IntPtr.Zero, 0, SetChestItemPtr, SetChestItemParamPtr, 0, IntPtr.Zero);
            if (threadHandle != IntPtr.Zero)
                Native.CloseHandle(threadHandle);
        }

        /*
        public void CallFunction(string funcName)
        {
            IntPtr funcAddress = Native.GetProcAddress(DLLHandle, funcName);
            IntPtr threadHandle = Native.CreateRemoteThread(KH2Handle, IntPtr.Zero, 0, funcAddress, IntPtr.Zero, 0, IntPtr.Zero);
            if (threadHandle != IntPtr.Zero)
                Native.CloseHandle(threadHandle);
        }
        */
    }
}
