#include "sppch.h"
#include "Gangs.h"

#include "Base/BufferHelpers.h"

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
