#include "sppch.h"
#include "PlayerInfo.h"

#include "Core/BufferHelpers.h"

bool FPlayerInfo::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );

	FBufferHelpers::ReadObject( Money, rStream );
	FBufferHelpers::ReadObject( WastedBustedState, rStream );
	FBufferHelpers::ReadObject( WastedBustedTime, rStream );
	FBufferHelpers::ReadObject( TrafficMultiplier, rStream );
	FBufferHelpers::ReadObject( RoadDensity, rStream );
	FBufferHelpers::ReadObject( MoneyOnScreen, rStream );
	FBufferHelpers::ReadObject( CollectedHiddenPackages, rStream );
	FBufferHelpers::ReadObject( TotalHiddenPackages, rStream );
	FBufferHelpers::ReadObject( InfiniteSprint, rStream );
	FBufferHelpers::ReadObject( FastReload, rStream );
	FBufferHelpers::ReadObject( GetOutOfJailFree, rStream );
	FBufferHelpers::ReadObject( GetOutOfHospitalFree, rStream );
	FBufferHelpers::ReadObject( PlayerName, rStream );

	FBufferHelpers::SkipN( rStream, 215 );

	return true;
}

void FPlayerInfo::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( 320u, rStream );
	FBufferHelpers::WriteObject( 316u, rStream );

	FBufferHelpers::WriteObject( Money, rStream );
	FBufferHelpers::WriteObject( WastedBustedState, rStream );
	FBufferHelpers::WriteObject( WastedBustedTime, rStream );
	FBufferHelpers::WriteObject( TrafficMultiplier, rStream );
	FBufferHelpers::WriteObject( RoadDensity, rStream );
	FBufferHelpers::WriteObject( MoneyOnScreen, rStream );
	FBufferHelpers::WriteObject( CollectedHiddenPackages, rStream );
	FBufferHelpers::WriteObject( TotalHiddenPackages, rStream );
	FBufferHelpers::WriteObject( InfiniteSprint, rStream );
	FBufferHelpers::WriteObject( FastReload, rStream );
	FBufferHelpers::WriteObject( GetOutOfJailFree, rStream );
	FBufferHelpers::WriteObject( GetOutOfHospitalFree, rStream );
	FBufferHelpers::WriteObject( PlayerName, rStream );

	FBufferHelpers::WriteN( rStream, 215 );
}
