#pragma once

#include <stdint.h>

extern char* BaseAddress;
extern char* CurrentLocationAddress;
extern char* CutsceneLengthAddress;
extern char* CutsceneSkipAddress;
extern char* SaveAddress;

extern char* Object00Address;
extern char* System03Address;

extern char* CurrentWorldAddress;
extern char* CurrentRoomAddress;
extern char* CurrentPlaceAddress;
extern char* CurrentDoorAddress;
extern char* CurrentMapAddress;
extern char* CurrentBattleAddress;
extern char* CurrentEventAddress;
extern char* PreviousPlaceAddress;

extern char* GameSpeedAddress;
extern char* Slot1Address;

/*Location Data*/
extern char World;
extern char Room;
extern short Place;
extern short Door;
extern short Map;
extern short Battle;
extern short Event;
extern short PrevPlace;
extern int64_t ARD;
