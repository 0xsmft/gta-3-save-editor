#include "sppch.h"
#include "Gangs.h"

#include "Core/BufferHelpers.h"

bool FGangs::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );

	FBufferHelpers::ReadBlockHeader( rStream, "GNG" );

	for( uint32_t Index = 0u; Index < Gangs.size(); ++Index )
	{
		FBufferHelpers::ReadObject( Gangs[ Index ].VehicleModelIndex, rStream );
		FBufferHelpers::ReadObject( Gangs[ Index ].PedModelOverride, rStream );
		FBufferHelpers::SkipN( rStream, 3 );

		FBufferHelpers::ReadObject( Gangs[ Index ].WeaponA, rStream );
		FBufferHelpers::ReadObject( Gangs[ Index ].WeaponB, rStream );
	}

	return true;
}

void FGangs::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( 156u, rStream );
	FBufferHelpers::WriteObject( 152u, rStream );

	FBufferHelpers::WriteBlockHeader( rStream, "GNG", 144u );

	for( uint32_t Index = 0u; Index < Gangs.size(); ++Index )
	{
		FBufferHelpers::WriteObject( Gangs[ Index ].VehicleModelIndex, rStream );
		FBufferHelpers::WriteObject( Gangs[ Index ].PedModelOverride, rStream );
		FBufferHelpers::WriteN( rStream, 3 );

		FBufferHelpers::WriteObject( Gangs[ Index ].WeaponA, rStream );
		FBufferHelpers::WriteObject( Gangs[ Index ].WeaponB, rStream );
	}

}
