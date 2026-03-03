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
