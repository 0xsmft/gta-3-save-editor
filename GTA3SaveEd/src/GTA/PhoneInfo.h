#pragma once

#include "Base/Common.h"

#include <array>
#include <vector>
#include <fstream>

enum class PhoneState : uint32_t
{
	None
};

struct FCPhone
{
	FVec3 Position{};

	std::array<uint32_t, 6> Messages{};

	uint32_t RepeatedMessageStartTime = 0u;
	uint32_t Handle = 0u;
	uint32_t PhoneState = 0u;
	bool VisibleToCam = true;
};

struct FPhones
{
	uint32_t NumPhones = 0u;
	uint32_t NumActivePhones = 0u;

	std::vector<FCPhone> Phones;

	bool Read( std::ifstream& rStream );
};
