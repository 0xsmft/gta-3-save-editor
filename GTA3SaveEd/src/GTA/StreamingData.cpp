#include "sppch.h"
#include "StreamingData.h"

#include "Core/BufferHelpers.h"

bool FStreamingData::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip4( rStream );

	uint32_t size = 0u;
	FBufferHelpers::ReadObject( size, rStream );

	Data.resize( size );

	for( auto& rData : Data )
	{
		FBufferHelpers::ReadObject( rData, rStream );
	}

	return true;
}
