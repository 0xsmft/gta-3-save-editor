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

void FCranes::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( 1036u, rStream );
	FBufferHelpers::WriteObject( 1032u, rStream );

	FBufferHelpers::WriteObject( NumberOfCranes, rStream );
	FBufferHelpers::WriteObject( CarsCollectedByMilitaryCare, rStream );

	for( auto& rCrane : Cranes )
	{
		FBufferHelpers::WriteObject( rCrane.Index, rStream );
		FBufferHelpers::WriteObject( rCrane.HookIndex, rStream );
		FBufferHelpers::WriteObject( rCrane.AudioEntityIndex, rStream );

		FBufferHelpers::WriteObject( rCrane.PickupZoneX1, rStream );
		FBufferHelpers::WriteObject( rCrane.PickupZoneX2, rStream );
		FBufferHelpers::WriteObject( rCrane.PickupZoneY1, rStream );
		FBufferHelpers::WriteObject( rCrane.PickupZoneY2, rStream );

		FBufferHelpers::WriteObject( rCrane.DropOffPoint, rStream );

		FBufferHelpers::WriteObject( rCrane.DropOffHeadingRad, rStream );
		FBufferHelpers::WriteObject( rCrane.ArmPickUpRotRad, rStream );
		FBufferHelpers::WriteObject( rCrane.ArmDropOffRotRad, rStream );
		FBufferHelpers::WriteObject( rCrane.ArmPickUpDistFromCenter, rStream );
		FBufferHelpers::WriteObject( rCrane.ArmDropOffDistFromCenter, rStream );
		FBufferHelpers::WriteObject( rCrane.ArmPickUpHeight, rStream );
		FBufferHelpers::WriteObject( rCrane.ArmDropOffHeight, rStream );
		FBufferHelpers::WriteObject( rCrane.ArmCurrentRotationRad, rStream );
		FBufferHelpers::WriteObject( rCrane.ArmDistanceFromCenter, rStream );
		FBufferHelpers::WriteObject( rCrane.ArmCurrentHeight, rStream );

		FBufferHelpers::WriteObject( rCrane.InitialPosition, rStream );
		FBufferHelpers::WriteObject( rCrane.HookCurrentXYZ, rStream );
		FBufferHelpers::WriteObject( rCrane.HookVelocity, rStream );

		FBufferHelpers::WriteObject( rCrane.VehPickupPtr, rStream );
		FBufferHelpers::WriteObject( rCrane.CurrentGameTime, rStream );

		FBufferHelpers::WriteObject( rCrane.Activity, rStream );
		FBufferHelpers::WriteObject( rCrane.Status, rStream );

		FBufferHelpers::WriteObject( rCrane.NumberOfVehiclesCollected, rStream );
		FBufferHelpers::WriteObject( rCrane.IsCrusherCrane, rStream );
		FBufferHelpers::WriteObject( rCrane.IsMilitaryCare, rStream );
		FBufferHelpers::WriteObject( rCrane.__unknown_1__, rStream );
		FBufferHelpers::WriteObject( rCrane.ModelIsNotDoc_Crane_Cab, rStream );

		FBufferHelpers::WriteByte( rStream );
	}
}
