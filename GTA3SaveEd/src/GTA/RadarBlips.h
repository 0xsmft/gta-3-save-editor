#pragma once

#include "Base/Common.h"

#include <array>
#include <fstream>

struct FSRadarTrace
{
	uint32_t Color = 0u;
	uint32_t Type = 0u;
	uint32_t EntityHandle = 0u;

	FVec2 RadarPosition{};
	FVec3 WorldPosition{};

	uint16_t BlipIndex = 0;
	bool IsBright = false;
	bool Enabled = false;
	float Radius = 0.0f;
	uint16_t Scale = 0;
	uint16_t Display = 0;
	uint16_t Sprite = 0;
};

struct FRadarBlips
{
	std::array<FSRadarTrace, 32> RadarBlips;

	bool Read( std::ifstream& rStream );
};
