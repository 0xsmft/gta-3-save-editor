#pragma once

#include "Core/Common.h"

#include <array>
#include <fstream>

struct FPedTypeInfo
{
	int32_t Flag = 0;

	float __unknown_0__ = 0.0f;
	float __unknown_1__ = 0.0f;
	float __unknown_2__ = 0.0f;

	float FleeDistance = 0.0f;
	float HeadingChangeRate = 0.0f;
	
	int32_t ThreatFlags = 0;
	int32_t AvoidFlags = 0;
};

struct FPedTypeInfos
{
	std::array<FPedTypeInfo, 23> PedTypeInfos;

	bool Read( std::ifstream& rStream );
	void Write( std::ofstream& rStream );
};
