#pragma once

#include "Core/Common.h"

#include <vector>
#include <fstream>

struct FAudioScriptObject
{
	uint32_t PoolIndex = 0;
	int16_t AudioID = 0;
	FVec3 Position{};
	int32_t AudioEntity = 0;
};

struct FAudioScriptObjects
{
	uint32_t NumAudioObjects = 0u;
	
	std::vector<FAudioScriptObject> Objects;

	bool Read( std::ifstream& rStream );
};
