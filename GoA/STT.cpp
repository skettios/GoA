#include "Globals.h"
#include "Helpers.h"

void STT()
{
	if (Place == 0x1512)
	{
		if (IsEvent(0x71, 0x71, 0x71))
		{
			Write<int>(SaveAddress + 0x353C, 0x12121200);
			Write<char>(SaveAddress + 0x1CFF, 13);
			for (int i = 0; i < 144; i++)
				Write<char>(SaveAddress + 0x0310 + i, Read<char>(SaveAddress + 0x0230 + i));

			Write<short>(SaveAddress + 0x03E8, Read<short>(SaveAddress + 0x0388));
			Write<short>(SaveAddress + 0x03EA, Read<short>(SaveAddress + 0x038A));
			Write<short>(SaveAddress + 0x03EC, Read<short>(SaveAddress + 0x038C));

			if (Read<char>(SaveAddress + 0x1CD2) == 0x30) // 1st visit
			{
				Warp(0x02, 0x01, 0x00, 0x00, 0x00, 0x38);
				Write<char>(SaveAddress + 0x3FF5, 1);
				RemoveTTBarriers();
				Write<short>(SaveAddress + 0x0366, 0x00);
			}
			if (Read<short>(SaveAddress + 0x0338) == 0x01) // before munny
			{
				Warp(0x02, 0x02, 0x63, 0x01, 0x00, 0x00);
				Write<char>(SaveAddress + 0x3FF5, 2);
				RemoveTTBarriers();
				Write<short>(SaveAddress + 0x20EC, 0xC449);
			}
			if (Read<short>(SaveAddress + 0x0338) == 0x0C) // munny
			{
				Warp(0x02, 0x02, 0x63, 0x01, 0x00, 0x00);
				Write<char>(SaveAddress + 0x3FF5, 2);
				RemoveTTBarriers();
				Write<short>(SaveAddress + 0x2080, 0xC44B);
				Write<short>(SaveAddress + 0x20E8, 0x9F4A);
				Write<short>(SaveAddress + 0x20EC, 0x9F49);
			}
			if (Read<short>(SaveAddress + 0x0338) == 0x02) // before sandlot nobodies
			{
				Warp(0x02, 0x02, 0x63, 0x01, 0x00, 0x00);
				Write<char>(SaveAddress + 0x3FF5, 3);
				RemoveTTBarriers();
				Write<short>(SaveAddress + 0x20EC, 0xC44C);
			}
			if (Read<short>(SaveAddress + 0x03E0) == 0x01) // before twilight thorn
			{
				Warp(0x02, 0x20, 0x63, 0x00, 0x00, 0x02);
				Write<char>(SaveAddress + 0x3FF5, 3);
				RemoveTTBarriers();
			}
			if (Read<short>(SaveAddress + 0x0332) == 0x02) // start day 4
			{
				Warp(0x02, 0x05, 0x63, 0x00, 0x00, 0x02);
				Write<char>(SaveAddress + 0x3FF5, 4);
				RemoveTTBarriers();
				Write<short>(SaveAddress + 0x20E8, 0xC542);
				Write<short>(SaveAddress + 0x2114, 0xC540);
			}
			if (Read<short>(SaveAddress + 0x0332) == 0x03) // before hayner
			{
				Warp(0x02, 0x05, 0x63, 0x00, 0x00, 0x03);
				Write<char>(SaveAddress + 0x3FF5, 4);
				RemoveTTBarriers();
				Write<short>(SaveAddress + 0x20E8, 0xC542);
				Write<short>(SaveAddress + 0x2114, 0xC540);
			}
			if (Read<short>(SaveAddress + 0x0322) == 0x04) // before vivi
			{
				Warp(0x02, 0x05, 0x63, 0x00, 0x00, 0x04);
				Write<char>(SaveAddress + 0x3FF5, 4);
				RemoveTTBarriers();
				Write<short>(SaveAddress + 0x20E8, 0xC542);
				Write<short>(SaveAddress + 0x2114, 0xC540);
			}
			if (Read<short>(SaveAddress + 0x0322) == 0x05) // before setzer
			{
				Warp(0x02, 0x05, 0x63, 0x00, 0x00, 0x05);
				Write<char>(SaveAddress + 0x3FF5, 4);
				RemoveTTBarriers();
				Write<short>(SaveAddress + 0x20E8, 0xC542);
				Write<short>(SaveAddress + 0x2114, 0xC540);
			}
			if (Read<short>(SaveAddress + 0x0344) == 0x0F) // start day 5
			{
				Warp(0x02, 0x02, 0x63, 0x01, 0x00, 0x0C);
				Write<char>(SaveAddress + 0x3FF5, 5);
				RemoveTTBarriers();
			}
			if (Read<short>(SaveAddress + 0x034C) == 0x01) // seven wonders
			{
				Warp(0x02, 0x0B, 0x63, 0x01, 0x00, 0x0C);
				Write<char>(SaveAddress + 0x3FF5, 5);
				RemoveTTBarriers();
			}
			if (Read<short>(SaveAddress + 0x03EC) == 0x0C) // before vivi wonder
			{
				Warp(0x02, 0x0B, 0x63, 0x01, 0x00, 0x0C);
				Write<char>(SaveAddress + 0x3FF5, 5);
				RemoveTTBarriers();
				Write<short>(SaveAddress + 0x2110, 0xB791);
			}
			if (Read<short>(SaveAddress + 0x035C) == 0x01) // after seven wonders
			{
				Warp(0x02, 0x0B, 0x63, 0x01, 0x00, 0x0D);
				Write<char>(SaveAddress + 0x3FF5, 5);
				RemoveTTBarriers();
			}
			if (Read<short>(SaveAddress + 0x0368) == 0x02) // before namine wonder
			{
				Warp(0x02, 0x02, 0x63, 0x01, 0x00, 0x00);
				Write<char>(SaveAddress + 0x3FF5, 5);
				RemoveTTBarriers();
				Write<short>(SaveAddress + 0x2080, 0xC544);
			}
			if (Read<short>(SaveAddress + 0x0326) == 0x03) // before back street nobodies
			{
				Warp(0x02, 0x02, 0x63, 0x01, 0x00, 0x00);
				Write<char>(SaveAddress + 0x3FF5, 6);
				RemoveTTBarriers();
				Write<short>(SaveAddress + 0x2114, 0xC546);
			}
			if (Read<short>(SaveAddress + 0x0368) == 0x03) // before mansion
			{
				Warp(0x02, 0x02, 0x63, 0x01, 0x00, 0x00);
				Write<char>(SaveAddress + 0x3FF5, 6);
				RemoveTTBarriers();
				Write<short>(SaveAddress + 0x2114, 0xC546);
			}
			if (Read<short>(SaveAddress + 0x037A) == 0x01) // before library
			{
				Warp(0x02, 0x12, 0x63, 0x01, 0x00, 0x00);
				Write<char>(SaveAddress + 0x3FF5, 6);
				RemoveTTBarriers();
				Write<short>(SaveAddress + 0x211C, 0xC548);
			}
			if (Read<short>(SaveAddress + 0x0392) == 0x01)
			{
				Warp(0x02, 0x12, 0x63, 0x01, 0x00, 0x00); // before entering computer room
				Write<char>(SaveAddress + 0x3FF5, 6);
				RemoveTTBarriers();
				Write<short>(SaveAddress + 0x211C, 0xC548);
			}
			if (Read<short>(SaveAddress + 0x0386) == 0x01) // after entering computer room
			{
				if (Read<char>(SaveAddress + 0x1CFB) == 0)
					Warp(0x02, 0x15, 0x63, Read<short>(SaveAddress + 0x38E), 0x00, Read<short>(SaveAddress + 0x392));
				else if (Read<char>(SaveAddress + 0x1CFB) == 0x01)
					Warp(0x02, 0x15, 0x3B, Read<short>(SaveAddress + 0x038E), 0x00, Read<short>(SaveAddress + 0x392));

				Write<char>(SaveAddress + 0x3FF5, 6);
				RemoveTTBarriers();
				Write<short>(SaveAddress + 0x211C, 0xC548);
			}
			if (Read<short>(SaveAddress + 0x0382) == 0x01) // after axel 2
			{
				if (Read<char>(SaveAddress + 0x0382) == 0)
					Warp(0x02, 0x15, 0x63, Read<short>(SaveAddress + 0x038E), 0x00, Read<short>(SaveAddress + 0x392));
				else if (Read<char>(SaveAddress + 0x1CFB) == 1)
					Warp(0x02, 0x15, 0x3B, Read<short>(SaveAddress + 0x038E), 0x00, Read<short>(SaveAddress + 0x392));

				Write<char>(SaveAddress + 0x3FF5, 6);
				RemoveTTBarriers();
			}
			if (Read<char>(SaveAddress + 0x1CFE) == 1) // post 1st visit 1
			{
				Warp(0x02, 0x02, 0x63, 0x01, 0x00, 0x00);
				Write<char>(SaveAddress + 0x3FF5, 6);
				RemoveTTBarriers();
			}
			else if (Read<char>(SaveAddress + 0x1CFE) == 2) // post 1st visit 2
			{
				Warp(0x02, 0x09, 0x63, 0x02, 0x00, 0x13);
				Write<char>(SaveAddress + 0x3FF5, 6);
				RemoveTTBarriers();
			}
			else if (Read<char>(SaveAddress + 0x1CFE) == 3) // post 1st visit 3
			{
				Warp(0x02, 0x0B, 0x63, 0x01, 0x00, 0x13);
				Write<char>(SaveAddress + 0x3FF5, 6);
				RemoveTTBarriers();
			}
			else if (Read<char>(SaveAddress + 0x1CFE) == 4) // post 1st visit 4
			{
				Warp(0x02, 0x12, 0x63, 0x01, 0x00, 0x00);
				Write<char>(SaveAddress + 0x3FF5, 6);
				RemoveTTBarriers();
			}
			else if (Read<char>(SaveAddress + 0x1CFE) == 5) // post 1st visit 5
			{
				if (Read<char>(SaveAddress + 0x1CFB) == 0)
					Warp(0x02, 0x15, 0x63, Read<short>(SaveAddress + 0x038E), 0x00, Read<short>(SaveAddress + 0x392));
				else if (Read<char>(SaveAddress + 0x1CFB) == 1)
					Warp(0x02, 0x15, 0x3B, Read<short>(SaveAddress + 0x038E), 0x00, Read<short>(SaveAddress + 0x392));

				Write<char>(SaveAddress + 0x3FF5, 6);
				RemoveTTBarriers();
			}

			Write<short>(SaveAddress + 0x20E4, 0x9F42);
			BitNot(SaveAddress + 0x1CEE, 0x0C);
			Write<char>(SaveAddress + 0x1CFB, 0);
		}
	}

	if (Read<char>(SaveAddress + 0x1CFF) == 13) // simulate simulated twilight town
	{
		BitNot(SaveAddress + 0x1CEA, 0x01);
		BitNot(SaveAddress + 0x239E, 0x08);
		if (Read<char>(SaveAddress + 0x3594) > 0)
		{
			Write<char>(SaveAddress + 0x1CF1, Read<char>(SaveAddress + 0x1CF1) + 1);
			Write<char>(SaveAddress + 0x3594, Read<char>(SaveAddress + 0x3594) - 1);
		}
	}

	if (Read<char>(SaveAddress + 0x1CFF) == 13)
	{
		if (Place == 0x0202)
		{
			if (IsEvent(0x02, 0x02, 0x02))
				SpawnObj<short>(0x06, 0x034, 0x23A);
			else
				SpawnObj<short>(0x06, 0x034, 0x239);
		}
	}
}
