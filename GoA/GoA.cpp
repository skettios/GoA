#include <Windows.h>
#include "Globals.h"
#include "Helpers.h"
#define _USE_MATH_DEFINES
#include <math.h>

struct Chest
{
	int offset;
	short value;
};

void GoA()
{
	if (Place == 0x1A04)
	{
		WriteString(Object00Address + 0x13450, "SHOP_POINT\0");
		WriteString(Object00Address + 0x13470, "N_EX960_RTN.mset\0");
		WriteShort(System03Address + 0x16F40, 0x001);
		WriteShort(System03Address + 0x16F42, 0x003);

		// Middle Chest
		if (ReadShort(SaveAddress + 0x06AC) == 0x02)
			WriteShort(SaveAddress + 0x06AC, 0x00);

		// Right Chest
		SpawnObj<float>(0x07, 0x038, -160);
		SpawnObj<float>(0x07, 0x040, 360);
		SpawnObj<float>(0x07, 0x048, M_PI / 2.f);
		// Left Chest
		SpawnObj<float>(0x07, 0x078, -160);
		SpawnObj<float>(0x07, 0x080, -360);
		SpawnObj<float>(0x07, 0x088, M_PI / 2.f);
		// Save Point & Moogle Shop
		int Spawn = 0;
		int File = 0x02;
		if (Door == 0x32)
		{
			File = 0x0B;
			Spawn = 0x074;
		}
		else if (Door == 0x00)
			Spawn = 0xA60;
		else if (Door == 0x01)
			Spawn = 0x0B4C;
		else if (Door == 0x15)
			Spawn = 0x074;
		else if (Door == 0x16)
			Spawn = 0x134;
		else if (Door == 0x17)
			Spawn = 0x1F4;
		else if (Door == 0x18)
			Spawn = 0x2B4;
		else if (Door == 0x19)
			Spawn = 0x374;
		else if (Door == 0x1A)
			Spawn = 0x434;
		else if (Door == 0x1B)
			Spawn = 0x4F4;
		else if (Door == 0x1C)
			Spawn = 0x5B4;
		else if (Door == 0x1D)
			Spawn = 0x674;
		else if (Door == 0x1E)
			Spawn = 0x734;
		else if (Door == 0x1F)
			Spawn = 0x7F4;
		else if (Door == 0x20)
			Spawn = 0x8B4;
		else if (Door == 0x21)
			Spawn = 0x974;

		if (Spawn)
		{
			// Save Point
			SpawnObj<short>(File, Spawn + 0x00, 0x23A);
			SpawnObj<float>(File, Spawn + 0x04, 0);
			SpawnObj<float>(File, Spawn + 0x08, 460);
			SpawnObj<float>(File, Spawn + 0x0C, -900);

			// Moogle Shop
			SpawnObj<short>(File, Spawn + 0x40, 0x4A1);
			SpawnObj<float>(File, Spawn + 0x44, 0);
			SpawnObj<float>(File, Spawn + 0x48, 460);
			SpawnObj<float>(File, Spawn + 0x4C, 900);
			SpawnObj<float>(File, Spawn + 0x54, 0);

			// Shop RC
			SpawnObj<short>(File, Spawn + 0x6C, 0x0D1);
		}
	}
	else
	{
		WriteString(Object00Address + 0x13450, "N_EX700_TT_WEAPON_RTN");
		WriteString(Object00Address + 0x13470, "N_EX700_SHOP_RTN.mset");
		WriteShort(System03Address + 0x16F40, 0x094);
		WriteShort(System03Address + 0x16F42, 0x08B);
	}

	// World Map->Garden of Assemblage
	if (Place == 0x000F)
	{
		if (Door == 0x0C) //The World that Never Was
			Warp(0x04, 0x1A, 0x15, 0x00, 0x00, 0x02);
		else if (Door == 0x03) //Land of Dragons
			Warp(0x04, 0x1A, 0x16, 0x00, 0x00, 0x02);
		else if (Door == 0x04) // Beast's Castle
			Warp(0x04, 0x1A, 0x17, 0x00, 0x00, 0x02);
		else if (Door == 0x09) //Halloween Town
			Warp(0x04, 0x1A, 0x18, 0x00, 0x00, 0x02);
		else if (Door == 0x0A) //Agrabah
			Warp(0x04, 0x1A, 0x19, 0x00, 0x00, 0x02);
		else if (Door == 0x05) //Olympus Coliseum
			Warp(0x04, 0x1A, 0x1A, 0x00, 0x00, 0x02);
		else if (Door == 0x0B) //Pride Lands
			Warp(0x04, 0x1A, 0x1B, 0x00, 0x00, 0x02);
		else if (Door == 0x01) //Twilight Town
		{
			if (ReadByte(SaveAddress + 0x1CFF) == 8) //Twilight Town
				Warp(0x04, 0x1A, 0x1C, 0x00, 0x00, 0x02);
			else if (ReadByte(SaveAddress + 0x1CFF) == 13) //Simulated Twilight Town
				Warp(0x04, 0x1A, 0x21, 0x00, 0x00, 0x02);

			WriteByte(SaveAddress + 0x1CFF, 0);
		}
		else if (Door == 0x02) //Hollow Bastion
		{
			Warp(0x04, 0x1A, 0x1D, 0x00, 0x00, 0x02);
			if (ReadByte(SaveAddress + 0x1D2F) == 1) //During Ravine Heartless
				WriteInt(SaveAddress + 0x3544, 0x12020100); //Add Goofy
		}
		else if (Door == 0x08) //Port Royal
			Warp(0x04, 0x1A, 0x1E, 0x00, 0x00, 0x02);
		else if (Door == 0x06) //Disney Castle
			Warp(0x04, 0x1A, 0x1F, 0x00, 0x00, 0x02);
		else if (Door == 0x07) //Atlantica
			Warp(0x04, 0x1A, 0x01, 0x00, 0x00, 0x02);
	}

	if (Place == 0x0004)
	{
		short PrevWorld = PrevPlace & 0xFF;
		if (PrevWorld == 0x12) // twtnw
			Warp(0x04, 0x1A, 0x15, 0x00, 0x00, 0x02);
		else if (PrevWorld == 0x08) // lod
			Warp(0x04, 0x1A, 0x16, 0x00, 0x00, 0x02);
		else if (PrevWorld == 0x05) // bc
			Warp(0x04, 0x1A, 0x17, 0x00, 0x00, 0x02);
		else if (PrevWorld == 0x0E) // ht
			Warp(0x04, 0x1A, 0x18, 0x00, 0x00, 0x02);
		else if (PrevWorld == 0x07) //agrabah
			Warp(0x04, 0x1A, 0x19, 0x00, 0x00, 0x02);
		else if (PrevWorld == 0x06) // oc
			Warp(0x04, 0x1A, 0x1A, 0x00, 0x00, 0x02);
		else if (PrevWorld == 0x0A) // pl
			Warp(0x04, 0x1A, 0x1B, 0x00, 0x00, 0x02);
		else if (PrevWorld == 0x02)
		{
			if (ReadByte(SaveAddress + 0x1CFF) == 8)
				Warp(0x04, 0x1A, 0x1C, 0x00, 0x00, 0x02); // tt
			else if (ReadByte(SaveAddress + 0x1CFF) == 13)
				Warp(0x04, 0x1A, 0x21, 0x00, 0x00, 0x02); // stt

			WriteByte(SaveAddress + 0x1CFF, 0);
		}
		else if (PrevWorld == 0x04) // hb
			Warp(0x04, 0x1A, 0x1D, 0x00, 0x00, 0x02);
		else if (PrevWorld == 0x10) // pr
			Warp(0x04, 0x1A, 0x1E, 0x00, 0x00, 0x02);
		else if (PrevWorld == 0x0C || PrevWorld == 0x0D) //dc/tr
			Warp(0x04, 0x1A, 0x1F, 0x00, 0x00, 0x02);
		else if (PrevWorld == 0x11) // sp
			Warp(0x04, 0x1A, 0x20, 0x00, 0x00, 0x02);
	}
}

extern "C"
{
	short __declspec(dllexport) GoA_GetCurrentMap()
	{
		return ReadShort(CurrentMapAddress);
	}

	void __declspec(dllexport) GoA_SetChestItem(Chest *chest)
	{
		WriteShort(BaseAddress + chest->offset, chest->value);
	}

	void __declspec(dllexport) GoA_SetDrive(char *value)
	{
		WriteByte(Slot1Address + 0x1B1, *value);
	}
}
