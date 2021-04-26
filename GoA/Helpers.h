#pragma once

#include "Globals.h"
extern "C"
{
	#include <lua.h>
}

template<typename T>
T Read(char* address)
{
	return *(T*)address;
}

template<typename T>
void Write(char* address, T value)
{
	*(T*)address = value;
}

template<typename T>
int LUA_Read(lua_State* L)
{
	uint64_t offset = (uint64_t)lua_tonumber(L, 1);
	T readValue = Read<T>(BaseAddress + offset);

	lua_pushnumber(L, readValue);
	return 1;
}

template<typename T>
int LUA_ReadA(lua_State* L)
{
	uint64_t address = (uint64_t)lua_tonumber(L, 1);
	if (address < (uint64_t)BaseAddress)
	{
		lua_pushnumber(L, 0);
		return 1;
	}

	T readValue = Read<T>((char*)((void*)address));
	
	lua_pushnumber(L, readValue);
	return 1;
}

template<typename T>
int LUA_WriteA(lua_State* L)
{
	uint64_t address = lua_tonumber(L, 1);
	if (address < (uint64_t)BaseAddress)
		return 0;

	T value = (T)lua_tonumber(L, 2);

	Write<T>((char*)((void*)address), value);
	return 0;
}

template<typename T>
int LUA_Write(lua_State* L)
{
	uint64_t offset = lua_tonumber(L, 1);
	T value = (T)lua_tonumber(L, 2);

	Write<T>(BaseAddress + offset, value);

	return 0;
}

template<>
void Write<const char*>(char* address, const char* value);

int LUA_WriteString(lua_State* L);
int LUA_WriteStringA(lua_State* L);

inline void BitNot(char* address, char byte)
{
	Write<char>(address, Read<char>(address) & ~byte);
}

inline void BitOr(char* address, char byte)
{
	Write<char>(address, Read<char>(address) | byte);
}

bool IsEvent(short map, short battle, short event);

template<typename T>
void SpawnObj(int subFile, int offset, T value)
{
	intptr_t subPoint = (ARD + 0x08 + 0x10 * (__int64)subFile);
	intptr_t x = ARD & 0xFFFFFF000000;
	intptr_t y = Read<int>((char *)((void *)subPoint)) & 0xFFFFFF;
	char* temp = (char *)((void *)(x + y + offset));
	Write<T>((char *)temp, value);
}

void Warp(char world, char room, short door, short map, short battle, short event);
void PoohWarp();

void SkipCutscene();

void ToggleSpeedUp(bool toggle);

void RefillDrive();

void RemoveTTBarriers();
