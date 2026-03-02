#include "sppch.h"
#include "PhoneInfo.h"

#include "Base/BufferHelpers.h"

bool FPhones::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );

	FBufferHelpers::ReadObject( NumPhones, rStream );
	FBufferHelpers::ReadObject( NumActivePhones, rStream );

	Phones.resize( NumPhones + 1 );

	for( auto& rPhone : Phones )
	{
		FBufferHelpers::ReadObject( rPhone.Position, rStream );
		FBufferHelpers::ReadObject( rPhone.Messages, rStream );
		FBufferHelpers::ReadObject( rPhone.RepeatedMessageStartTime, rStream );
		FBufferHelpers::ReadObject( rPhone.Handle, rStream );
		FBufferHelpers::ReadObject( rPhone.PhoneState, rStream );
		FBufferHelpers::ReadObject( rPhone.VisibleToCam, rStream );

		FBufferHelpers::SkipN( rStream, 3 );
	}

	return true;
}
