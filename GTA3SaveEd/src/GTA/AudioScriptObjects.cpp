#include "sppch.h"
#include "AudioScriptObjects.h"

#include "Core/BufferHelpers.h"

bool FAudioScriptObjects::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );

	FBufferHelpers::ReadBlockHeader( rStream, "AUD" );

	FBufferHelpers::ReadObject( NumAudioObjects, rStream );

	Objects.resize( NumAudioObjects );

	for( auto& rObject : Objects )
	{
		FBufferHelpers::ReadObject( rObject.PoolIndex, rStream );
		FBufferHelpers::ReadObject( rObject.AudioID, rStream );
		FBufferHelpers::Skip2( rStream );

		FBufferHelpers::ReadObject( rObject.Position, rStream );
		FBufferHelpers::ReadObject( rObject.AudioEntity, rStream );
	}

	return true;
}
