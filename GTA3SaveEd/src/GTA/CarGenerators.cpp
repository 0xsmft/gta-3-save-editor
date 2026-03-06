#include "sppch.h"
#include "CarGenerators.h"

#include "Core/BufferHelpers.h"

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

void FTheCarGenerators::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( 11552u, rStream );
	FBufferHelpers::WriteObject( 11548u, rStream );

	FBufferHelpers::WriteBlockHeader( rStream, "CGN", 11540u );

	FBufferHelpers::WriteObject( CarGenDataSize, rStream );

	FBufferHelpers::WriteObject( NumberOfActiveCarGens, rStream );
	FBufferHelpers::WriteObject( CurrentActiveCount, rStream );
	FBufferHelpers::WriteObject( ProcessCounter, rStream );
	FBufferHelpers::WriteObject( GenerateEvenIfPlayerIsCloseCounter, rStream );

	FBufferHelpers::WriteN( rStream, 2 );

	FBufferHelpers::WriteObject( CarGenArraySize, rStream );

	for( uint32_t Index = 0u; Index < CarGenerators.size(); ++Index )
	{
		FBufferHelpers::WriteObject( CarGenerators[ Index ].ModexIndex, rStream );
		FBufferHelpers::WriteObject( CarGenerators[ Index ].Position, rStream );
		FBufferHelpers::WriteObject( CarGenerators[ Index ].Angle, rStream );
		FBufferHelpers::WriteObject( CarGenerators[ Index ].ColorA, rStream );
		FBufferHelpers::WriteObject( CarGenerators[ Index ].ColorB, rStream );

		FBufferHelpers::WriteObject( CarGenerators[ Index ].ForceSpawn, rStream );
		FBufferHelpers::WriteObject( CarGenerators[ Index ].Alarm, rStream );
		FBufferHelpers::WriteObject( CarGenerators[ Index ].DoorLook, rStream );

		FBufferHelpers::WriteByte( rStream );

		FBufferHelpers::WriteObject( CarGenerators[ Index ].MinDelay, rStream );
		FBufferHelpers::WriteObject( CarGenerators[ Index ].MaxDelay, rStream );

		FBufferHelpers::WriteObject( CarGenerators[ Index ].Timer, rStream );
		FBufferHelpers::WriteObject( CarGenerators[ Index ].Handle, rStream );
		FBufferHelpers::WriteObject( CarGenerators[ Index ].UsesRemaining, rStream );
		FBufferHelpers::WriteObject( CarGenerators[ Index ].IsBlocking, rStream );

		FBufferHelpers::WriteByte( rStream );

		FBufferHelpers::WriteObject( CarGenerators[ Index ].VecInf, rStream );
		FBufferHelpers::WriteObject( CarGenerators[ Index ].VecSup, rStream );
		FBufferHelpers::WriteObject( CarGenerators[ Index ].Size, rStream );
	}
}
