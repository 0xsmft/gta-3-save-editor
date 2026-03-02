#include "sppch.h"
#include "PlayerInfo.h"

#include "Base/BufferHelpers.h"

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
