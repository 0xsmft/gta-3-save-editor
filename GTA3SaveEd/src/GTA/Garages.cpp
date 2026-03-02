#include "sppch.h"
#include "Garages.h"

#include "Base/BufferHelpers.h"

bool FStoredCar::Read( std::ifstream& rStream )
{
	FBufferHelpers::ReadObject( ModelID, rStream );
	FBufferHelpers::ReadObject( Position, rStream );
	FBufferHelpers::ReadObject( Rotation, rStream );
	FBufferHelpers::ReadObject( Immunities, rStream );
	FBufferHelpers::ReadObject( PrimaryColorID, rStream );
	FBufferHelpers::ReadObject( SecondaryColorID, rStream );
	FBufferHelpers::ReadObject( RadioStationID, rStream );
	FBufferHelpers::ReadObject( ModelVariationA, rStream );
	FBufferHelpers::ReadObject( ModelVariationB, rStream );
	FBufferHelpers::ReadObject( BombTypeID, rStream );

	FBufferHelpers::Skip2( rStream );

	return true;
}

bool FGarages::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );

	FBufferHelpers::ReadObject( Count, rStream );
	FBufferHelpers::ReadObject( BombsAreFree, rStream );

	FBufferHelpers::SkipByte( rStream );
	FBufferHelpers::Skip2( rStream );

	FBufferHelpers::ReadObject( RespraysAreFree, rStream );

	FBufferHelpers::SkipByte( rStream );
	FBufferHelpers::Skip2( rStream );

	FBufferHelpers::ReadObject( CarsCollected, rStream );
	FBufferHelpers::ReadObject( BankVansCollected, rStream );
	FBufferHelpers::ReadObject( PoliceCarsCollected, rStream );

	FBufferHelpers::ReadObject( PortlandIEStatus, rStream );
	FBufferHelpers::ReadObject( ShoresideIEStatus, rStream );
	FBufferHelpers::ReadObject( UnusedIEStatus, rStream );

	FBufferHelpers::ReadObject( TimeGA21WasShown, rStream );

	for( uint32_t Index = 0; Index < StoredCars.size(); Index++ )
	{
		StoredCars[ Index ].Read( rStream );
	}

	Garages.resize( 32 );

	for( uint32_t Index = 0; Index < 32; Index++ )
	{
		FBufferHelpers::ReadObject( Garages[ Index ].TypeID, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].State, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].__unknown_0__, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].ClosingWithoutTargetCar, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].Deactivated, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].ResprayHappenend, rStream );

		FBufferHelpers::Skip2( rStream );

		FBufferHelpers::ReadObject( Garages[ Index ].TargetVehicleModelIdx, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].Door1Ptr, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].Door2Ptr, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].IsDoor1PoolIndex, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].IsDoor2PoolIndex, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].IsDoor1Object, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].IsDoor2Object, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].__unknown_1__, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].RotatedDoor, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].CameraFollowsPlayer, rStream );

		FBufferHelpers::SkipByte( rStream );

		FBufferHelpers::ReadObject( Garages[ Index ].X1, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].X2, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].Y1, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].Y2, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].Z1, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].Z2, rStream );

		FBufferHelpers::ReadObject( Garages[ Index ].DoorPosition, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].DoorHeight, rStream );

		FBufferHelpers::ReadObject( Garages[ Index ].DoorX1, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].DoorY1, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].DoorX2, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].DoorY2, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].DoorZ1, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].DoorZ2, rStream );

		FBufferHelpers::ReadObject( Garages[ Index ].LastOpenTime, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].CollectedCars, rStream );

		FBufferHelpers::SkipByte( rStream );
		FBufferHelpers::Skip2( rStream );

		FBufferHelpers::ReadObject( Garages[ Index ].TargetVehiclePtr, rStream );
		FBufferHelpers::ReadObject( Garages[ Index ].__unknown_2__, rStream );

		Garages[ Index ].StoredCar.Read( rStream );
	}

	FBufferHelpers::SkipN( rStream, 244 );

	return true;
}
