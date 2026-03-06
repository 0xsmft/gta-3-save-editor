#include "sppch.h"
#include "Garages.h"

#include "Core/BufferHelpers.h"

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

void FStoredCar::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( ModelID, rStream );
	FBufferHelpers::WriteObject( Position, rStream );
	FBufferHelpers::WriteObject( Rotation, rStream );
	FBufferHelpers::WriteObject( Immunities, rStream );
	FBufferHelpers::WriteObject( PrimaryColorID, rStream );
	FBufferHelpers::WriteObject( SecondaryColorID, rStream );
	FBufferHelpers::WriteObject( RadioStationID, rStream );
	FBufferHelpers::WriteObject( ModelVariationA, rStream );
	FBufferHelpers::WriteObject( ModelVariationB, rStream );
	FBufferHelpers::WriteObject( BombTypeID, rStream );

	FBufferHelpers::WriteN( rStream, 2 );
}

//////////////////////////////////////////////////////////////////////////

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

void FGarages::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( 5488u, rStream );
	FBufferHelpers::WriteObject( 5484u, rStream );

	FBufferHelpers::WriteObject( Count, rStream );
	FBufferHelpers::WriteObject( BombsAreFree, rStream );

	FBufferHelpers::WriteN( rStream, 3 );

	FBufferHelpers::WriteObject( RespraysAreFree, rStream );

	FBufferHelpers::WriteN( rStream, 3 );

	FBufferHelpers::WriteObject( CarsCollected, rStream );
	FBufferHelpers::WriteObject( BankVansCollected, rStream );
	FBufferHelpers::WriteObject( PoliceCarsCollected, rStream );

	FBufferHelpers::WriteObject( PortlandIEStatus, rStream );
	FBufferHelpers::WriteObject( ShoresideIEStatus, rStream );
	FBufferHelpers::WriteObject( UnusedIEStatus, rStream );

	FBufferHelpers::WriteObject( TimeGA21WasShown, rStream );

	for( uint32_t Index = 0; Index < StoredCars.size(); Index++ )
	{
		StoredCars[ Index ].Write( rStream );
	}

	for( uint32_t Index = 0; Index < 32; Index++ )
	{
		FBufferHelpers::WriteObject( Garages[ Index ].TypeID, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].State, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].__unknown_0__, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].ClosingWithoutTargetCar, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].Deactivated, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].ResprayHappenend, rStream );

		FBufferHelpers::WriteN( rStream, 2 );

		FBufferHelpers::WriteObject( Garages[ Index ].TargetVehicleModelIdx, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].Door1Ptr, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].Door2Ptr, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].IsDoor1PoolIndex, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].IsDoor2PoolIndex, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].IsDoor1Object, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].IsDoor2Object, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].__unknown_1__, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].RotatedDoor, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].CameraFollowsPlayer, rStream );

		FBufferHelpers::WriteN( rStream, 1 );

		FBufferHelpers::WriteObject( Garages[ Index ].X1, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].X2, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].Y1, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].Y2, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].Z1, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].Z2, rStream );

		FBufferHelpers::WriteObject( Garages[ Index ].DoorPosition, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].DoorHeight, rStream );

		FBufferHelpers::WriteObject( Garages[ Index ].DoorX1, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].DoorY1, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].DoorX2, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].DoorY2, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].DoorZ1, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].DoorZ2, rStream );

		FBufferHelpers::WriteObject( Garages[ Index ].LastOpenTime, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].CollectedCars, rStream );

		FBufferHelpers::WriteN( rStream, 3 );

		FBufferHelpers::WriteObject( Garages[ Index ].TargetVehiclePtr, rStream );
		FBufferHelpers::WriteObject( Garages[ Index ].__unknown_2__, rStream );

		Garages[ Index ].StoredCar.Write( rStream );
	}

	FBufferHelpers::WriteN( rStream, ( uint8_t ) 244 );
}

//////////////////////////////////////////////////////////////////////////

static std::unordered_map<uint32_t, std::string_view> s_VehicleModelIDToName
{
	{ 90u, "Landstalker" },
	{ 91u, "Idaho" },
	{ 92u, "Stinger" },
	{ 93u, "Linerunner" },
	{ 94u, "Perennial" },
	{ 95u, "Sentinel" },
	{ 96u, "Patriot" },
	{ 97u, "Firetruck" },
	{ 98u, "Trashmaster" },
	{ 99u, "Stretch" },
	{ 100u, "Manana" },
	{ 101u, "Infernus" },
	{ 102u, "Blista" },
	{ 103u, "Pony" },
	{ 104u, "Mule" },
	{ 105u, "Cheetah" },
	{ 106u, "Ambulance" },
	{ 107u, "Fbi Car" },
	{ 108u, "Moonbeam" },
	{ 109u, "Esperanto" },
	{ 110u, "Taxi" },
	{ 111u, "Kuruma" },
	{ 112u, "Bobcat" },
	{ 113u, "Mr Whoopee" },
	{ 114u, "BF Injection" },
	{ 115u, "Manana" },
	{ 116u, "Police" },
	{ 117u, "Enforcer" },
	{ 118u, "Securicar" },
	{ 119u, "Banshee" },
	{ 120u, "Predator" },
	{ 121u, "Bus" },
	{ 122u, "Rhino" },
	{ 123u, "Barracks OL" },
	{ 124u, "Train" },
	{ 125u, "Helicopter" },
	{ 126u, "Dodo" },
	{ 127u, "Coach" },
	{ 128u, "Cabbie" },
	{ 129u, "Stallion" },
	{ 130u, "Rumpo" },
	{ 131u, "RC Bandit" },
	{ 132u, "Triad Fish Van" },
	{ 133u, "Mr Wongs" },
	{ 134u, "Mafia Sentinel" },
	{ 135u, "Yardie Lobo" },
	{ 136u, "Yakuza Stinger" },
	{ 137u, "Diablo Stallion" },
	{ 138u, "Cartel Cruiser" },
	{ 139u, "Hoods Rumpo XL" },
	{ 140u, "Aeroplane" },
	{ 141u, "Dodo" },
	{ 142u, "Speeder"	 },
	{ 143u, "Reefer" },
	{ 144u, "Panlantic" },
	{ 145u, "Flatbed"	 },
	{ 146u, "Yankee" },
	{ 147u, "Helicopter" },
	{ 148u, "Borgnine" },
	{ 149u, "TOYZ" },
	{ 150u, "Ghost" }
};

std::string_view VehicleModelIDToString( uint32_t ModelID )
{
	const auto itr = s_VehicleModelIDToName.find( ModelID );
	if( itr != s_VehicleModelIDToName.end() )
	{
		return itr->second;
	}

	return "<NULL>";
}

static std::unordered_map< uint8_t, std::string_view > s_VehicleColorIDToString
{ 
	{ -1, "Random" },
	{ 0, "Metallic Black" },
	{ 1, "Metallic Graphite Black" },
	{ 2, "Metallic Black Steal" },
	{ 3, "Metallic Dark Silver" },
	{ 4, "Metallic Silver" },
	{ 5, "Metallic Blue Silver" },
	{ 6, "Metallic Steel Gray" },
	{ 7, "Metallic Shadow Silver" },
	{ 8, "Metallic Stone Silver" },
	{ 9, "Metallic Midnight Silver" },
	{ 10, "Metallic Gun Metal" },
	{ 11, "Metallic Anthracite Grey" },
	{ 12, "Matte Black" },
	{ 13, "Matte Gray" },
	{ 14, "Matte Light Grey" },
	{ 15, "Util Black" },
	{ 16, "Util Black Poly" },
	{ 17, "Util Dark silver" },
	{ 18, "Util Silver" },
	{ 19, "Util Gun Metal" },
	{ 20, "Util Shadow Silver" },
	{ 21, "Worn Black" },
	{ 22, "Worn Graphite" },
	{ 23, "Worn Silver Grey" },
	{ 24, "Worn Silver" },
	{ 25, "Worn Blue Silver" },
	{ 26, "Worn Shadow Silver" },
	{ 27, "Metallic Red" },
	{ 28, "Metallic Torino Red" },
	{ 29, "Metallic Formula Red" },
	{ 30, "Metallic Blaze Red" },
	{ 31, "Metallic Graceful Red" },
	{ 32, "Metallic Garnet Red" },
	{ 33, "Metallic Desert Red" },
	{ 34, "Metallic Cabernet Red" },
	{ 35, "Metallic Candy Red" },
	{ 36, "Metallic Sunrise Orange" },
	{ 37, "Metallic Classic Gold" },
	{ 38, "Metallic Orange" },
	{ 39, "Matte Red" },
	{ 40, "Matte Dark Red" },
	{ 41, "Matte Orange" },
	{ 42, "Matte Yellow" },
	{ 43, "Util Red" },
	{ 44, "Util Bright Red" },
	{ 45, "Util Garnet Red" },
	{ 46, "Worn Red" },
	{ 47, "Worn Golden Red" },
	{ 48, "Worn Dark Red" },
	{ 49, "Metallic Dark Green" },
	{ 50, "Metallic Racing Green" },
	{ 51, "Metallic Sea Green" },
	{ 52, "Metallic Olive Green" },
	{ 53, "Metallic Green" },
	{ 54, "Metallic Gasoline Blue Green" },
	{ 55, "Matte Lime Green" },
	{ 56, "Util Dark Green" },
	{ 57, "Util Green" },
	{ 58, "Worn Dark Green" },
	{ 59, "Worn Green" },
	{ 60, "Worn Sea Wash" },
	{ 61, "Metallic Midnight Blue" },
	{ 62, "Metallic Dark Blue" },
	{ 63, "Metallic Saxony Blue" },
	{ 64, "Metallic Blue" },
	{ 65, "Metallic Mariner Blue" },
	{ 66, "Metallic Harbor Blue" },
	{ 67, "Metallic Diamond Blue" },
	{ 68, "Metallic Surf Blue" },
	{ 69, "Metallic Nautical Blue" },
	{ 70, "Metallic Bright Blue" },
	{ 71, "Metallic Purple Blue" },
	{ 72, "Metallic Spinnaker Blue" },
	{ 73, "Metallic Ultra Blue" },
	{ 74, "Metallic Bright Blue" },
	{ 75, "Util Dark Blue" },
	{ 76, "Util Midnight Blue" },
	{ 77, "Util Blue" },
	{ 78, "Util Sea Foam Blue" },
	{ 79, "Uil Lightning blue" },
	{ 80, "Util Maui Blue Poly" },
	{ 81, "Util Bright Blue" },
	{ 82, "Matte Dark Blue" },
	{ 83, "Matte Blue" },
	{ 84, "Matte Midnight Blue" },
	{ 85, "Worn Dark blue" },
	{ 86, "Worn Blue" },
	{ 87, "Worn Light blue" },
	{ 88, "Metallic Taxi Yellow" },
	{ 89, "Metallic Race Yellow" },
	{ 90, "Metallic Bronze" },
	{ 91, "Metallic Yellow Bird" },
	{ 92, "Metallic Lime" },
	{ 93, "Metallic Champagne" },
	{ 94, "Metallic Pueblo Beige" },
	{ 95, "Metallic Dark Ivory" },
	{ 96, "Metallic Choco Brown" },
	{ 97, "Metallic Golden Brown" },
	{ 98, "Metallic Light Brown" },
	{ 99, "Metallic Straw Beige" },
	{ 100, "Metallic Moss Brown" },
	{ 101, "Metallic Biston Brown" },
	{ 102, "Metallic Beechwood" },
	{ 103, "Metallic Dark Beechwood" },
	{ 104, "Metallic Choco Orange" },
	{ 105, "Metallic Beach Sand" },
	{ 106, "Metallic Sun Bleeched Sand" },
	{ 107, "Metallic Cream" },
	{ 108, "Util Brown" },
	{ 109, "Util Medium Brown" },
	{ 110, "Util Light Brown" },
	{ 111, "Metallic White" },
	{ 112, "Metallic Frost White" },
	{ 113, "Worn Honey Beige" },
	{ 114, "Worn Brown" },
	{ 115, "Worn Dark Brown" },
	{ 116, "Worn straw beige" },
	{ 117, "Brushed Steel" },
	{ 118, "Brushed Black steel" },
	{ 119, "Brushed Aluminium" },
	{ 120, "Chrome" },
	{ 121, "Worn Off White" },
	{ 122, "Util Off White" },
	{ 123, "Worn Orange" },
	{ 124, "Worn Light Orange" },
	{ 125, "Metallic Securicor Green" },
	{ 126, "Worn Taxi Yellow" },
	{ 127, "police car blue" },
	{ 128, "Matte Green" },
	{ 129, "Matte Brown" },
	{ 130, "Worn Orange" },
	{ 131, "Matte White" },
	{ 132, "Worn White" },
	{ 133, "Worn Olive Army Green" },
	{ 134, "Pure White" },
	{ 135, "Hot Pink" },
	{ 136, "Salmon pink" },
	{ 137, "Metallic Vermillion Pink" },
	{ 138, "Orange" },
	{ 139, "Green" },
	{ 140, "Blue" },
	{ 141, "Mettalic Black Blue" },
	{ 142, "Metallic Black Purple" },
	{ 143, "Metallic Black Red" },
	{ 144, "hunter green" },
	{ 145, "Metallic Purple" },
	{ 146, "Metaillic V Dark Blue" },
	{ 147, "MODSHOP BLACK1" },
	{ 148, "Matte Purple" },
	{ 149, "Matte Dark Purple" },
	{ 150, "Metallic Lava Red" },
	{ 151, "Matte Forest Green" },
	{ 152, "Matte Olive Drab" },
	{ 153, "Matte Desert Brown" },
	{ 154, "Matte Desert Tan" },
	{ 155, "Matte Foilage Green" },
	{ 156, "DEFAULT ALLOY COLOR" },
	{ 157, "Epsilon Blue" },
};

std::string_view VehicleColorIDToString( uint8_t ColorID )
{
	const auto itr = s_VehicleColorIDToString.find( ColorID );
	if( itr != s_VehicleColorIDToString.end() )
	{
		return itr->second;
	}

	return "<NULL>";
}
