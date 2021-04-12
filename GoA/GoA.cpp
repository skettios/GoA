#include <Windows.h>
#include "GoA.h"

/* OFFSETS */
const int Dusk1 = 0x29ED9A4;
const int Dusk2 = 0x29ED9E4;
const int Dusk3 = 0x29EDA24;
const int GoADonald1 = 0x29EE560;
const int GoASave1Pos1 = 0x29EE564;
const int GoASave1Pos2 = 0x29EE568;
const int GoASave1Pos3 = 0x29EE56C;
const int GoAGoofy1 = 0x29EE5A0;
const int GoAMog1Pos1 = 0x29EE5A4;
const int GoAMog1Pos2 = 0x29EE5A8;
const int GoAMog1Pos3 = 0x29EE5AC;
const int GoAMog1Pos4 = 0x29EE5B4;
const int GoAMog1RC = 0x29EE5CC;
const int GoADonald2 = 0x29EF134;
const int GoASave2Pos1 = 0x29EF138;
const int GoASave2Pos2 = 0x29EF13C;
const int GoASave2Pos3 = 0x29EF140;
const int GoAGoofy2 = 0x29EF174;
const int GoAMog2Pos1 = 0x29EF178;
const int GoAMog2Pos2 = 0x29EF17C;
const int GoAMog2Pos3 = 0x29EF180;
const int GoAMog2Pos4 = 0x29EF188;
const int GoAMog2RC = 0x29EF1A0;
const int GoADonald3 = 0x29EDB74;
const int GoASave3Pos1 = 0x29EDB78;
const int GoASave3Pos2 = 0x29EDB7C;
const int GoASave3Pos3 = 0x29EDB80;
const int GoAGoofy3 = 0x29EDBB4;
const int GoAMog3Pos1 = 0x29EDBB8;
const int GoAMog3Pos2 = 0x29EDBBC;
const int GoAMog3Pos3 = 0x29EDBC0;
const int GoAMog3Pos4 = 0x29EDBC8;
const int GoAMog3RC = 0x29EDBE0;
const int GoADonald4 = 0x29EDC34;
const int GoASave4Pos1 = 0x29EDC38;
const int GoASave4Pos2 = 0x29EDC3C;
const int GoASave4Pos3 = 0x29EDC40;
const int GoAGoofy4 = 0x29EDC74;
const int GoAMog4Pos1 = 0x29EDC78;
const int GoAMog4Pos2 = 0x29EDC7C;
const int GoAMog4Pos3 = 0x29EDC80;
const int GoAMog4Pos4 = 0x29EDC88;
const int GoAMog4RC = 0x29EDCA0;
const int GoADonald5 = 0x29EDCF4;
const int GoASave5Pos1 = 0x29EDCF8;
const int GoASave5Pos2 = 0x29EDCFC;
const int GoASave5Pos3 = 0x29EDD00;
const int GoAGoofy5 = 0x29EDD34;
const int GoAMog5Pos1 = 0x29EDD38;
const int GoAMog5Pos2 = 0x29EDD3C;
const int GoAMog5Pos3 = 0x29EDD40;
const int GoAMog5Pos4 = 0x29EDD48;
const int GoAMog5RC = 0x29EDD60;
const int GoADonald6 = 0x29EDDB4;
const int GoASave6Pos1 = 0x29EDDB8;
const int GoASave6Pos2 = 0x29EDDBC;
const int GoASave6Pos3 = 0x29EDDC0;
const int GoAGoofy6 = 0x29EDDF4;
const int GoAMog6Pos1 = 0x29EDDF8;
const int GoAMog6Pos2 = 0x29EDDFC;
const int GoAMog6Pos3 = 0x29EDE00;
const int GoAMog6Pos4 = 0x29EDE08;
const int GoAMog6RC = 0x29EDE20;
const int GoADonald7 = 0x29EDE74;
const int GoASave7Pos1 = 0x29EDE78;
const int GoASave7Pos2 = 0x29EDE7C;
const int GoASave7Pos3 = 0x29EDE80;
const int GoAGoofy7 = 0x29EDEB4;
const int GoAMog7Pos1 = 0x29EDEB8;
const int GoAMog7Pos2 = 0x29EDEBC;
const int GoAMog7Pos3 = 0x29EDEC0;
const int GoAMog7Pos4 = 0x29EDEC8;
const int GoAMog7RC = 0x29EDEE0;
const int GoADonald8 = 0x29EDF34;
const int GoASave8Pos1 = 0x29EDF38;
const int GoASave8Pos2 = 0x29EDF3C;
const int GoASave8Pos3 = 0x29EDF40;
const int GoAGoofy8 = 0x29EDF74;
const int GoAMog8Pos1 = 0x29EDF78;
const int GoAMog8Pos2 = 0x29EDF7C;
const int GoAMog8Pos3 = 0x29EDF80;
const int GoAMog8Pos4 = 0x29EDF88;
const int GoAMog8RC = 0x29EDFA0;
const int GoADonald9 = 0x29EDFF4;
const int GoASave9Pos1 = 0x29EDFF8;
const int GoASave9Pos2 = 0x29EDFFC;
const int GoASave9Pos3 = 0x29EE000;
const int GoAGoofy9 = 0x29EE034;
const int GoAMog9Pos1 = 0x29EE038;
const int GoAMog9Pos2 = 0x29EE03C;
const int GoAMog9Pos3 = 0x29EE040;
const int GoAMog9Pos4 = 0x29EE048;
const int GoAMog9RC = 0x29EE060;
const int GoADonald10 = 0x29EE0B4;
const int GoASave10Pos1 = 0x29EE0B8;
const int GoASave10Pos2 = 0x29EE0BC;
const int GoASave10Pos3 = 0x29EE0C0;
const int GoAGoofy10 = 0x29EE0F4;
const int GoAMog10Pos1 = 0x29EE0F8;
const int GoAMog10Pos2 = 0x29EE0FC;
const int GoAMog10Pos3 = 0x29EE100;
const int GoAMog10Pos4 = 0x29EE108;
const int GoAMog10RC = 0x29EE120;
const int GoADonald11 = 0x29EE174;
const int GoASave11Pos1 = 0x29EE178;
const int GoASave11Pos2 = 0x29EE17C;
const int GoASave11Pos3 = 0x29EE180;
const int GoAGoofy11 = 0x29EE1B4;
const int GoAMog11Pos1 = 0x29EE1B8;
const int GoAMog11Pos2 = 0x29EE1BC;
const int GoAMog11Pos3 = 0x29EE1C0;
const int GoAMog11Pos4 = 0x29EE1C8;
const int GoAMog11RC = 0x29EE1E0;
const int GoADonald12 = 0x29EE234;
const int GoASave12Pos1 = 0x29EE238;
const int GoASave12Pos2 = 0x29EE23C;
const int GoASave12Pos3 = 0x29EE240;
const int GoAGoofy12 = 0x29EE274;
const int GoAMog12Pos1 = 0x29EE278;
const int GoAMog12Pos2 = 0x29EE27C;
const int GoAMog12Pos3 = 0x29EE280;
const int GoAMog12Pos4 = 0x29EE288;
const int GoAMog12RC = 0x29EE2A0;
const int GoADonald13 = 0x29EE2F4;
const int GoASave13Pos1 = 0x29EE2F8;
const int GoASave13Pos2 = 0x29EE2FC;
const int GoASave13Pos3 = 0x29EE300;
const int GoAGoofy13 = 0x29EE334;
const int GoAMog13Pos1 = 0x29EE338;
const int GoAMog13Pos2 = 0x29EE33C;
const int GoAMog13Pos3 = 0x29EE340;
const int GoAMog13Pos4 = 0x29EE348;
const int GoAMog13RC = 0x29EE360;
const int GoADonald14 = 0x29EE3B4;
const int GoASave14Pos1 = 0x29EE3B8;
const int GoASave14Pos2 = 0x29EE3BC;
const int GoASave14Pos3 = 0x29EE3C0;
const int GoAGoofy14 = 0x29EE3F4;
const int GoAMog14Pos1 = 0x29EE3F8;
const int GoAMog14Pos2 = 0x29EE3FC;
const int GoAMog14Pos3 = 0x29EE400;
const int GoAMog14Pos4 = 0x29EE408;
const int GoAMog14RC = 0x29EE420;
const int GoADonald15 = 0x29EE474;
const int GoASave15Pos1 = 0x29EE478;
const int GoASave15Pos2 = 0x29EE47C;
const int GoASave15Pos3 = 0x29EE480;
const int GoAGoofy15 = 0x29EE4B4;
const int GoAMog15Pos1 = 0x29EE4B8;
const int GoAMog15Pos2 = 0x29EE4BC;
const int GoAMog15Pos3 = 0x29EE4C0;
const int GoAMog15Pos4 = 0x29EE4C8;
const int GoAMog15RC = 0x29EE4E0;
const int GoADonald16 = 0x29EE64C;
const int GoASave16Pos1 = 0x29EE650;
const int GoASave16Pos2 = 0x29EE654;
const int GoASave16Pos3 = 0x29EE658;
const int GoAGoofy16 = 0x29EE68C;
const int GoAMog16Pos1 = 0x29EE690;
const int GoAMog16Pos2 = 0x29EE694;
const int GoAMog16Pos3 = 0x29EE698;
const int GoAMog16Pos4 = 0x29EE6A0;
const int GoAMog16RC = 0x29EE6B8;
const int GoAMogMdl = 0x2A35FE0;
const int GoAMogMset = 0x2A36000;
const int Chest1Pos1 = 0x29EED58;
const int Chest1Pos2 = 0x29EED60;
const int Chest1Pos3 = 0x29EED68;
const int Chest2Pos1 = 0x29EED18;
const int Chest2Pos2 = 0x29EED20;
const int Chest2Pos3 = 0x29EED28;
const int Slot1 = 0x2A20C58;

/* Precalculated addresses */
char* BaseAddress;
char* CurrentLocationAddress;
char* CutsceneLengthAddress;
char* CutsceneSkipAddress;
char* SaveAddress;

char* CurrentWorldAddress;
char* CurrentRoomAddress;
char* CurrentPlaceAddress;
char* CurrentDoorAddress;
char* CurrentMapAddress;
char* CurrentBattleAddress;
char* CurrentEventAddress;
char* PreviousPlaceAddress;

/* Location Struct */
char World = 0;
char Room = 0;
short Place = 0;
short Door = 0;
short Map = 0;
short Battle = 0;
short Event = 0;
short PrevPlace = 0;

inline char ReadByte(char* address)
{
	return *address;
}

inline short ReadShort(char* address)
{
	return *(short*)address;
}

inline int ReadInt(char* address)
{
	return *(int*)address;
}

inline void WriteByte(char* address, char value)
{
	*(address) = value;
}

inline void WriteShort(char* address, short value)
{
	*(short*)address = value;
}

inline void WriteInt(char* address, int value)
{
	*(int*)address = value;
}

inline void WriteFloat(char* address, float value)
{
	*(float*)address = value;
}

inline void Warp(char world, char room, short door, short map, short battle, short event)
{
	WriteByte(CurrentLocationAddress + 0x00, world);
	WriteByte(CurrentLocationAddress + 0x01, room);
	WriteShort(CurrentLocationAddress + 0x02, door);
	WriteShort(CurrentLocationAddress + 0x04, map);
	WriteShort(CurrentLocationAddress + 0x06, battle);
	WriteShort(CurrentLocationAddress + 0x08, event);

	WriteByte(SaveAddress + 0x000C, world);
	WriteByte(SaveAddress + 0x000D, room);
	WriteShort(SaveAddress + 0x000E, door);
}

inline void SkipCutscene()
{
	WriteByte(BaseAddress + CutsceneSkipOffset, 0x01);
}

inline void BitNot(char* address, char byte)
{
	WriteByte(address, ReadByte(address) & ~byte);
}

inline void BitOr(char* address, char byte)
{
	WriteByte(address, ReadByte(address) | byte);
}

inline void BC(char* baseAddress);
inline void HT(char* baseAddress);
inline void Ag(char* baseAddress);
inline void OC(char* baseAddress);
inline void PL(char* baseAddress);
inline void SP(char* baseAddress);
inline void DC(char* baseAddress);

extern "C"
{
	short __declspec(dllexport) GoA_GetCurrentMap()
	{
		return ReadShort(CurrentMapAddress);
	}

	void __declspec(dllexport) GoA_SetChestItem(char *param)
	{
		int offset = *(int*)param;
		short value = *((short*)(param + sizeof(int)));
		WriteShort(BaseAddress + offset, value);
	}

	void __declspec(dllexport) GoA_SetDrive(char *value)
	{
		WriteByte(BaseAddress + Slot1 + 0x1B1, *value);
	}

	void __declspec(dllexport) GoA_Run()
	{
		BaseAddress = (char*)GetModuleHandle(NULL);
		CurrentLocationAddress = BaseAddress + CurrentLocationOffset;
		CutsceneLengthAddress = BaseAddress + CutsceneLengthOffset;
		CutsceneSkipAddress = BaseAddress + CutsceneSkipOffset;
		SaveAddress = BaseAddress + SaveOffset;

		CurrentWorldAddress = CurrentLocationAddress + 0x0;
		CurrentRoomAddress = CurrentLocationAddress + 0x01;
		CurrentPlaceAddress = CurrentLocationAddress + 0x00;
		CurrentDoorAddress = CurrentLocationAddress + 0x02;
		CurrentMapAddress = CurrentLocationAddress + 0x04;
		CurrentBattleAddress = CurrentLocationAddress + 0x06;
		CurrentEventAddress = CurrentLocationAddress + 0x08;
		PreviousPlaceAddress = CurrentLocationAddress + 0x30;

		while (true)
		{
			if (!BaseAddress)
				continue;

			World = ReadByte(CurrentWorldAddress);
			Room = ReadByte(CurrentRoomAddress);
			Place = ReadShort(CurrentPlaceAddress);
			Door = ReadShort(CurrentDoorAddress);
			Map = ReadShort(CurrentMapAddress);
			Battle = ReadShort(CurrentBattleAddress);
			Event = ReadShort(CurrentEventAddress);
			PrevPlace = ReadShort(PreviousPlaceAddress);

			if (Place == 0x0102)
			{
				if (Map == 0x34 && Battle == 0x34 && Event == 0x34) // Opening CS
					SkipCutscene();

				if (Map == 0x38 && Battle == 0x38 && Event == 0x38) // Roxas Room Day 1
				{
					Warp(0x02, 0x20, 0x32, 0x01, 0x01, 0x01);
					BitNot(BaseAddress + SaveOffset + 0x1CD2, (char)0xC0);
					BitOr(BaseAddress + SaveOffset + 0x1CEA, (char)0x03);
				}
			}

			if (Place == 0x2002)
			{
				if (Map == 0x01 && Battle == 0x01 && Event == 0x01) // In station of serenity weapons
				{
					WriteShort(BaseAddress + Dusk1, 0x0745);
					WriteShort(BaseAddress + Dusk2, 0x0433);
					WriteShort(BaseAddress + Dusk3, 0x0434);

					if (ReadInt(BaseAddress + CutsceneLengthOffset) == 0x246) // Dusks attack
						SkipCutscene();

					WriteByte(BaseAddress + SaveOffset + 0x35AE, 1); //Have 1 Battlefields of War
					WriteByte(BaseAddress + SaveOffset + 0x35AF, 1); //Have 1 Sword of the Ancestors
					WriteByte(BaseAddress + SaveOffset + 0x35B3, 1); //Have 1 Beast's Claw
					WriteByte(BaseAddress + SaveOffset + 0x35B4, 1); //Have 1 Bone Fist
					WriteByte(BaseAddress + SaveOffset + 0x35B5, 1); //Have 1 Proud Fang
					WriteByte(BaseAddress + SaveOffset + 0x35B6, 1); //Have 1 Skill and Crossbones
					WriteByte(BaseAddress + SaveOffset + 0x35C0, 1); //Have 1 Scimitar
					WriteByte(BaseAddress + SaveOffset + 0x35C1, 1); //Have 1 Way to the Dawn
					WriteByte(BaseAddress + SaveOffset + 0x35C2, 1); //Have 1 Identity Disk
					WriteByte(BaseAddress + SaveOffset + 0x363F, 1); //Have 1 Tournament Poster
					WriteByte(BaseAddress + SaveOffset + 0x3640, 1); //Have 1 Poster
					WriteByte(BaseAddress + SaveOffset + 0x3641, 1); //Have 1 Letter
					WriteByte(BaseAddress + Slot1 + 0x1B0, 100); //Starting Drive %
					WriteByte(BaseAddress + Slot1 + 0x1B1, 9);   //Starting Drive Current
					WriteByte(BaseAddress + Slot1 + 0x1B2, 9);   //Starting Drive Max
				}

				if (Map == 0x9A && Battle == 0x9A && Event == 0x9A && ReadByte(BaseAddress + SaveOffset + 0x1CD8) == 0x00)
				{
					Warp(0x04, 0x1A, 0x00, 0x01, 0x00, 0x01);
					// Place Scripts
					WriteShort(BaseAddress + SaveOffset + 0x06AC, 0x01); //Garden of Assemblage MAP(Before Computer)
					WriteShort(BaseAddress + SaveOffset + 0x06B0, 0x01); //Garden of Assemblage EVT
					WriteShort(BaseAddress + SaveOffset + 0x1B5E, 0x01); //Proof of Existence MAP(Lock Progress)
					BitOr(BaseAddress + SaveOffset + 0x239E, (char)0x07);  //Pause Menu(1 = Items, 2 = Party, 4 = Customize)
					BitNot(BaseAddress + SaveOffset + 0x239E, (char)0x80); //Show Struggle Bats Outside STT
					WriteShort(BaseAddress + SaveOffset + 0x32F4, 0x051); //Valor Form equips FAKE
					WriteShort(BaseAddress + SaveOffset + 0x339C, 0x02C); //Master Form equips Detection Saber
					WriteShort(BaseAddress + SaveOffset + 0x33D4, 0x02D); //Final Form equips Edge of Ultima
					WriteShort(BaseAddress + SaveOffset + 0x4270, 0x01FF); //Pause Menu Tutorial Prompts Seen Flags
					WriteShort(BaseAddress + SaveOffset + 0x4274, 0x01FF); //Status Form & Summon Seen Flags
					// Unlock Shop Weapons
					BitOr(BaseAddress + SaveOffset + 0x49F0, (char) 0x03); //Shop Tutorial Prompt Flags(1 = Big Shops, 2 = Small Shops)
					BitOr(BaseAddress + SaveOffset + 0x2396, (char) 0x10); //Comet Staff & Falling Star(Olympus Coliseum)
					BitOr(BaseAddress + SaveOffset + 0x2396, (char) 0x40); //Victory Bell & Chain Gear(Port Royal)
					BitOr(BaseAddress + SaveOffset + 0x2397, (char) 0x80); //Lord's Broom & Dreamcloud (Pride Lands)
					BitOr(BaseAddress + SaveOffset + 0x2398, (char) 0x04); //Wisdom Wand & Knight Defender(The World that Never Was)
					// Unlock Data Portals
					BitOr(BaseAddress + SaveOffset + 0x1D35, (char) 0x01); //Xaldin
					BitOr(BaseAddress + SaveOffset + 0x1D23, (char) 0x08); //Vexen
					BitOr(BaseAddress + SaveOffset + 0x1D23, (char) 0x10); //Lexaeus
					BitOr(BaseAddress + SaveOffset + 0x1D23, (char) 0x40); //Zexion
					BitOr(BaseAddress + SaveOffset + 0x1CE9, (char) 0x04); //Axel
					BitOr(BaseAddress + SaveOffset + 0x1D15, (char) 0x08); //Demyx
					BitOr(BaseAddress + SaveOffset + 0x1D23, (char) 0x80); //Marluxia
					BitOr(BaseAddress + SaveOffset + 0x1D23, (char) 0x20); //Larxene
					BitOr(BaseAddress + SaveOffset + 0x1ED9, (char) 0x01); //TWtNW Members
					// Story Flags
					BitOr(BaseAddress + SaveOffset + 0x1CE2, (char) 0x10); //TT_SCENARIO_7_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1CE9, (char) 0x20); //TT_908_END_L(Scene Before TT2)
					BitOr(BaseAddress + SaveOffset + 0x1CE5, (char) 0x80); //TT_SCENARIO_9_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1CE7, (char) 0x08); //TT_SCENARIO_10_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1D1B, (char) 0x10); //HB_SCENARIO_1_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1D1B, (char) 0x80); //HB_SCENARIO_2_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1D1C, (char) 0x01); //HB_SCENARIO_2_START
					BitOr(BaseAddress + SaveOffset + 0x1D1E, (char) 0x02); //HB_SCENARIO_3_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1D1E, (char) 0x10); //HB_SCENARIO_4_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1D1C, (char) 0x04); //HB_SCENARIO_5_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1D31, (char) 0x10); //BB_SCENARIO_1_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1D32, (char) 0x01); //BB_SCENARIO_2_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1D53, (char) 0x80); //HE_SCENARIO_1_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1D55, (char) 0x02); //HE_W_COL_ON(Underdrome Unlocked Scene)
					BitOr(BaseAddress + SaveOffset + 0x1D54, (char) 0x08); //HE_SCENARIO_2_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1D73, (char) 0x04); //AL_SCENARIO_1_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1D73, (char) 0x20); //AL_SCENARIO_2_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1D91, (char) 0x04); //MU_SCENARIO_1_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1D91, (char) 0x20); //MU_SCENARIO_2_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1DB7, (char) 0x04); //PO_SCENARIO_0_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1DD5, (char) 0x08); //LK_SCENARIO_1_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1DD5, (char) 0x40); //LK_SCENARIO_2_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1DF6, (char) 0x01); //LM_SCENARIO_1_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1E11, (char) 0x08); //DC_SCENARIO_1_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1E57, (char) 0x01); //NM_SCENARIO_1_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1E56, (char) 0x20); //NM_SCENARIO_2_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1E99, (char) 0x08); //CA_SCENARIO_1_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1E99, (char) 0x40); //CA_SCENARIO_2_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1EB5, (char) 0x40); //TR_SCENARIO_1_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1EB6, (char) 0x02); //TR_SCENARIO_2_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1ED5, (char) 0x80); //EH_SCENARIO_1_OPEN
					BitOr(BaseAddress + SaveOffset + 0x1ED8, (char) 0x04); //EH_FINAL_CHANCE_START
				}
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
					if (ReadByte(BaseAddress + SaveOffset + 0x1CFF) == 8) //Twilight Town
						Warp(0x04, 0x1A, 0x1C, 0x00, 0x00, 0x02);
					else if (ReadByte(BaseAddress + SaveOffset + 0x1CFF) == 13) //Simulated Twilight Town
						Warp(0x04, 0x1A, 0x21, 0x00, 0x00, 0x02);

					WriteByte(BaseAddress + SaveOffset + 0x1CFF, 0);
				}
				else if (Door == 0x02) //Hollow Bastion
				{
					Warp(0x04, 0x1A, 0x1D, 0x00, 0x00, 0x02);
					if (ReadByte(BaseAddress + SaveOffset + 0x1D2F) == 1) //During Ravine Heartless
						WriteInt(BaseAddress + SaveOffset + 0x3544, 0x12020100); //Add Goofy
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
					if (ReadByte(BaseAddress + SaveOffset + 0x1CFF) == 8)
						Warp(0x04, 0x1A, 0x1C, 0x00, 0x00, 0x02); // tt
					else if (ReadByte(BaseAddress + SaveOffset + 0x1CFF) == 13)
						Warp(0x04, 0x1A, 0x21, 0x00, 0x00, 0x02); // stt

					WriteByte(BaseAddress + SaveOffset + 0x1CFF, 0);
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

			if (Place == 0x1A04)
			{
				if (ReadShort(BaseAddress + SaveOffset + 0x06AC) == 0x02)
					WriteShort(BaseAddress + SaveOffset + 0x06AC, 0x00);

				WriteFloat(BaseAddress + Chest2Pos1, -160);
				WriteFloat(BaseAddress + Chest2Pos2, 360);
				WriteFloat(BaseAddress + Chest2Pos3, 3.14f / 2);

				WriteFloat(BaseAddress + Chest1Pos1, -160);
				WriteFloat(BaseAddress + Chest1Pos2, -360);
				WriteFloat(BaseAddress + Chest1Pos3, 3.14f / 2);

				WriteShort(BaseAddress + GoADonald1, 0x23A); //Party 1->Save Point(From Entrance / 100 Acre Wood)
				WriteFloat(BaseAddress + GoASave1Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoASave1Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoASave1Pos3, -900); //Position Z
				WriteShort(BaseAddress + GoAGoofy1, 0x4A1); //Party 2->Moogle Shop(From Entrance / 100 Acre Wood)
				WriteFloat(BaseAddress + GoAMog1Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoAMog1Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoAMog1Pos3, 900); //Position Z
				WriteFloat(BaseAddress + GoAMog1Pos4, 0); //Rotation Y
				WriteShort(BaseAddress + GoAMog1RC, 0x0D1); //Shop RC
				WriteShort(BaseAddress + GoADonald2, 0x23A); //Party 1->Save Point(From Computer)
				WriteFloat(BaseAddress + GoASave2Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoASave2Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoASave2Pos3, -900); //Position Z
				WriteShort(BaseAddress + GoAGoofy2, 0x4A1); //Party 2->Moogle Shop(From Computer)
				WriteFloat(BaseAddress + GoAMog2Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoAMog2Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoAMog2Pos3, 900); //Position Z
				WriteFloat(BaseAddress + GoAMog2Pos4, 0); //Rotation Y
				WriteShort(BaseAddress + GoAMog2RC, 0x0D1); //Shop RC
				WriteShort(BaseAddress + GoADonald3, 0x23A); //Party 1->Save Point(From The World That Never Was)
				WriteFloat(BaseAddress + GoASave3Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoASave3Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoASave3Pos3, -900); //Position Z
				WriteShort(BaseAddress + GoAGoofy3, 0x4A1); //Party 2->Moogle Shop(From The World That Never Was)
				WriteFloat(BaseAddress + GoAMog3Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoAMog3Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoAMog3Pos3, 900); //Position Z
				WriteFloat(BaseAddress + GoAMog3Pos4, 0); //Rotation Y
				WriteShort(BaseAddress + GoAMog3RC, 0x0D1); //Shop RC
				WriteShort(BaseAddress + GoADonald4, 0x23A); //Party 1->Save Point(From The Land of Dragons)
				WriteFloat(BaseAddress + GoASave4Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoASave4Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoASave4Pos3, -900); //Position Z
				WriteShort(BaseAddress + GoAGoofy4, 0x4A1); //Party 2->Moogle Shop(From The Land of Dragons)
				WriteFloat(BaseAddress + GoAMog4Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoAMog4Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoAMog4Pos3, 900); //Position Z
				WriteFloat(BaseAddress + GoAMog4Pos4, 0); //Rotation Y
				WriteShort(BaseAddress + GoAMog4RC, 0x0D1); //Shop RC
				WriteShort(BaseAddress + GoADonald5, 0x23A); //Party 1->Save Point(From Beast's Castle)
				WriteFloat(BaseAddress + GoASave5Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoASave5Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoASave5Pos3, -900); //Position Z
				WriteShort(BaseAddress + GoAGoofy5, 0x4A1); //Party 2->Moogle Shop(From Beast's Castle)
				WriteFloat(BaseAddress + GoAMog5Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoAMog5Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoAMog5Pos3, 900); //Position Z
				WriteFloat(BaseAddress + GoAMog5Pos4, 0); //Rotation Y
				WriteShort(BaseAddress + GoAMog5RC, 0x0D1); //Shop RC
				WriteShort(BaseAddress + GoADonald6, 0x23A); //Party 1->Save Point(From Halloween Town)
				WriteFloat(BaseAddress + GoASave6Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoASave6Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoASave6Pos3, -900); //Position Z
				WriteShort(BaseAddress + GoAGoofy6, 0x4A1); //Party 2->Moogle Shop(From Halloween Town)
				WriteFloat(BaseAddress + GoAMog6Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoAMog6Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoAMog6Pos3, 900); //Position Z
				WriteFloat(BaseAddress + GoAMog6Pos4, 0); //Rotation Y
				WriteShort(BaseAddress + GoAMog6RC, 0x0D1); //Shop RC
				WriteShort(BaseAddress + GoADonald7, 0x23A); //Party 1->Save Point(From Agrabah)
				WriteFloat(BaseAddress + GoASave7Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoASave7Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoASave7Pos3, -900); //Position Z
				WriteShort(BaseAddress + GoAGoofy7, 0x4A1); //Party 2->Moogle Shop(From Agrabah)
				WriteFloat(BaseAddress + GoAMog7Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoAMog7Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoAMog7Pos3, 900); //Position Z
				WriteFloat(BaseAddress + GoAMog7Pos4, 0); //Rotation Y
				WriteShort(BaseAddress + GoAMog7RC, 0x0D1); //Shop RC
				WriteShort(BaseAddress + GoADonald8, 0x23A); //Party 1->Save Point(From Olympus Coliseum)
				WriteFloat(BaseAddress + GoASave8Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoASave8Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoASave8Pos3, -900); //Position Z
				WriteShort(BaseAddress + GoAGoofy8, 0x4A1); //Party 2->Moogle Shop(From Olympus Coliseum)
				WriteFloat(BaseAddress + GoAMog8Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoAMog8Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoAMog8Pos3, 900); //Position Z
				WriteFloat(BaseAddress + GoAMog8Pos4, 0); //Rotation Y
				WriteShort(BaseAddress + GoAMog8RC, 0x0D1); //Shop RC
				WriteShort(BaseAddress + GoADonald9, 0x23A); //Party 1->Save Point(From Pride Lands)
				WriteFloat(BaseAddress + GoASave9Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoASave9Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoASave9Pos3, -900); //Position Z
				WriteShort(BaseAddress + GoAGoofy9, 0x4A1); //Party 2->Moogle Shop(From Pride Lands)
				WriteFloat(BaseAddress + GoAMog9Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoAMog9Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoAMog9Pos3, 900); //Position Z
				WriteFloat(BaseAddress + GoAMog9Pos4, 0); //Rotation Y
				WriteShort(BaseAddress + GoAMog9RC, 0x0D1); //Shop RC
				WriteShort(BaseAddress + GoADonald10, 0x23A); //Party 1->Save Point(From Twilight Town)
				WriteFloat(BaseAddress + GoASave10Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoASave10Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoASave10Pos3, -900); //Position Z
				WriteShort(BaseAddress + GoAGoofy10, 0x4A1); //Party 2->Moogle Shop(From Twilight Town)
				WriteFloat(BaseAddress + GoAMog10Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoAMog10Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoAMog10Pos3, 900); //Position Z
				WriteFloat(BaseAddress + GoAMog10Pos4, 0); //Rotation Y
				WriteShort(BaseAddress + GoAMog10RC, 0x0D1); //Shop RC
				WriteShort(BaseAddress + GoADonald11, 0x23A); //Party 1->Save Point(From Hollow Bastion / Radiant Garden)
				WriteFloat(BaseAddress + GoASave11Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoASave11Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoASave11Pos3, -900); //Position Z
				WriteShort(BaseAddress + GoAGoofy11, 0x4A1); //Party 2->Moogle Shop(From Hollow Bastion / Radiant Garden)
				WriteFloat(BaseAddress + GoAMog11Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoAMog11Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoAMog11Pos3, 900); //Position Z
				WriteFloat(BaseAddress + GoAMog11Pos4, 0); //Rotation Y
				WriteShort(BaseAddress + GoAMog11RC, 0x0D1); //Shop RC
				WriteShort(BaseAddress + GoADonald12, 0x23A); //Party 1->Save Point(From Port Royal)
				WriteFloat(BaseAddress + GoASave12Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoASave12Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoASave12Pos3, -900); //Position Z
				WriteShort(BaseAddress + GoAGoofy12, 0x4A1); //Party 2->Moogle Shop(From Port Royal)
				WriteFloat(BaseAddress + GoAMog12Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoAMog12Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoAMog12Pos3, 900); //Position Z
				WriteFloat(BaseAddress + GoAMog12Pos4, 0); //Rotation Y
				WriteShort(BaseAddress + GoAMog12RC, 0x0D1); //Shop RC
				WriteShort(BaseAddress + GoADonald13, 0x23A); //Party 1->Save Point(From Disney Castle)
				WriteFloat(BaseAddress + GoASave13Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoASave13Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoASave13Pos3, -900); //Position Z
				WriteShort(BaseAddress + GoAGoofy13, 0x4A1); //Party 2->Moogle Shop(From Disney Castle)
				WriteFloat(BaseAddress + GoAMog13Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoAMog13Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoAMog13Pos3, 900); //Position Z
				WriteFloat(BaseAddress + GoAMog13Pos4, 0); //Rotation Y
				WriteShort(BaseAddress + GoAMog13RC, 0x0D1); //Shop RC
				WriteShort(BaseAddress + GoADonald14, 0x23A); //Party 1->Save Point(From Space Paranoids)
				WriteFloat(BaseAddress + GoASave14Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoASave14Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoASave14Pos3, -900); //Position Z
				WriteShort(BaseAddress + GoAGoofy14, 0x4A1); //Party 2->Moogle Shop(From Space Paranoids)
				WriteFloat(BaseAddress + GoAMog14Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoAMog14Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoAMog14Pos3, 900); //Position Z
				WriteFloat(BaseAddress + GoAMog14Pos4, 0); //Rotation Y
				WriteShort(BaseAddress + GoAMog14RC, 0x0D1); //Shop RC
				WriteShort(BaseAddress + GoADonald15, 0x23A); //Party 1->Save Point(From Simulated Twilight Town)
				WriteFloat(BaseAddress + GoASave15Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoASave15Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoASave15Pos3, -900); //Position Z
				WriteShort(BaseAddress + GoAGoofy15, 0x4A1); //Party 2->Moogle Shop(From Simulated Twilight Town)
				WriteFloat(BaseAddress + GoAMog15Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoAMog15Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoAMog15Pos3, 900); //Position Z
				WriteFloat(BaseAddress + GoAMog15Pos4, 0); //Rotation Y
				WriteShort(BaseAddress + GoAMog15RC, 0x0D1); //Shop RC
				WriteShort(BaseAddress + GoADonald16, 0x23A); //Party 1->Save Point(From Atlantica)
				WriteFloat(BaseAddress + GoASave16Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoASave16Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoASave16Pos3, -900); //Position Z
				WriteShort(BaseAddress + GoAGoofy16, 0x4A1); //Party 2->Moogle Shop(From Atlantica)
				WriteFloat(BaseAddress + GoAMog16Pos1, 0); //Position X
				WriteFloat(BaseAddress + GoAMog16Pos2, 460); //Position Y
				WriteFloat(BaseAddress + GoAMog16Pos3, 900); //Position Z
				WriteFloat(BaseAddress + GoAMog16Pos4, 0); //Rotation Y
				WriteShort(BaseAddress + GoAMog16RC, 0x0D1); //Shop RC
			}

			if (Place == 0x0A12)
			{
				if (Map == 0x6B && Battle == 0x6B && Event == 0x6B) // LoD
				{
					if ((ReadByte(BaseAddress + SaveOffset + 0x1D90) & (~0x01)) == 0x00)
						Warp(0x08, 0x00, 0x00, 0x01, 0x00, 0x01);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C1A) == 0x01) // Before Encampment Heartless
						Warp(0x08, 0x00, 0x63, 0x00, 0x00, 0x13);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C1A) == 0x04) //Before Missions
						Warp(0x08, 0x00, 0x63, 0x00, 0x00, 0x16);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C1A) == 0x10)//During Missions 1
						Warp(0x08, 0x00, 0x63, 0x00, 0x00, 0x16);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C1A) == 0x11) //During Missions 2
						Warp(0x08, 0x00, 0x63, 0x00, 0x00, 0x16);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C1A) == 0x12) //During Missions 3
						Warp(0x08, 0x00, 0x63, 0x00, 0x00, 0x16);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C26) == 0x01) //Before Mountain Climb
						Warp(0x08, 0x00, 0x63, 0x00, 0x00, 0x10);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C32) == 0x01) //Before Village Cave Heartless
						Warp(0x08, 0x04, 0x63, 0x00, 0x00, 0x16);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C3E) == 0x01) //Before Summit Rapid Heartless
						Warp(0x08, 0x0C, 0x63, 0x01, 0x00, 0x16);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C20) == 0x03) //After Summit Heartless
						Warp(0x08, 0x00, 0x63, 0x00, 0x00, 0x14);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C44) == 0x01) //Before Imperial Square Heartless I
						Warp(0x08, 0x00, 0x63, 0x00, 0x00, 0x14);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C4A) == 0x01) //Before Shan Yu
						Warp(0x08, 0x00, 0x63, 0x00, 0x00, 0x14);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C14) == 0x11) //Post 1st Visit
						Warp(0x08, 0x0C, 0x63, 0x00, 0x00, 0x14);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C14) == 0x11 && ReadByte(BaseAddress + SaveOffset + 0x35AF) > 0) //2nd Visit
					{
						Warp(0x08, 0x0C, 0x00, 0x00, 0x00, 0x0A);
						WriteShort(BaseAddress + SaveOffset + 0x0C14, 0x12); //Bamboo Grove EVT
						WriteShort(BaseAddress + SaveOffset + 0x0C18, 0x0A); //Encampment BTL
						WriteShort(BaseAddress + SaveOffset + 0x0C1E, 0x0A); //Checkpoint BTL
						WriteShort(BaseAddress + SaveOffset + 0x0C24, 0x0A); //Mountain Trail BTL
						WriteShort(BaseAddress + SaveOffset + 0x0C30, 0x0A); //Village Cave BTL
						WriteShort(BaseAddress + SaveOffset + 0x0C42, 0x0A); //Imperial Square BTL
						WriteShort(BaseAddress + SaveOffset + 0x0C48, 0x0A); //Palace Gate BTL
					}
					if (ReadShort(BaseAddress + SaveOffset + 0x0C5C) == 0x15) //Before Riku
						Warp(0x08, 0x0C, 0x63, 0x00, 0x00, 0x15);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C44) == 0x0A) //Before Imperial Square Heartless II
						Warp(0x08, 0x00, 0x63, 0x00, 0x00, 0x15);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C4A) == 0x0A) //After Imperial Square Heartless II
						Warp(0x08, 0x00, 0x63, 0x00, 0x00, 0x15);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C50) == 0x0B) //Before Antechamber Nobodies
						Warp(0x08, 0x00, 0x63, 0x00, 0x00, 0x15);
					if (ReadShort(BaseAddress + SaveOffset + 0x0C50) == 0x0D) //Before Storm Rider
						Warp(0x08, 0x0B, 0x63, 0x00, 0x00, 0x16);
					if (ReadByte(BaseAddress + SaveOffset + 0x1D9E) == 1) //Post 2nd Visit 1
						Warp(0x08, 0x00, 0x63, 0x00, 0x00, 0x00);
					else if (ReadByte(BaseAddress + SaveOffset + 0x1D9E) == 2) //Post 2nd Visit 2
						Warp(0x08, 0x04, 0x63, 0x00, 0x00, 0x14);
					else if (ReadByte(BaseAddress + SaveOffset + 0x1D9E) == 3) //Post 2nd Visit 3
						Warp(0x08, 0x0B, 0x63, 0x00, 0x00, 0x15);
				}
			}

			if (Place == 0x0E12)
			{
				if (Map == 0x6F && Battle == 0x6F && Event == 0x6F)
				{
					if ((ReadByte(BaseAddress + SaveOffset + 0x1E90) & (~0x05)) == 0x00)
						Warp(0x10, 0x00, 0x00, 0x00, 0x00, 0x01);
					if (ReadShort(BaseAddress + SaveOffset + 0x181A) == 0x01)
						Warp(0x10, 0x00, 0x63, 0x00, 0x00, 0x00);
					if (ReadShort(BaseAddress + SaveOffset + 0x1820) == 0x01)
						Warp(0x10, 0x00, 0x63, 0x00, 0x00, 0x00);
				}
			}

			BC(BaseAddress);
			HT(BaseAddress);
			Ag(BaseAddress);
			OC(BaseAddress);
			PL(BaseAddress);
			DC(BaseAddress);
			SP(BaseAddress);

			Sleep(1);
		}
	}
}

inline void BC(char* baseAddress)
{
	if (Place == 0x0F05 && Map == 0x62 && Battle == 0x62 && Event == 0x62)
	{
		if ((ReadByte(baseAddress + SaveOffset + 0x1D30) & (~0x01)) == 0x00)
			Warp(0x05, 0x00, 0x00, 0x01, 0x00, 0x01);
		if (ReadShort(baseAddress + SaveOffset + 0x0794) == 0x02)
			Warp(0x05, 0x01, 0x63, 0x00, 0x00, 0x14);
	}
}

inline void HT(char* baseAddress)
{
	if (Place == 0x2004 && Map == 0x82 && Battle == 0x82 && Event == 0x82)
	{
		if ((ReadByte(baseAddress + SaveOffset + 0x1E50) & (~0x03)) == 0x00)
			Warp(0x0E, 0x04, 0x00, 0x00, 0x00, 0x01);
		if (ReadShort(baseAddress + SaveOffset + 0x1514) == 0x02)
			Warp(0x0E, 0x01, 0x63, 0x00, 0x00, 0x16);
	}
}

inline void Ag(char* baseAddress)
{
	if (Place == 0x2104 && Map == 0x84 && Battle == 0x84 && Event == 0x84)
	{
		if ((ReadByte(baseAddress + SaveOffset + 0x1D70) & (~0x01)) == 0x00)
			Warp(0x07, 0x00, 0x00, 0x00, 0x00, 0x01);
		if (ReadShort(baseAddress + SaveOffset + 0x0AA6) == 0x01)
			Warp(0x07, 0x02, 0x63, 0x02, 0x00, 0x14);
	}
}

inline void OC(char* baseAddress)
{
	if (Place == 0x2204 && Map == 0x86 && Battle == 0x86 && Event == 0x86)
	{
		if ((ReadByte(baseAddress + SaveOffset + 0x1D50) & (~0x81)) == 0x00)
			Warp(0x06, 0x00, 0x00, 0x00, 0x00, 0x1);
		if (ReadShort(baseAddress + SaveOffset + 0x0926) == 0x02)
			Warp(0x06, 0x03, 0x63, 0x01, 0x16, 0x02);
	}
}

inline void PL(char* baseAddress)
{
	if (Place == 0x0F12 && Map == 0x6D && Battle == 0x6D && Event == 0x6D)
	{
		if ((ReadByte(baseAddress + SaveOffset + 0x1DD0) & (~0x01)) == 0x00)
			Warp(0x0A, 0x10, 0x00, 0x00, 0x00, 0x01);
		if (ReadShort(baseAddress + SaveOffset + 0x0F38) == 0x13)
			Warp(0x0A, 0x06, 0x63, 0x01, 0x00, 0x13);
	}
}

inline void DC(char* baseAddress)
{
	if (Place == 0x2604)
	{
		if (Map == 0x88 && Battle == 0x88 && Event == 0x88)
		{
			if ((ReadByte(baseAddress + SaveOffset + 0x1E10) & (~0x02)) == 0x00)
				Warp(0x0C, 0x06, 0x00, 0x00, 0x00, 0x01);
			if (ReadShort(baseAddress + SaveOffset + 0x1226) == 0x01)
				Warp(0x0C, 0x06, 0x63, 0x00, 0x00, 0x16);
		}
	}
}

inline void SP(char* baseAddress)
{
	if (Place == 0x2104 && Map == 0x8A && Battle == 0x8A && Event == 0x8A)
	{
		if ((ReadByte(baseAddress + SaveOffset + 0x1EB0) & (~0x01)) == 0x00)
			Warp(0x11, 0x01, 0x00, 0x02, 0x00, 0x01);
		if (ReadShort(baseAddress + SaveOffset + 0x19A6) == 0x01)
			Warp(0x11, 0x00, 0x37, 0x03, 0x00, 0x16);
	}
}
