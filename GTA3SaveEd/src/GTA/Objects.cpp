#include "sppch.h"
#include "Objects.h"

#include "Core/BufferHelpers.h"

bool FObjects::Read( std::ifstream& rStream )
{
	uint32_t temp4 = 0u;
	FBufferHelpers::ReadObject( temp4, rStream );
	FBufferHelpers::ReadObject( temp4, rStream );

	FBufferHelpers::ReadObject( Count, rStream );

	Objects.resize( Count );

	for( auto& rObject : Objects )
	{
		FBufferHelpers::ReadObject( rObject.ModelID, rStream );
		FBufferHelpers::ReadObject( rObject.ObjectReference, rStream );
		
		FBufferHelpers::ReadObject( rObject.Matrix, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_0__, rStream );
		FBufferHelpers::ReadObject( rObject.UproofLimit, rStream );
		FBufferHelpers::ReadObject( rObject.ObjectMatrix, rStream );
		FBufferHelpers::ReadObject( rObject.__unknown_1__, rStream );
		FBufferHelpers::ReadObject( rObject.ObjectCreatedBy, rStream );
		FBufferHelpers::ReadObject( rObject.IsPickup, rStream );
		FBufferHelpers::ReadObject( rObject.IsPickupInShop, rStream );
		FBufferHelpers::ReadObject( rObject.IsGlassCracked, rStream );

		FBufferHelpers::ReadObject( rObject.IsGlassBroken, rStream );
		FBufferHelpers::ReadObject( rObject.HasBeenDamaged, rStream );

		FBufferHelpers::Skip2( rStream );

		FBufferHelpers::ReadObject( rObject.CollisionDmgMultiplier, rStream );
		FBufferHelpers::ReadObject( rObject.CollisionDamageEffect, rStream );
		FBufferHelpers::ReadObject( rObject.SpecialCollisionResponseCase, rStream );
		
		FBufferHelpers::ReadObject( rObject.EndOfLifeTime, rStream );
		FBufferHelpers::ReadObject( rObject.FlagsA, rStream );
		FBufferHelpers::ReadObject( rObject.FlagsB, rStream );
	}

	return true;
}

void FObjects::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( 23864u, rStream );
	FBufferHelpers::WriteObject( 23860u, rStream );

	FBufferHelpers::WriteObject( Count, rStream );

	for( auto& rObject : Objects )
	{
		FBufferHelpers::WriteObject( rObject.ModelID, rStream );
		FBufferHelpers::WriteObject( rObject.ObjectReference, rStream );

		FBufferHelpers::WriteObject( rObject.Matrix, rStream );
		FBufferHelpers::WriteObject( rObject.__unknown_0__, rStream );
		FBufferHelpers::WriteObject( rObject.UproofLimit, rStream );
		FBufferHelpers::WriteObject( rObject.ObjectMatrix, rStream );
		FBufferHelpers::WriteObject( rObject.__unknown_1__, rStream );
		FBufferHelpers::WriteObject( rObject.ObjectCreatedBy, rStream );
		FBufferHelpers::WriteObject( rObject.IsPickup, rStream );
		FBufferHelpers::WriteObject( rObject.IsPickupInShop, rStream );
		FBufferHelpers::WriteObject( rObject.IsGlassCracked, rStream );

		FBufferHelpers::WriteObject( rObject.IsGlassBroken, rStream );
		FBufferHelpers::WriteObject( rObject.HasBeenDamaged, rStream );

		FBufferHelpers::WriteN( rStream, 2 );

		FBufferHelpers::WriteObject( rObject.CollisionDmgMultiplier, rStream );
		FBufferHelpers::WriteObject( rObject.CollisionDamageEffect, rStream );
		FBufferHelpers::WriteObject( rObject.SpecialCollisionResponseCase, rStream );

		FBufferHelpers::WriteObject( rObject.EndOfLifeTime, rStream );
		FBufferHelpers::WriteObject( rObject.FlagsA, rStream );
		FBufferHelpers::WriteObject( rObject.FlagsB, rStream );
	}
}
