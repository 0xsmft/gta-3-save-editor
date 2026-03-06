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

void FAudioScriptObjects::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( 400u, rStream );
	FBufferHelpers::WriteObject( 396u, rStream );

	FBufferHelpers::WriteBlockHeader( rStream, "AUD", 388u );

	FBufferHelpers::WriteObject( NumAudioObjects, rStream );

	for( auto& rObject : Objects )
	{
		FBufferHelpers::WriteObject( rObject.PoolIndex, rStream );
		FBufferHelpers::WriteObject( rObject.AudioID, rStream );
		FBufferHelpers::WriteN( rStream, 2 );

		FBufferHelpers::WriteObject( rObject.Position, rStream );
		FBufferHelpers::WriteObject( rObject.AudioEntity, rStream );
	}
}
