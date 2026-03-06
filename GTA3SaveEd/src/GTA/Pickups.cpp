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

void FPickups::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( 9496u, rStream );
	FBufferHelpers::WriteObject( 9492u, rStream );

	for( auto& rPickup : Pickups )
	{
		FBufferHelpers::WriteObject( rPickup.Type, rStream );
		FBufferHelpers::WriteObject( rPickup.HasBeenPickedUp, rStream );
		FBufferHelpers::WriteObject( rPickup.Ammo, rStream );
		FBufferHelpers::WriteObject( rPickup.PoolIndex, rStream );
		FBufferHelpers::WriteObject( rPickup.RegenTime, rStream );
		FBufferHelpers::WriteObject( rPickup.ModelID, rStream );
		FBufferHelpers::WriteObject( rPickup.Index, rStream );
		FBufferHelpers::WriteObject( rPickup.Position, rStream );
	}

	FBufferHelpers::WriteObject( CollectedPickupIndex, rStream );
	FBufferHelpers::WriteObject( __unknown_0__, rStream );

	for( uint32_t Index = 0; Index < PickupsCollected.size(); ++Index )
	{
		FBufferHelpers::WriteObject( PickupsCollected[ Index ], rStream );
	}
}
