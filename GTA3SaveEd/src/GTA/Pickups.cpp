#include "sppch.h"
#include "Pickups.h"

#include "Core/BufferHelpers.h"

bool FPickups::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );

	for( auto& rPickup : Pickups )
	{
		FBufferHelpers::ReadObject( rPickup.Type, rStream );
		FBufferHelpers::ReadObject( rPickup.HasBeenPickedUp, rStream );
		FBufferHelpers::ReadObject( rPickup.Ammo, rStream );
		FBufferHelpers::ReadObject( rPickup.PoolIndex, rStream );
		FBufferHelpers::ReadObject( rPickup.RegenTime, rStream );
		FBufferHelpers::ReadObject( rPickup.ModelID, rStream );
		FBufferHelpers::ReadObject( rPickup.Index, rStream );
		FBufferHelpers::ReadObject( rPickup.Position, rStream );
	}

	FBufferHelpers::ReadObject( CollectedPickupIndex, rStream );
	FBufferHelpers::ReadObject( __unknown_0__, rStream );

	for( uint32_t Index = 0; Index < PickupsCollected.size(); ++Index )
	{
		FBufferHelpers::ReadObject( PickupsCollected[ Index ], rStream );
	}

	return true;
}
