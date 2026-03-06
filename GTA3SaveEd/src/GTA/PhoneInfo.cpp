#include "sppch.h"
#include "PhoneInfo.h"

#include "Core/BufferHelpers.h"

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

void FPhones::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( 2612u, rStream );
	FBufferHelpers::WriteObject( 2608u, rStream );
	
	FBufferHelpers::WriteObject( NumPhones, rStream );
	FBufferHelpers::WriteObject( NumActivePhones, rStream );

	for( auto& rPhone : Phones )
	{
		FBufferHelpers::WriteObject( rPhone.Position, rStream );
		FBufferHelpers::WriteObject( rPhone.Messages, rStream );
		FBufferHelpers::WriteObject( rPhone.RepeatedMessageStartTime, rStream );
		FBufferHelpers::WriteObject( rPhone.Handle, rStream );
		FBufferHelpers::WriteObject( rPhone.PhoneState, rStream );
		FBufferHelpers::WriteObject( rPhone.VisibleToCam, rStream );

		FBufferHelpers::WriteN( rStream, 3 );
	}
}
