#include "sppch.h"
#include "Objects.h"

#include "Base/BufferHelpers.h"

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
