#pragma once

#include <stdint.h>

struct FVec2
{
	float X = 0.0F, Y = 0.0F;
};

struct FVec3
{
	FVec3() = default;

	float X = 0.0F, Y = 0.0F, Z = 0.0F;
};

struct FCMartix 
{
	FVec3 Right{};
	uint32_t flags = 0;
	
	FVec3 Up{};
	uint32_t pad = 0;

	FVec3 At{};
	uint32_t pad1 = 0;

	FVec3 Position{};
	uint32_t pad2 = 0;

	uint32_t pAttachment = 0;
	bool HasRwMatrix = false;
};
