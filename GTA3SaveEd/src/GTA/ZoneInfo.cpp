#include "sppch.h"
#include "ZoneInfo.h"

#include "Core/BufferHelpers.h"

bool FTheZones::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );

	FBufferHelpers::ReadBlockHeader( rStream, "ZNS" );

	FBufferHelpers::ReadObject( CurrentZoneIndex, rStream );
	FBufferHelpers::ReadObject( CurrentLevel, rStream );
	FBufferHelpers::ReadObject( FindIndex, rStream );
	FBufferHelpers::Skip2( rStream );

	for( uint32_t Index = 0u; Index < Zones.size(); ++Index )
	{
		FBufferHelpers::ReadObject( Zones[ Index ], rStream );
	}

	for( uint32_t Index = 0u; Index < ZoneInfos.size(); ++Index )
	{
		FBufferHelpers::ReadObject( ZoneInfos[ Index ], rStream );
	}

	FBufferHelpers::ReadObject( NumberOfZones, rStream );
	FBufferHelpers::ReadObject( NumberOfZoneInfos, rStream );

	for( uint32_t Index = 0u; Index < MapZones.size(); ++Index )
	{
		FBufferHelpers::ReadObject( MapZones[ Index ], rStream );
	}

	for( uint32_t Index = 0u; Index < AudioZones.size(); ++Index )
	{
		FBufferHelpers::ReadObject( AudioZones[ Index ], rStream );
	}

	FBufferHelpers::ReadObject( NumberOfMapZones, rStream );
	FBufferHelpers::ReadObject( NumberOfAudioZones, rStream );

	return true;
}

void FTheZones::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( 10104u, rStream );
	FBufferHelpers::WriteObject( 10100u, rStream );

	FBufferHelpers::WriteBlockHeader( rStream, "ZNS", 10092u );

	FBufferHelpers::WriteObject( CurrentZoneIndex, rStream );
	FBufferHelpers::WriteObject( CurrentLevel, rStream );
	FBufferHelpers::WriteObject( FindIndex, rStream );
	FBufferHelpers::WriteN( rStream, 2 );

	for( uint32_t Index = 0u; Index < Zones.size(); ++Index )
	{
		FBufferHelpers::WriteObject( Zones[ Index ], rStream );
	}

	for( uint32_t Index = 0u; Index < ZoneInfos.size(); ++Index )
	{
		FBufferHelpers::WriteObject( ZoneInfos[ Index ], rStream );
	}

	FBufferHelpers::WriteObject( NumberOfZones, rStream );
	FBufferHelpers::WriteObject( NumberOfZoneInfos, rStream );

	for( uint32_t Index = 0u; Index < MapZones.size(); ++Index )
	{
		FBufferHelpers::WriteObject( MapZones[ Index ], rStream );
	}

	for( uint32_t Index = 0u; Index < AudioZones.size(); ++Index )
	{
		FBufferHelpers::WriteObject( AudioZones[ Index ], rStream );
	}

	FBufferHelpers::WriteObject( NumberOfMapZones, rStream );
	FBufferHelpers::WriteObject( NumberOfAudioZones, rStream );
}
