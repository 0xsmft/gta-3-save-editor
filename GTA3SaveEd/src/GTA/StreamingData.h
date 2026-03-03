#pragma once

#include "Core/Common.h"

#include <vector>
#include <fstream>

struct FStreamingData
{
	std::vector<int8_t> Data;

	bool Read( std::ifstream& rStream );
};
