#pragma once

#include "Base/Common.h"

#include <vector>
#include <fstream>

struct FCCompressedMatrix
{
	FVec3 Position;
	uint8_t RightX = 0;
	uint8_t RightY = 0;
	uint8_t RightZ = 0;
	uint8_t UpX = 0;
	uint8_t UpY = 0;
	uint8_t UpZ = 0;

	uint8_t __a_UpZ = 0;
	uint8_t __b_UpZ = 0;
};

struct FCObject
{
	int16_t ModelID = 0;
	int32_t ObjectReference = 0;

	FCCompressedMatrix Matrix{};

	uint32_t __unknown_0__ = 0u;
	float UproofLimit = 0.0f;

	FCCompressedMatrix ObjectMatrix{};

	uint32_t __unknown_1__ = 0u;

	uint8_t ObjectCreatedBy = 0;
	bool IsPickup = false;
	bool IsPickupInShop = false;
	bool IsPickupOutofStock = false;
	bool IsGlassCracked = false;
	bool IsGlassBroken = false;
	bool HasBeenDamaged = false;
	
	float CollisionDmgMultiplier = 0.0f;
	uint8_t CollisionDamageEffect = 0;
	uint8_t SpecialCollisionResponseCase = 0;
	uint32_t EndOfLifeTime = 0u;
	uint32_t FlagsA = 0u;
	uint32_t FlagsB = 0u;
};

struct FObjects
{
	uint32_t Count = 0;
	std::vector<FCObject> Objects;

	bool Read( std::ifstream& rStream );
};
