#include "Helpers.h"
#include "Globals.h"

#include <string.h>

template<>
void Write<const char*>(char* address, const char* value)
{
	size_t length = strlen(value);
	for (size_t i = 0; i < length; i++)
		Write<char>(address + i, value[i]);
}

void WriteStringLength(char* address, const char* value, size_t length)
{
	for (size_t i = 0; i < length; i++)
		Write<char>(address + i, value[i]);
}

int LUA_WriteString(lua_State* L)
{
	if (lua_isstring(L, 2))
	{
		uint64_t offset = lua_tonumber(L, 1);
		const char* value = lua_tostring(L, 2);
		size_t length = lua_rawlen(L, 2);
		WriteStringLength(BaseAddress + offset, value, length);
	}

	return 0;
}

int LUA_WriteStringA(lua_State* L)
{
	if (lua_isstring(L, 2))
	{
		uint64_t address = lua_tonumber(L, 1);
		const char* value = lua_tostring(L, 2);
		size_t length = lua_rawlen(L, 2);
		WriteStringLength((char *)((void *)address), value, length);
	}

	return 0;
}

bool IsEvent(short map, short battle, short event)
{
	return ((Map == map) && 
			(Battle == battle) && 
			(Event == event));
}

void Warp(char world, char room, short door, short map, short battle, short event)
{
	Write<char>(CurrentWorldAddress, world);
	Write<char>(CurrentRoomAddress, room);
	Write<short>(CurrentDoorAddress, door);
	Write<short>(CurrentMapAddress, map);
	Write<short>(CurrentBattleAddress, battle);
	Write<short>(CurrentEventAddress, event);

	Write<char>(SaveAddress + 0x000C, world);
	Write<char>(SaveAddress + 0x000D, room);
	Write<short>(SaveAddress + 0x000E, door);
}

void PoohWarp()
{
	if (Read<short>(SaveAddress + 0x06AC) == 0x00)
		Warp(0x04, 0x1A, 0x00, 0x00, 0x00, 0x02);
	else if (Read<short>(SaveAddress + 0x06AC) == 0x01)
		Warp(0x04, 0x1A, 0x00, 0x01, 0x00, 0x01);
}

void SkipCutscene()
{
	Write<char>(CutsceneSkipAddress, 0x01);
}

void ToggleSpeedUp(bool toggle)
{
	if (toggle)
		Write<float>(GameSpeedAddress, 2);
	else
		Write<float>(GameSpeedAddress, 1);
}

void RefillDrive()
{
	Write<short>(SaveAddress + 0x3524, 0);
	Write<char>(SaveAddress + 0x3528, 100);
	Write<char>(SaveAddress + 0x3529, Read<char>(SaveAddress + 0x352A));
}

void RemoveTTBarriers()
{
	Write<short>(SaveAddress + 0x207C, 0x0000);
	Write<short>(SaveAddress + 0x2080, 0x0000);
	Write<short>(SaveAddress + 0x20E4, 0x0000);
	Write<short>(SaveAddress + 0x20E8, 0x0000);
	Write<short>(SaveAddress + 0x20EC, 0x0000);
	Write<short>(SaveAddress + 0x20F0, 0x0000);
	Write<short>(SaveAddress + 0x20F4, 0x0000);
	Write<short>(SaveAddress + 0x20F8, 0x0000);
	Write<short>(SaveAddress + 0x20FC, 0x0000);
	Write<short>(SaveAddress + 0x2100, 0x0000);
	Write<short>(SaveAddress + 0x2110, 0x0000);
	Write<short>(SaveAddress + 0x2114, 0x0000);
	Write<short>(SaveAddress + 0x211C, 0x0000);
	Write<short>(SaveAddress + 0x2120, 0x0000);
}
