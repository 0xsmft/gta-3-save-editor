#pragma once

#include "Core/Common.h"

#include <array>
#include <fstream>

struct FRestartPoint 
{
	FVec3 Position{};
	float Angle = 0.0f;
};

struct FRestartInfo
{
	std::array<FRestartPoint, 8> HospitalRestartPoints;
	std::array<FRestartPoint, 8> PoliceRestartPoints;

	uint16_t NumberOfHospitalRestarts = 0;
	uint16_t NumberOfPoliceRestarts = 0;

	bool OverrideRestart = false;

	FRestartPoint Override{};

	bool FadeInAfterNextDeath = false;
	bool FadeInAfterNextArrest = false;
	uint8_t OverrideHospitalLevel = 0;
	uint8_t OverridePoliceLevel = 0;

	bool Read( std::ifstream& rStream );
};
