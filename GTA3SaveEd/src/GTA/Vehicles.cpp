#include "sppch.h"
#include "Vehicles.h"

#include "Base/BufferHelpers.h"

bool FVehicles::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip4( rStream );
	FBufferHelpers::Skip4( rStream );

	FBufferHelpers::ReadObject( Count, rStream );
	FBufferHelpers::ReadObject( NumberOfBoats, rStream );

	Vehicles.resize( Count );
	Boats.resize( NumberOfBoats );

	for( auto& rVechicle : Vehicles )
	{
		FBufferHelpers::ReadObject( rVechicle.Field0h, rStream );
		FBufferHelpers::ReadObject( rVechicle.ModelID, rStream );
		FBufferHelpers::ReadObject( rVechicle.Field06h, rStream );

		FBufferHelpers::ReadObject( rVechicle.CVehicle.__unknown_0__, rStream );
		FBufferHelpers::ReadObject( rVechicle.CVehicle.Position, rStream );
		FBufferHelpers::ReadObject( rVechicle.CVehicle.__unknown_1__, rStream );
	}

	for( auto& rBoat : Boats )
	{
		FBufferHelpers::ReadObject( rBoat.Field0h, rStream );
		FBufferHelpers::ReadObject( rBoat.ModelID, rStream );
		FBufferHelpers::ReadObject( rBoat.Field06h, rStream );

		FBufferHelpers::ReadObject( rBoat.CBoat.__unknown_0__, rStream );
		FBufferHelpers::ReadObject( rBoat.CBoat.Position, rStream );
		FBufferHelpers::ReadObject( rBoat.CBoat.__unknown_1__, rStream );
	}

	return true;
}
