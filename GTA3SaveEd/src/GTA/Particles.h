#pragma once

#include "Core/Common.h"

#include <vector>
#include <fstream>

struct FCPlaceable
{
	int32_t pvtbl = 0;
	FCMartix Matrix{};
};

struct FCParticle : public FCPlaceable
{
	int32_t pNext = 0;
	int32_t pPrev = 0;
	int32_t pParticle = 0;

	uint32_t RemoveTimer = 0;

	uint32_t ParticleObjectType = 0;
	uint32_t ParticleType = 0;

	uint8_t NumEffectCycles = 0;
	uint8_t SkipFrames = 0;
	uint16_t FrameCounter = 0;
	uint16_t State = 0;

	FVec3 Target{};

	float Spread = 0.0f;
	float Size = 0.0f;

	uint32_t Color = 0;
	bool DestroyWhenFar = false;
	uint8_t CreationChance = false;
};

struct FParticles 
{
	uint32_t NumPariclesObjects = 0;

	std::vector<FCParticle> Particles;

	bool Read( std::ifstream& rStream );
	void Write( std::ofstream& rStream );
};
