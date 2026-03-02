#pragma once

#include "Base/Common.h"

#include <array>
#include <fstream>

struct FCZone
{
	char Name[ 8 ]{0};
	FVec3 Min{};
	FVec3 Max{};

	uint32_t Type = 0u;
	uint32_t Level = 0u;

	int16_t ZoneInfoDay = 0u;
	int16_t ZoneInfoNight = 0u;

	int32_t ChildZoneIndex = 0u;
	int32_t ParentZoneIndex = 0u;
	int32_t NextZoneIndex = 0u;
};

struct FCZoneInfo
{
	int16_t CarDensity = 0;
	std::array<int16_t, 6> CarThresholds{};

	int16_t CopCarDensityBaseRate = 0;
	std::array<int16_t, 9> CopCarDensity{};

	int16_t PedDensity = 0;
	int16_t CopPedDensity = 0;
	
	std::array<int16_t, 9> GangPedDensity{};

	int16_t PedGroup = 0;
};

struct FTheZones
{
	uint32_t CurrentZoneIndex = 0u;
	uint32_t CurrentLevel = 0u;
	uint16_t FindIndex = 0;

	std::array<FCZone, 50> Zones;
	std::array<FCZoneInfo, 100> ZoneInfos;

	uint16_t NumberOfZones = 0;
	uint16_t NumberOfZoneInfos = 0;

	std::array<FCZone, 25> MapZones;
	std::array<int16_t, 36> AudioZones;

	uint16_t NumberOfMapZones = 0;
	uint16_t NumberOfAudioZones = 0;

	bool Read( std::ifstream& rStream );
};
