#include "sppch.h"
#include "CarGenerators.h"

#include "Base/BufferHelpers.h"

bool FTheCarGenerators::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );

	FBufferHelpers::ReadBlockHeader( rStream, "CGN" );

	FBufferHelpers::ReadObject( CarGenDataSize, rStream );

	if( CarGenDataSize != 0x0C )
	{
		__debugbreak();
	}

	FBufferHelpers::ReadObject( NumberOfActiveCarGens, rStream );
	FBufferHelpers::ReadObject( CurrentActiveCount, rStream );
	FBufferHelpers::ReadObject( ProcessCounter, rStream );
	FBufferHelpers::ReadObject( GenerateEvenIfPlayerIsCloseCounter, rStream );

	FBufferHelpers::Skip2( rStream );

	FBufferHelpers::ReadObject( CarGenArraySize, rStream );

	if( CarGenArraySize != 0x2D00 )
	{
		__debugbreak();
	}

	for( uint32_t Index = 0u; Index < CarGenerators.size(); ++Index )
	{
		FBufferHelpers::ReadObject( CarGenerators[ Index ].ModexIndex, rStream );
		FBufferHelpers::ReadObject( CarGenerators[ Index ].Position, rStream );
		FBufferHelpers::ReadObject( CarGenerators[ Index ].Angle, rStream );
		FBufferHelpers::ReadObject( CarGenerators[ Index ].ColorA, rStream );
		FBufferHelpers::ReadObject( CarGenerators[ Index ].ColorB, rStream );

		FBufferHelpers::ReadObject( CarGenerators[ Index ].ForceSpawn, rStream );
		FBufferHelpers::ReadObject( CarGenerators[ Index ].Alarm, rStream );
		FBufferHelpers::ReadObject( CarGenerators[ Index ].DoorLook, rStream );

		FBufferHelpers::SkipByte( rStream );

		FBufferHelpers::ReadObject( CarGenerators[ Index ].MinDelay, rStream );
		FBufferHelpers::ReadObject( CarGenerators[ Index ].MaxDelay, rStream );
		
		FBufferHelpers::ReadObject( CarGenerators[ Index ].Timer, rStream );
		FBufferHelpers::ReadObject( CarGenerators[ Index ].Handle, rStream );
		FBufferHelpers::ReadObject( CarGenerators[ Index ].UsesRemaining, rStream );
		FBufferHelpers::ReadObject( CarGenerators[ Index ].IsBlocking, rStream );

		FBufferHelpers::SkipByte( rStream );

		FBufferHelpers::ReadObject( CarGenerators[ Index ].VecInf, rStream );
		FBufferHelpers::ReadObject( CarGenerators[ Index ].VecSup, rStream );
		FBufferHelpers::ReadObject( CarGenerators[ Index ].Size, rStream );
	}

	return true;
}
