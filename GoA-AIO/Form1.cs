using System;
using System.Windows.Forms;
using System.IO;
using System.Runtime.InteropServices;

namespace GoA
{
    public partial class Form1 : Form
    {
        private Timer _waitProcTimer;
        private GoA _GoA;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            _GoA = new GoA();

            _waitProcTimer = new Timer
            {
                Interval = 100
            };
            _waitProcTimer.Tick += Timer_Tick;
            _waitProcTimer.Start();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            label1.Text = "Waiting for KINGDOM HEARTS II FINAL MIX";

            int procId = _GoA.GetProcessId("KINGDOM HEARTS II FINAL MIX");
            if (procId != 0)
            {
                if (_GoA.Inject(procId))
                {
                    _GoA.Run();

                    label1.Text = "GoA.dll injected!";
                    _waitProcTimer.Stop();
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            _GoA.SetDrive(byte.Parse(textBox1.Text));
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (_waitProcTimer.Enabled)
                _waitProcTimer.Stop();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int offset = int.Parse(textBox2.Text, System.Globalization.NumberStyles.HexNumber);
            short value = short.Parse(textBox3.Text, System.Globalization.NumberStyles.HexNumber);

            _GoA.SetChestItem(offset, value);
        }
    }
}
