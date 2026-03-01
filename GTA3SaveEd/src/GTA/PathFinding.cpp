#include "sppch.h"
#include "PathFinding.h"

#include "Base/BufferHelpers.h"

bool FPathFinding::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );

	FBufferHelpers::ReadObject( NumberOfPaths, rStream );

	DisabledPedPathNodes.resize( NumberOfPaths / 2 );
	DisabledCarPathNodes.resize( NumberOfPaths / 2 );

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
