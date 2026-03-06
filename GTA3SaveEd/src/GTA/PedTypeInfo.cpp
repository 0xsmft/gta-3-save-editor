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

void FPedTypeInfos::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( 748u, rStream );
	FBufferHelpers::WriteObject( 744u, rStream );

	FBufferHelpers::WriteBlockHeader( rStream, "PTP", 736u );

	for( uint32_t Index = 0u; Index < PedTypeInfos.size(); ++Index )
	{
		FBufferHelpers::WriteObject( PedTypeInfos[ Index ].Flag, rStream );
		FBufferHelpers::WriteObject( PedTypeInfos[ Index ].__unknown_0__, rStream );
		FBufferHelpers::WriteObject( PedTypeInfos[ Index ].__unknown_1__, rStream );
		FBufferHelpers::WriteObject( PedTypeInfos[ Index ].__unknown_2__, rStream );
		FBufferHelpers::WriteObject( PedTypeInfos[ Index ].FleeDistance, rStream );
		FBufferHelpers::WriteObject( PedTypeInfos[ Index ].HeadingChangeRate, rStream );
		FBufferHelpers::WriteObject( PedTypeInfos[ Index ].ThreatFlags, rStream );
		FBufferHelpers::WriteObject( PedTypeInfos[ Index ].AvoidFlags, rStream );
	}
}
