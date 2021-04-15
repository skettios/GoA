#include "Helpers.h"
#include "Globals.h"

#include <string.h>

void WriteString(char* address, const char* value)
{
	size_t length = strlen(value);
	for (size_t i = 0; i < length; i++)
		WriteByte(address + i, value[i]);
}

bool IsEvent(short map, short battle, short event)
{
	return ((Map == map) && 
			(Battle == battle) && 
			(Event == event));
}

void Warp(char world, char room, short door, short map, short battle, short event)
{
	WriteByte(CurrentWorldAddress, world);
	WriteByte(CurrentRoomAddress, room);
	WriteShort(CurrentDoorAddress, door);
	WriteShort(CurrentMapAddress, map);
	WriteShort(CurrentBattleAddress, battle);
	WriteShort(CurrentEventAddress, event);

	WriteByte(SaveAddress + 0x000C, world);
	WriteByte(SaveAddress + 0x000D, room);
	WriteShort(SaveAddress + 0x000E, door);
}

void PoohWarp()
{
	if (ReadShort(SaveAddress + 0x06AC) == 0x00)
		Warp(0x04, 0x1A, 0x00, 0x00, 0x00, 0x02);
	else if (ReadShort(SaveAddress + 0x06AC) == 0x01)
		Warp(0x04, 0x1A, 0x00, 0x01, 0x00, 0x01);
}

void SkipCutscene()
{
	WriteByte(CutsceneSkipAddress, 0x01);
}

void ToggleSpeedUp(bool toggle)
{
	if (toggle)
		WriteFloat(GameSpeedAddress, 2);
	else
		WriteFloat(GameSpeedAddress, 1);
}

void RefillDrive()
{
	WriteShort(SaveAddress + 0x3524, 0);
	WriteByte(SaveAddress + 0x3528, 100);
	WriteByte(SaveAddress + 0x3529, ReadByte(SaveAddress + 0x352A));
}
