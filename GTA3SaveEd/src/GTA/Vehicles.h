#pragma once

#include "Base/Common.h"

#include <vector>
#include <fstream>

struct FCVehicle
{
	uint8_t __unknown_0__[ 52 ]{};

	FVec3 Position{};

	uint8_t __unknown_1__[ 1384 ]{};
};

struct FVehicle
{
	uint32_t Field0h = 0;
	uint16_t ModelID = 0;
	uint32_t Field06h = 0;

	FCVehicle CVehicle{};
};

struct FCBoat
{
	uint8_t __unknown_0__[ 52 ]{};

	FVec3 Position{};

	uint8_t __unknown_1__[ 1092 ]{};
};

struct FBoat
{
	uint32_t Field0h = 0;
	uint16_t ModelID = 0;
	uint32_t Field06h = 0;

	FCBoat CBoat;
};

struct FVehicles
{
	uint32_t Count = 0;
	uint32_t NumberOfBoats = 0;

	std::vector<FVehicle> Vehicles;
	std::vector<FBoat> Boats;

	bool Read( std::ifstream& rStream );
};
