#pragma once

#include "Core/Common.h"

#include <array>
#include <fstream>

struct FCGangInfo
{
	uint32_t VehicleModelIndex = 0u;
	int8_t PedModelOverride = 0;
	uint32_t WeaponA = 0u;
	uint32_t WeaponB = 0u;
};

struct FGangs
{
	std::array<FCGangInfo, 9> Gangs;

	bool Read( std::ifstream& rStream );
	void Write( std::ofstream& rStream );
};
