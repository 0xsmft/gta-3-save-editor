#include "sppch.h"
#include "Objects.h"

#include "Base/BufferHelpers.h"

bool FObjects::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip4( rStream );
	FBufferHelpers::Skip4( rStream );

	FBufferHelpers::ReadObject( Count, rStream );

	Objects.resize( Count );

	for( auto& rObject : Objects )
	{
		FBufferHelpers::ReadObject( rObject.ModelID, rStream );
		FBufferHelpers::ReadObject( rObject.ObjectReference, rStream );
		FBufferHelpers::ReadObject( rObject.Position, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_0__, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_1__, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_2__, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_3__, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_4__, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_5__, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_6__, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_7__, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_8__, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_9__, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_10__, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_11__, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_12__, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_13__, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_14__, rStream );
	}

	return true;
}
