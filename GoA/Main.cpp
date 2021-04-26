#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include "Globals.h"
#include "Helpers.h"

extern "C"
{
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
}

#define CurrentLocationOffset	0x0714DB8
#define CutsceneLengthOffset	0x0B62774
#define CutsceneSkipOffset		0x0B6275C
#define SaveOffset				0x09A7070
#define GameSpeedOffset			0x07151D4
#define PauseOffset				0x0AB9038
#define Slot1Offset				0x2A20C48
#define Battle00Offset			0x2A74840
#define Object00Offset			0x2A22B90
#define System03Offset			0x2A59DB0

/* Precalculated addresses */
char* BaseAddress;
char* CurrentLocationAddress;
char* CutsceneLengthAddress;
char* CutsceneSkipAddress;
char* SaveAddress;

char* Object00Address;
char* System03Address;

char* CurrentWorldAddress;
char* CurrentRoomAddress;
char* CurrentPlaceAddress;
char* CurrentDoorAddress;
char* CurrentMapAddress;
char* CurrentBattleAddress;
char* CurrentEventAddress;
char* PreviousPlaceAddress;

char* PauseAddress;
char* GameSpeedAddress;
char* Slot1Address;

/* Location Struct */
char World = 0;
char Room = 0;
short Place = 0;
short Door = 0;
short Map = 0;
short Battle = 0;
short Event = 0;
short PrevPlace = 0;
int64_t ARD = 0;

extern void GoA();
extern void LoD();
extern void STT();

void NewGame()
{
	if (Place == 0xFFFF || Place == 0x0101 || (Place == 0x0102 && IsEvent(0x34, 0x34, 0x34)))
	{
		if (Read<short>(BaseAddress + Battle00Offset + 0x312E6) == 0x81A1)
			Write<short>(BaseAddress + Battle00Offset + 0x312E6, 0x01A1);

		if (Read<short>(BaseAddress + Battle00Offset + 0x314EA) == 0x81A1)
			Write<short>(BaseAddress + Battle00Offset + 0x314EA, 0x01A1);

		if (Read<short>(BaseAddress + Battle00Offset + 0x315EA) == 0x81A1)
			Write<short>(BaseAddress + Battle00Offset + 0x315EA, 0x01A1);
		
		if (Read<char>(Object00Address + 0x05295) == 0x34)
		{
			Write<const char *>(Object00Address + 0x05290, "F_EX030");
			Write<const char *>(Object00Address + 0x052B0, "F_EX030.mset");
			Write<const char *>(Object00Address + 0x052F0, "F_EX030_TR");
			Write<const char *>(Object00Address + 0x05310, "F_EX030.mset");
			Write<const char *>(Object00Address + 0x0BD10, "F_EX030_BB");
			Write<const char *>(Object00Address + 0x0BD30, "F_EX030.mset");
			Write<const char *>(Object00Address + 0x0BD70, "F_EX030_HE");
			Write<const char *>(Object00Address + 0x0BD90, "F_EX030.mset");
			Write<const char *>(Object00Address + 0x0BDD0, "F_EX030_AL");
			Write<const char *>(Object00Address + 0x0BDF0, "F_EX030.mset");
			Write<const char *>(Object00Address + 0x0BE30, "F_EX030_CA");
			Write<const char *>(Object00Address + 0x0BE50, "F_EX030.mset");
			Write<const char *>(Object00Address + 0x0BE90, "F_EX030_NM");
			Write<const char *>(Object00Address + 0x0BEB0, "F_EX030.mset");
			Write<const char *>(Object00Address + 0x0BEF0, "F_EX030_MU");
			Write<const char *>(Object00Address + 0x0BF10, "F_EX030.mset");
			Write<const char *>(Object00Address + 0x0BF50, "F_EX030_PO");
			Write<const char *>(Object00Address + 0x0BF70, "F_EX030.mset");
			Write<const char *>(Object00Address + 0x0BFB0, "F_EX030_DC");
			Write<const char *>(Object00Address + 0x0BFD0, "F_EX030.mset");
			Write<const char *>(Object00Address + 0x0C010, "F_EX030_WI");
			Write<const char *>(Object00Address + 0x0C030, "F_EX030.mset");
			Write<const char *>(Object00Address + 0x0C070, "F_EX030_EH");
			Write<const char *>(Object00Address + 0x0C090, "F_EX030.mset");
			Write<const char *>(Object00Address + 0x231D0, "F_EX050");
			Write<const char *>(Object00Address + 0x231F0, "F_EX050.mset");
			Write<const char *>(Object00Address + 0x23590, "F_EX030_NM_XMAS");
			Write<const char *>(Object00Address + 0x235B0, "F_EX030.mset");
			Write<const char *>(Object00Address + 0x256F0, "F_EX030_TT");
			Write<const char *>(Object00Address + 0x25710, "F_EX030_TT.mset");
			Write<const char *>(Object00Address + 0x2C050, "F_EX030_EH");
			Write<const char *>(Object00Address + 0x2C070, "F_EX030.mset");
		}
	}

	if (Place == 0x0102)
	{
		if (IsEvent(0x34, 0x34, 0x34))
			SkipCutscene();

		if (IsEvent(0x38, 0x38, 0x38))
		{
			Warp(0x02, 0x20, 0x32, 0x01, 0x01, 0x01);
			BitNot(SaveAddress + 0x1CD2, (char)0xC0);
			BitOr(SaveAddress + 0x1CEA, (char)0x03);
		}
	}

	if (Place == 0x2002)
	{
		if (IsEvent(0x01, 0x01, 0x01))
		{
			SpawnObj<short>(0x0E, 0x034, 0x745);
			SpawnObj<short>(0x0E, 0x074, 0x433);
			SpawnObj<short>(0x0E, 0x0B4, 0x434);
			Write<char>(PauseAddress, 0x02);
			if (Read<int>(CutsceneLengthAddress) == 0x246)
				SkipCutscene();

			Write<char>(SaveAddress + 0x35AE, 1); //Have 1 Battlefields of War
			Write<char>(SaveAddress + 0x35AF, 1); //Have 1 Sword of the Ancestors
			Write<char>(SaveAddress + 0x35B3, 1); //Have 1 Beast's Claw
			Write<char>(SaveAddress + 0x35B4, 1); //Have 1 Bone Fist
			Write<char>(SaveAddress + 0x35B5, 1); //Have 1 Proud Fang
			Write<char>(SaveAddress + 0x35B6, 1); //Have 1 Skill and Crossbones
			Write<char>(SaveAddress + 0x35C0, 1); //Have 1 Scimitar
			Write<char>(SaveAddress + 0x35C1, 1); //Have 1 Way to the Dawn
			Write<char>(SaveAddress + 0x35C2, 1); //Have 1 Identity Disk
			Write<char>(SaveAddress + 0x363F, 1); //Have 1 Tournament Poster
			Write<char>(SaveAddress + 0x3640, 1); //Have 1 Poster
			Write<char>(SaveAddress + 0x3641, 1); //Have 1 Letter
			Write<char>(Slot1Address + 0x1B0, 100); //Starting Drive %
			Write<char>(Slot1Address + 0x1B1, 5);   //Starting Drive Current
			Write<char>(Slot1Address + 0x1B2, 5);   //Starting Drive Max
		}

		if (IsEvent(0x9A, 0x9A, 0x9A) && Read<char>(SaveAddress + 0x1CD8) == 0x00)
		{
			Warp(0x04, 0x1A, 0x00, 0x01, 0x00, 0x01);

			// Place Scripts
			Write<short>(SaveAddress + 0x06AC, 0x01); //Garden of Assemblage MAP(Before Computer)
			Write<short>(SaveAddress + 0x06B0, 0x01); //Garden of Assemblage EVT
			Write<short>(SaveAddress + 0x1B5E, 0x01); //Proof of Existence MAP(Lock Progress)
			BitOr(SaveAddress + 0x239E, 0x07);  //Pause Menu(1 = Items, 2 = Party, 4 = Customize)
			BitNot(SaveAddress + 0x239E, 0x80); //Show Struggle Bats Outside STT
			Write<short>(SaveAddress + 0x32F4, 0x051); //Valor Form equips FAKE
			Write<short>(SaveAddress + 0x339C, 0x02C); //Master Form equips Detection Saber
			Write<short>(SaveAddress + 0x33D4, 0x02D); //Final Form equips Edge of Ultima
			Write<short>(SaveAddress + 0x4270, 0x01FF); //Pause Menu Tutorial Prompts Seen Flags
			Write<short>(SaveAddress + 0x4274, 0x01FF); //Status Form & Summon Seen Flags

			// Unlock Shop Weapons
			BitOr(SaveAddress + 0x49F0, 0x03); //Shop Tutorial Prompt Flags(1 = Big Shops, 2 = Small Shops)
			BitOr(SaveAddress + 0x2396, 0x10); //Comet Staff & Falling Star(Olympus Coliseum)
			BitOr(SaveAddress + 0x2396, 0x40); //Victory Bell & Chain Gear(Port Royal)
			BitOr(SaveAddress + 0x2397, 0x80); //Lord's Broom & Dreamcloud (Pride Lands)
			BitOr(SaveAddress + 0x2398, 0x04); //Wisdom Wand & Knight Defender(The World that Never Was)

			// Unlock Data Portals
			BitOr(SaveAddress + 0x1D35, 0x01); //Xaldin
			BitOr(SaveAddress + 0x1D23, 0x08); //Vexen
			BitOr(SaveAddress + 0x1D23, 0x10); //Lexaeus
			BitOr(SaveAddress + 0x1D23, 0x40); //Zexion
			BitOr(SaveAddress + 0x1CE9, 0x04); //Axel
			BitOr(SaveAddress + 0x1D15, 0x08); //Demyx
			BitOr(SaveAddress + 0x1D23, 0x80); //Marluxia
			BitOr(SaveAddress + 0x1D23, 0x20); //Larxene
			BitOr(SaveAddress + 0x1ED9, 0x01); //TWtNW Members

			// Story Flags
			BitOr(SaveAddress + 0x1CE2, 0x10); //TT_SCENARIO_7_OPEN
			BitOr(SaveAddress + 0x1CE9, 0x20); //TT_908_END_L(Scene Before TT2)
			BitOr(SaveAddress + 0x1CE5, 0x80); //TT_SCENARIO_9_OPEN
			BitOr(SaveAddress + 0x1CE7, 0x08); //TT_SCENARIO_10_OPEN
			BitOr(SaveAddress + 0x1D1B, 0x10); //HB_SCENARIO_1_OPEN
			BitOr(SaveAddress + 0x1D1B, 0x80); //HB_SCENARIO_2_OPEN
			BitOr(SaveAddress + 0x1D1C, 0x01); //HB_SCENARIO_2_START
			BitOr(SaveAddress + 0x1D1E, 0x02); //HB_SCENARIO_3_OPEN
			BitOr(SaveAddress + 0x1D1E, 0x10); //HB_SCENARIO_4_OPEN
			BitOr(SaveAddress + 0x1D1C, 0x04); //HB_SCENARIO_5_OPEN
			BitOr(SaveAddress + 0x1D31, 0x10); //BB_SCENARIO_1_OPEN
			BitOr(SaveAddress + 0x1D32, 0x01); //BB_SCENARIO_2_OPEN
			BitOr(SaveAddress + 0x1D53, 0x80); //HE_SCENARIO_1_OPEN
			BitOr(SaveAddress + 0x1D55, 0x02); //HE_W_COL_ON(Underdrome Unlocked Scene)
			BitOr(SaveAddress + 0x1D54, 0x08); //HE_SCENARIO_2_OPEN
			BitOr(SaveAddress + 0x1D73, 0x04); //AL_SCENARIO_1_OPEN
			BitOr(SaveAddress + 0x1D73, 0x20); //AL_SCENARIO_2_OPEN
			BitOr(SaveAddress + 0x1D91, 0x04); //MU_SCENARIO_1_OPEN
			BitOr(SaveAddress + 0x1D91, 0x20); //MU_SCENARIO_2_OPEN
			BitOr(SaveAddress + 0x1DB7, 0x04); //PO_SCENARIO_0_OPEN
			BitOr(SaveAddress + 0x1DD5, 0x08); //LK_SCENARIO_1_OPEN
			BitOr(SaveAddress + 0x1DD5, 0x40); //LK_SCENARIO_2_OPEN
			BitOr(SaveAddress + 0x1DF6, 0x01); //LM_SCENARIO_1_OPEN
			BitOr(SaveAddress + 0x1E11, 0x08); //DC_SCENARIO_1_OPEN
			BitOr(SaveAddress + 0x1E57, 0x01); //NM_SCENARIO_1_OPEN
			BitOr(SaveAddress + 0x1E56, 0x20); //NM_SCENARIO_2_OPEN
			BitOr(SaveAddress + 0x1E99, 0x08); //CA_SCENARIO_1_OPEN
			BitOr(SaveAddress + 0x1E99, 0x40); //CA_SCENARIO_2_OPEN
			BitOr(SaveAddress + 0x1EB5, 0x40); //TR_SCENARIO_1_OPEN
			BitOr(SaveAddress + 0x1EB6, 0x02); //TR_SCENARIO_2_OPEN
			BitOr(SaveAddress + 0x1ED5, 0x80); //EH_SCENARIO_1_OPEN
			BitOr(SaveAddress + 0x1ED8, 0x04); //EH_FINAL_CHANCE_START
		}
	}
}

extern "C"
{
	void __declspec(dllexport) GoA_Lua()
	{
		BaseAddress = (char*)GetModuleHandle(NULL);
		CurrentLocationAddress = BaseAddress + CurrentLocationOffset;
		CutsceneLengthAddress = BaseAddress + CutsceneLengthOffset;
		CutsceneSkipAddress = BaseAddress + CutsceneSkipOffset;
		SaveAddress = BaseAddress + SaveOffset;

		Object00Address = BaseAddress + Object00Offset;
		System03Address = BaseAddress + System03Offset;

		CurrentWorldAddress = CurrentLocationAddress + 0x0;
		CurrentRoomAddress = CurrentLocationAddress + 0x01;
		CurrentPlaceAddress = CurrentLocationAddress + 0x00;
		CurrentDoorAddress = CurrentLocationAddress + 0x02;
		CurrentMapAddress = CurrentLocationAddress + 0x04;
		CurrentBattleAddress = CurrentLocationAddress + 0x06;
		CurrentEventAddress = CurrentLocationAddress + 0x08;
		PreviousPlaceAddress = CurrentLocationAddress + 0x30;

		PauseAddress = BaseAddress + PauseOffset;
		GameSpeedAddress = BaseAddress + GameSpeedOffset;
		Slot1Address = BaseAddress + Slot1Offset;

		lua_State* L = luaL_newstate();

		lua_pushnumber(L, (int64_t)BaseAddress);
		lua_setglobal(L, "BaseAddress");

		luaL_openlibs(L);

		lua_register(L, "ReadByte", LUA_Read<uint8_t>);
		lua_register(L, "ReadShort", LUA_Read<uint16_t>);
		lua_register(L, "ReadInt", LUA_Read<uint32_t>);
		lua_register(L, "ReadLong", LUA_Read<uint64_t>);
		lua_register(L, "ReadFloat", LUA_Read<float>);

		lua_register(L, "ReadByteA", LUA_ReadA<uint8_t>);
		lua_register(L, "ReadShortA", LUA_ReadA<uint16_t>);
		lua_register(L, "ReadIntA", LUA_ReadA<uint32_t>);
		lua_register(L, "ReadLongA", LUA_ReadA<uint64_t>);
		lua_register(L, "ReadFloatA", LUA_ReadA<float>);

		lua_register(L, "WriteByte", LUA_Write<uint8_t>);
		lua_register(L, "WriteShort", LUA_Write<uint16_t>);
		lua_register(L, "WriteInt", LUA_Write<uint32_t>);
		lua_register(L, "WriteLong", LUA_Write<uint64_t>);
		lua_register(L, "WriteFloat", LUA_Write<float>);

		lua_register(L, "WriteByteA", LUA_WriteA<uint8_t>);
		lua_register(L, "WriteShortA", LUA_WriteA<uint16_t>);
		lua_register(L, "WriteIntA", LUA_WriteA<uint32_t>);
		lua_register(L, "WriteLongA", LUA_WriteA<uint64_t>);
		lua_register(L, "WriteFloatA", LUA_WriteA<float>);

		lua_register(L, "WriteString", LUA_WriteString);
		lua_register(L, "WriteStringA", LUA_WriteStringA);

		luaL_dofile(L, "Test GoA v2.lua");

		while (true)
		{
			lua_getglobal(L, "_OnFrame");
			lua_call(L, 0, 0);
			lua_pop(L, 0);

			Sleep(1);
		}
	}

	void __declspec(dllexport) GoA_Run()
	{
		BaseAddress = (char*)GetModuleHandle(NULL);
		CurrentLocationAddress = BaseAddress + CurrentLocationOffset;
		CutsceneLengthAddress = BaseAddress + CutsceneLengthOffset;
		CutsceneSkipAddress = BaseAddress + CutsceneSkipOffset;
		SaveAddress = BaseAddress + SaveOffset;

		Object00Address = BaseAddress + Object00Offset;
		System03Address = BaseAddress + System03Offset;

		CurrentWorldAddress = CurrentLocationAddress + 0x0;
		CurrentRoomAddress = CurrentLocationAddress + 0x01;
		CurrentPlaceAddress = CurrentLocationAddress + 0x00;
		CurrentDoorAddress = CurrentLocationAddress + 0x02;
		CurrentMapAddress = CurrentLocationAddress + 0x04;
		CurrentBattleAddress = CurrentLocationAddress + 0x06;
		CurrentEventAddress = CurrentLocationAddress + 0x08;
		PreviousPlaceAddress = CurrentLocationAddress + 0x30;

		PauseAddress = BaseAddress + PauseOffset;
		GameSpeedAddress = BaseAddress + GameSpeedOffset;
		Slot1Address = BaseAddress + Slot1Offset;

		while (true)
		{
			if (!BaseAddress)
				continue;

			World = Read<char>(CurrentWorldAddress);
			Room = Read<char>(CurrentRoomAddress);
			Place = Read<short>(CurrentPlaceAddress);
			Door = Read<short>(CurrentDoorAddress);
			Map = Read<short>(CurrentMapAddress);
			Battle = Read<short>(CurrentBattleAddress);
			Event = Read<short>(CurrentEventAddress);
			PrevPlace = Read<short>(PreviousPlaceAddress);
			ARD = *(int64_t*)(BaseAddress + 0x2A0Cee8);

			NewGame();
			GoA();
			LoD();
			STT();

			Sleep(1);
		}
	}
}
