#include "sppch.h"
#include "Cranes.h"

#include "Core/BufferHelpers.h"

bool FCranes::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );

	FBufferHelpers::ReadObject( NumberOfCranes, rStream );
	FBufferHelpers::ReadObject( CarsCollectedByMilitaryCare, rStream );

	for( auto& rCrane : Cranes )
	{
		FBufferHelpers::ReadObject( rCrane.Index, rStream );
		FBufferHelpers::ReadObject( rCrane.HookIndex, rStream );
		FBufferHelpers::ReadObject( rCrane.AudioEntityIndex, rStream );

		FBufferHelpers::ReadObject( rCrane.PickupZoneX1, rStream );
		FBufferHelpers::ReadObject( rCrane.PickupZoneX2, rStream );
		FBufferHelpers::ReadObject( rCrane.PickupZoneY1, rStream );
		FBufferHelpers::ReadObject( rCrane.PickupZoneY2, rStream );

		FBufferHelpers::ReadObject( rCrane.DropOffPoint, rStream );

		FBufferHelpers::ReadObject( rCrane.DropOffHeadingRad, rStream );
		FBufferHelpers::ReadObject( rCrane.ArmPickUpRotRad, rStream );
		FBufferHelpers::ReadObject( rCrane.ArmDropOffRotRad, rStream );
		FBufferHelpers::ReadObject( rCrane.ArmPickUpDistFromCenter, rStream );
		FBufferHelpers::ReadObject( rCrane.ArmDropOffDistFromCenter, rStream );
		FBufferHelpers::ReadObject( rCrane.ArmPickUpHeight, rStream );
		FBufferHelpers::ReadObject( rCrane.ArmDropOffHeight, rStream );
		FBufferHelpers::ReadObject( rCrane.ArmCurrentRotationRad, rStream );
		FBufferHelpers::ReadObject( rCrane.ArmDistanceFromCenter, rStream );
		FBufferHelpers::ReadObject( rCrane.ArmCurrentHeight, rStream );

		FBufferHelpers::ReadObject( rCrane.InitialPosition, rStream );
		FBufferHelpers::ReadObject( rCrane.HookCurrentXYZ, rStream );
		FBufferHelpers::ReadObject( rCrane.HookVelocity, rStream );

		FBufferHelpers::ReadObject( rCrane.VehPickupPtr, rStream );
		FBufferHelpers::ReadObject( rCrane.CurrentGameTime, rStream );
		
		FBufferHelpers::ReadObject( rCrane.Activity, rStream );
		FBufferHelpers::ReadObject( rCrane.Status, rStream );

		FBufferHelpers::ReadObject( rCrane.NumberOfVehiclesCollected, rStream );
		FBufferHelpers::ReadObject( rCrane.IsCrusherCrane, rStream );
		FBufferHelpers::ReadObject( rCrane.IsMilitaryCare, rStream );
		FBufferHelpers::ReadObject( rCrane.__unknown_1__, rStream );
		FBufferHelpers::ReadObject( rCrane.ModelIsNotDoc_Crane_Cab, rStream );

		FBufferHelpers::SkipByte( rStream );
	}

	return true;
}
