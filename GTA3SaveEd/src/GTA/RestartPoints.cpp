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

void FRestartInfo::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( 296u, rStream );
	FBufferHelpers::WriteObject( 292u, rStream );
	
	FBufferHelpers::WriteBlockHeader( rStream, "RST", 284u );

	for( auto& rHospitalRp : HospitalRestartPoints )
	{
		FBufferHelpers::WriteObject( rHospitalRp, rStream );
	}

	for( auto& rPoliceRp : PoliceRestartPoints )
	{
		FBufferHelpers::WriteObject( rPoliceRp, rStream );
	}

	FBufferHelpers::WriteObject( NumberOfHospitalRestarts, rStream );
	FBufferHelpers::WriteObject( NumberOfPoliceRestarts, rStream );

	FBufferHelpers::WriteObject( OverrideRestart, rStream );
	FBufferHelpers::WriteN( rStream, 3 );

	FBufferHelpers::WriteObject( Override, rStream );

	FBufferHelpers::WriteObject( FadeInAfterNextDeath, rStream );
	FBufferHelpers::WriteObject( FadeInAfterNextArrest, rStream );
	FBufferHelpers::WriteObject( OverrideHospitalLevel, rStream );
	FBufferHelpers::WriteObject( OverridePoliceLevel, rStream );
}
