#pragma once

#include <fstream>

struct FPathFinding
{
	uint32_t NumberOfPaths = 0u;

	std::vector<uint8_t> DisabledPedPathNodes;
	std::vector<uint8_t> DisabledCarPathNodes;

	bool Read( std::ifstream& rStream );
};
