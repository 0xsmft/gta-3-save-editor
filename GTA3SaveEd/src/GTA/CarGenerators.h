#pragma once

#include "Core/Common.h"

#include <array>
#include <fstream>

struct FCCarGenerator 
{
	uint32_t ModexIndex = 0u;
	FVec3 Position{};
	float Angle = 0.0f;
	int16_t ColorA = 0;
	int16_t ColorB = 0;
	bool ForceSpawn = false;
	bool Alarm = false;
	int8_t DoorLook = false;

	uint16_t MinDelay = 0;
	uint16_t MaxDelay = 0;

	uint32_t Timer = 0u;
	int32_t Handle = 0u;
	int16_t UsesRemaining = 0u;
	bool IsBlocking = false;

	FVec3 VecInf{};
	FVec3 VecSup{};
	float Size = 0.0f;
};

struct FTheCarGenerators 
{
	uint32_t CarGenDataSize = 0x0C;

	uint32_t NumberOfActiveCarGens = 0u;
	uint32_t CurrentActiveCount = 0u;
	uint8_t ProcessCounter = 0;
	uint8_t GenerateEvenIfPlayerIsCloseCounter = 0;

	uint32_t CarGenArraySize = 0x2D00;

	std::array<FCCarGenerator, 160> CarGenerators;

	bool Read( std::ifstream& rStream );
};
