#pragma once

#include "Base/Common.h"

#include <array>
#include <fstream>

struct FPickup
{
	uint8_t Type = 0;
	bool HasBeenPickedUp =false;
	int16_t Ammo = 0;
	uint32_t PoolIndex = 0u;
	uint32_t RegenTime = 0u;
	int16_t ModelID = 0u;
	uint16_t Index = 0u;
	FVec3 Position;
};

struct FPickups
{
	std::array<FPickup, 336> Pickups;

	uint16_t CollectedPickupIndex = 0;
	uint16_t __unknown_0__ = 0;

	std::array<uint32_t, 20> PickupsCollected;

	bool Read( std::ifstream& rStream );
};
