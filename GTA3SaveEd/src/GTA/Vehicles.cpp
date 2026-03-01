#include "sppch.h"
#include "Vehicles.h"

#include "Base/BufferHelpers.h"

bool FVehicles::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );

	FBufferHelpers::ReadObject( Count, rStream );
	FBufferHelpers::ReadObject( NumberOfBoats, rStream );

	Vehicles.resize( Count );
	Boats.resize( NumberOfBoats );

	for( uint32_t Index = 0; Index < Count + NumberOfBoats; ++Index )
	{
		uint32_t type = 0u;
		int16_t model = 0;
		int32_t slot = 0;

		FBufferHelpers::ReadObject( type, rStream );
		FBufferHelpers::ReadObject( model, rStream );
		FBufferHelpers::ReadObject( slot, rStream );

		switch( type )
		{
			case 1 /*VehicleType::Boat*/:
			{
				FBoat& rBoat = Boats[ Index ];

				FBufferHelpers::ReadObject( rBoat.CBoat.__unknown_0__, rStream );
				FBufferHelpers::ReadObject( rBoat.CBoat.Position, rStream );
				FBufferHelpers::ReadObject( rBoat.CBoat.__unknown_1__, rStream );

				rBoat.Type = ( VehicleType ) type;
				rBoat.ModelID = model;
				rBoat.Slot = slot;
			} break;

			case 0 /*VehicleType::Car*/:
			{
				FVehicle& rVehicle = Vehicles[ Index ];

				FBufferHelpers::ReadObject( rVehicle.CVehicle.__unknown_0__, rStream );
				FBufferHelpers::ReadObject( rVehicle.CVehicle.Position, rStream );
				FBufferHelpers::ReadObject( rVehicle.CVehicle.__unknown_1__, rStream );

				rVehicle.Type = ( VehicleType ) type;
				rVehicle.ModelID = model;
				rVehicle.Slot = slot;
			} break;

			default:
				__debugbreak();
				break;
		}
	}

	return true;
}
