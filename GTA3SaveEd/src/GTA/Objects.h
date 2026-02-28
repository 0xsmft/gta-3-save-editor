#pragma once

#include "Base/Common.h"

#include <vector>
#include <fstream>

struct FCObject
{
	uint16_t ModelID = 0;
	uint32_t ObjectReference = 0;
	FVec3 Position{};

	FVec3 __unknown_0__;

	uint8_t __unknown_1__[ 12 ]{};
	uint8_t __unknown_2__ = 0;
	uint8_t __unknown_3__ = 0;
	uint8_t __unknown_4__ = 0;
	uint8_t __unknown_5__ = 0;
	uint8_t __unknown_6__ = 0;
	uint8_t __unknown_7__ = 0;
	uint8_t __unknown_8__ = 0;
	uint8_t __unknown_9__ = 0;
	uint8_t __unknown_10__ = 0;
	uint8_t __unknown_11__ = 0;
	uint32_t __unknown_12__ = 0u;
	uint32_t __unknown_13__ = 0u;
	uint32_t __unknown_14__ = 0u;
};

struct FObjects
{
	uint32_t Count = 0;
	std::vector<FCObject> Objects;

	bool Read( std::ifstream& rStream );
};
