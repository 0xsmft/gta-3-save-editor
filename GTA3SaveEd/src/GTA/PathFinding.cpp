#include "sppch.h"
#include "PathFinding.h"

#include "Core/BufferHelpers.h"

bool FPathFinding::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip4( rStream );

	FBufferHelpers::ReadObject( NumberOfPaths, rStream );
	NumberOfPaths /= 2;

	DisabledPedPathNodes.resize( NumberOfPaths );
	DisabledCarPathNodes.resize( NumberOfPaths );

	for( uint32_t Index = 0u; Index < DisabledPedPathNodes.size(); ++Index )
	{
		FBufferHelpers::ReadObject( DisabledPedPathNodes[ Index ], rStream );
	}

	for( uint32_t Index = 0u; Index < DisabledCarPathNodes.size(); ++Index )
	{
		FBufferHelpers::ReadObject( DisabledCarPathNodes[ Index ], rStream );
	}

	return true;
}
