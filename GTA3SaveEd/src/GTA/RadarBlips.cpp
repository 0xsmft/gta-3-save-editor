#include "sppch.h"
#include "RadarBlips.h"

#include "Core/BufferHelpers.h"

bool FRadarBlips::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );

	FBufferHelpers::ReadBlockHeader( rStream, "RDR" );

	for( uint32_t Index = 0u; Index < RadarBlips.size(); ++Index )
	{
		FBufferHelpers::ReadObject( RadarBlips[ Index ].Color, rStream );
		FBufferHelpers::ReadObject( RadarBlips[ Index ].Type, rStream );
		FBufferHelpers::ReadObject( RadarBlips[ Index ].EntityHandle, rStream );
		FBufferHelpers::ReadObject( RadarBlips[ Index ].RadarPosition, rStream );
		FBufferHelpers::ReadObject( RadarBlips[ Index ].WorldPosition, rStream );
		FBufferHelpers::ReadObject( RadarBlips[ Index ].BlipIndex, rStream );
		FBufferHelpers::ReadObject( RadarBlips[ Index ].IsBright, rStream );
		FBufferHelpers::ReadObject( RadarBlips[ Index ].Enabled, rStream );
		FBufferHelpers::ReadObject( RadarBlips[ Index ].Radius, rStream );
		FBufferHelpers::ReadObject( RadarBlips[ Index ].Scale, rStream );
		FBufferHelpers::ReadObject( RadarBlips[ Index ].Display, rStream );
		FBufferHelpers::ReadObject( RadarBlips[ Index ].Sprite, rStream );

		FBufferHelpers::Skip2( rStream );
	}

	return true;
}

void FRadarBlips::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( 1548u, rStream );
	FBufferHelpers::WriteObject( 1544u, rStream );
	FBufferHelpers::WriteBlockHeader( rStream, "RDR", 1536 );

	for( uint32_t Index = 0u; Index < RadarBlips.size(); ++Index )
	{
		FBufferHelpers::WriteObject( RadarBlips[ Index ].Color, rStream );
		FBufferHelpers::WriteObject( RadarBlips[ Index ].Type, rStream );
		FBufferHelpers::WriteObject( RadarBlips[ Index ].EntityHandle, rStream );
		FBufferHelpers::WriteObject( RadarBlips[ Index ].RadarPosition, rStream );
		FBufferHelpers::WriteObject( RadarBlips[ Index ].WorldPosition, rStream );
		FBufferHelpers::WriteObject( RadarBlips[ Index ].BlipIndex, rStream );
		FBufferHelpers::WriteObject( RadarBlips[ Index ].IsBright, rStream );
		FBufferHelpers::WriteObject( RadarBlips[ Index ].Enabled, rStream );
		FBufferHelpers::WriteObject( RadarBlips[ Index ].Radius, rStream );
		FBufferHelpers::WriteObject( RadarBlips[ Index ].Scale, rStream );
		FBufferHelpers::WriteObject( RadarBlips[ Index ].Display, rStream );
		FBufferHelpers::WriteObject( RadarBlips[ Index ].Sprite, rStream );

		FBufferHelpers::WriteN( rStream, 2 );
	}
}
