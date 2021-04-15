#pragma once

#include "Globals.h"

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

inline float ReadFloat(char* address)
{
	return *(float*)address;
}

inline void WriteByte(char* address, char value)
{
	*address = value;
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

template<typename T>
void Write(char* address, T value)
{
	*(T*)address = value;
}

void WriteString(char *address, const char* value);

inline void BitNot(char* address, char byte)
{
	WriteByte(address, ReadByte(address) & ~byte);
}

inline void BitOr(char* address, char byte)
{
	WriteByte(address, ReadByte(address) | byte);
}

bool IsEvent(short map, short battle, short event);

template<typename T>
void SpawnObj(int subFile, int offset, T value)
{
	intptr_t subPoint = (ARD + 0x08 + 0x10 * subFile);
	intptr_t x = ARD & 0xFFFFFF000000;
	intptr_t y = ReadInt((char *)((void *)subPoint)) & 0xFFFFFF;
	char* temp = (char *)((void *)(x + y + offset));
	Write<T>((char *)temp, value);
}

void Warp(char world, char room, short door, short map, short battle, short event);
void PoohWarp();

void SkipCutscene();

void ToggleSpeedUp(bool toggle);

void RefillDrive();
