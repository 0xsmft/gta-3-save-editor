#include "sppch.h"
#include "PedTypeInfo.h"

#include "Core/BufferHelpers.h"

bool FPedTypeInfos::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );

	FBufferHelpers::ReadBlockHeader( rStream, "PTP" );

	for( uint32_t Index = 0u; Index < PedTypeInfos.size(); ++Index )
	{
		FBufferHelpers::ReadObject( PedTypeInfos[ Index ].Flag, rStream );
		FBufferHelpers::ReadObject( PedTypeInfos[ Index ].__unknown_0__, rStream );
		FBufferHelpers::ReadObject( PedTypeInfos[ Index ].__unknown_1__, rStream );
		FBufferHelpers::ReadObject( PedTypeInfos[ Index ].__unknown_2__, rStream );
		FBufferHelpers::ReadObject( PedTypeInfos[ Index ].FleeDistance, rStream );
		FBufferHelpers::ReadObject( PedTypeInfos[ Index ].HeadingChangeRate, rStream );
		FBufferHelpers::ReadObject( PedTypeInfos[ Index ].ThreatFlags, rStream );
		FBufferHelpers::ReadObject( PedTypeInfos[ Index ].AvoidFlags, rStream );
	}

	return true;
}
