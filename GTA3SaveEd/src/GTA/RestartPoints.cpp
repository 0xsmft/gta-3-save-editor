#include "sppch.h"
#include "RestartPoints.h"

#include "Core/BufferHelpers.h"

bool FRestartInfo::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );

	FBufferHelpers::ReadBlockHeader( rStream, "RST" );

	for( auto& rHospitalRp : HospitalRestartPoints )
	{
		FBufferHelpers::ReadObject( rHospitalRp, rStream );
	}

	for( auto& rPoliceRp : PoliceRestartPoints )
	{
		FBufferHelpers::ReadObject( rPoliceRp, rStream );
	}

	FBufferHelpers::ReadObject( NumberOfHospitalRestarts, rStream );
	FBufferHelpers::ReadObject( NumberOfPoliceRestarts, rStream );

	FBufferHelpers::ReadObject( OverrideRestart, rStream );
	FBufferHelpers::SkipN( rStream, 3 );

	FBufferHelpers::ReadObject( Override, rStream );

	FBufferHelpers::ReadObject( FadeInAfterNextDeath, rStream );
	FBufferHelpers::ReadObject( FadeInAfterNextArrest, rStream );
	FBufferHelpers::ReadObject( OverrideHospitalLevel, rStream );
	FBufferHelpers::ReadObject( OverridePoliceLevel, rStream );

	return true;
}
