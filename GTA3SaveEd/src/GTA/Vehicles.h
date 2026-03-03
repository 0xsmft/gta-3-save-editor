#pragma once

#include "Core/Common.h"

#include <vector>
#include <fstream>

struct FCVehicle
{
	uint8_t __unknown_0__[ 52 ]{};

	FVec3 Position{};

	uint8_t __unknown_1__[ 1384 ]{};
};

enum class VehicleType : uint32_t
{
	Car,
	Boat,
	Train,
	Helicopter,
	Dodo,
	Bike
};

struct FVehicle
{
	VehicleType Type = VehicleType::Car;
	int16_t ModelID = 0;
	int32_t Slot = 0;

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
	VehicleType Type = VehicleType::Boat;
	int16_t ModelID = 0;
	int32_t Slot = 0;

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
