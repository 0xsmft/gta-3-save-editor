#include "sppch.h"
#include "PlayerPeds.h"

#include "Core/BufferHelpers.h"

bool FPlayerPeds::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );

	uint32_t playerCount = 0;
	FBufferHelpers::ReadObject( playerCount, rStream );

	PlayerPeds.resize( playerCount );

	for( auto& rPlayerPed : PlayerPeds )
	{
		FBufferHelpers::ReadObject( rPlayerPed.___unknown_0__, rStream );
		FBufferHelpers::ReadObject( rPlayerPed.___unknown_1__, rStream );
		FBufferHelpers::ReadObject( rPlayerPed.___unknown_2__, rStream );
		FBufferHelpers::ReadObject( rPlayerPed.CPed.___unknown_0__, rStream );
		FBufferHelpers::ReadObject( rPlayerPed.CPed.XYZ[ 0 ], rStream );
		FBufferHelpers::ReadObject( rPlayerPed.CPed.XYZ[ 1 ], rStream );
		FBufferHelpers::ReadObject( rPlayerPed.CPed.XYZ[ 2 ], rStream );
		FBufferHelpers::ReadObject( rPlayerPed.CPed.___unknown_1__, rStream );
		FBufferHelpers::ReadObject( rPlayerPed.CPed.Health, rStream );
		FBufferHelpers::ReadObject( rPlayerPed.CPed.Armour, rStream );
		FBufferHelpers::ReadObject( rPlayerPed.CPed.___unknown_2__, rStream );

		for( uint32_t Index = 0; Index < rPlayerPed.CPed.Weapons.size(); Index++ )
		{
			FBufferHelpers::ReadObject( rPlayerPed.CPed.Weapons[ Index ].WeaponID, rStream );
			FBufferHelpers::ReadObject( rPlayerPed.CPed.Weapons[ Index ].___unknown_0__, rStream );
			FBufferHelpers::ReadObject( rPlayerPed.CPed.Weapons[ Index ].BulletsInMag, rStream );
			FBufferHelpers::ReadObject( rPlayerPed.CPed.Weapons[ Index ].BulletsInTotal, rStream );
			FBufferHelpers::ReadObject( rPlayerPed.CPed.Weapons[ Index ].___unknown_1__, rStream );
			FBufferHelpers::ReadObject( rPlayerPed.CPed.Weapons[ Index ].___unknown_2__, rStream );
		}

		FBufferHelpers::ReadObject( rPlayerPed.CPed.___unknown_3__, rStream );

		FBufferHelpers::ReadObject( rPlayerPed.MaxWantedLevel, rStream );
		FBufferHelpers::ReadObject( rPlayerPed.MaxChaosLevel, rStream );
		FBufferHelpers::ReadObject( rPlayerPed.ModelName, rStream );

		FBufferHelpers::Skip2( rStream );
	}

	return true;
}

void FPlayerPeds::Write( std::ostream& rStream )
{
	FBufferHelpers::WriteObject( 1572u, rStream );
	FBufferHelpers::WriteObject( 1566u, rStream );

	FBufferHelpers::WriteObject( ( uint32_t ) PlayerPeds.size(), rStream );

	for( auto& rPlayerPed : PlayerPeds )
	{
		FBufferHelpers::WriteObject( rPlayerPed.___unknown_0__, rStream );
		FBufferHelpers::WriteObject( rPlayerPed.___unknown_1__, rStream );
		FBufferHelpers::WriteObject( rPlayerPed.___unknown_2__, rStream );
		FBufferHelpers::WriteObject( rPlayerPed.CPed.___unknown_0__, rStream );
		FBufferHelpers::WriteObject( rPlayerPed.CPed.XYZ[ 0 ], rStream );
		FBufferHelpers::WriteObject( rPlayerPed.CPed.XYZ[ 1 ], rStream );
		FBufferHelpers::WriteObject( rPlayerPed.CPed.XYZ[ 2 ], rStream );
		FBufferHelpers::WriteObject( rPlayerPed.CPed.___unknown_1__, rStream );
		FBufferHelpers::WriteObject( rPlayerPed.CPed.Health, rStream );
		FBufferHelpers::WriteObject( rPlayerPed.CPed.Armour, rStream );
		FBufferHelpers::WriteObject( rPlayerPed.CPed.___unknown_2__, rStream );

		for( uint32_t Index = 0; Index < rPlayerPed.CPed.Weapons.size(); Index++ )
		{
			FBufferHelpers::WriteObject( rPlayerPed.CPed.Weapons[ Index ].WeaponID, rStream );
			FBufferHelpers::WriteObject( rPlayerPed.CPed.Weapons[ Index ].___unknown_0__, rStream );
			FBufferHelpers::WriteObject( rPlayerPed.CPed.Weapons[ Index ].BulletsInMag, rStream );
			FBufferHelpers::WriteObject( rPlayerPed.CPed.Weapons[ Index ].BulletsInTotal, rStream );
			FBufferHelpers::WriteObject( rPlayerPed.CPed.Weapons[ Index ].___unknown_1__, rStream );
			FBufferHelpers::WriteObject( rPlayerPed.CPed.Weapons[ Index ].___unknown_2__, rStream );
		}

		FBufferHelpers::WriteObject( rPlayerPed.CPed.___unknown_3__, rStream );

		FBufferHelpers::WriteObject( rPlayerPed.MaxWantedLevel, rStream );
		FBufferHelpers::WriteObject( rPlayerPed.MaxChaosLevel, rStream );
		FBufferHelpers::WriteObject( rPlayerPed.ModelName, rStream );

		FBufferHelpers::WriteN( rStream, 2 );
	}
}
