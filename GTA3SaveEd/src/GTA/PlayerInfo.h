#pragma once

#include "Core/Common.h"

#include <fstream>

struct FPlayerInfo
{
	int32_t Money = 0;
	int8_t WastedBustedState = 0;
	uint32_t WastedBustedTime = 0;
	int16_t TrafficMultiplier = 0;
	float RoadDensity = 1.45f;
	int32_t MoneyOnScreen = 0;
	uint32_t CollectedHiddenPackages = 0;
	uint32_t TotalHiddenPackages = 0;
	
	bool InfiniteSprint = false;
	bool FastReload = false;
	bool GetOutOfJailFree = false;
	bool GetOutOfHospitalFree = false;

	char PlayerName[ 70 ]{ 0 };

	bool Read( std::ifstream& rStream );
};
