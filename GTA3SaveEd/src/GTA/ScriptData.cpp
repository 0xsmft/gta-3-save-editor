#include "sppch.h"
#include "ScriptData.h"

#include "Core/BufferHelpers.h"

constexpr uint32_t SCRIPT_DATA_SIZE = 0x3C8;

bool FTheScriptsData::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip4( rStream );

	// Header
	char Signature[ 4 ] = { 'S', 'C', 'R', '\0' };
	FBufferHelpers::ReadBlockHeader( rStream, Signature );

	FBufferHelpers::ReadObject( VariableSpaceSize, rStream );

	ScriptSpace.resize( VariableSpaceSize / 4 );

	for( uint32_t Index = 0; Index < VariableSpaceSize / 4; ++Index )
	{
		FBufferHelpers::ReadObject( ScriptSpace[ Index ], rStream );
	}

	// Read Scripts
	uint32_t size = 0;
	FBufferHelpers::ReadObject( size, rStream );

	if( size != SCRIPT_DATA_SIZE )
	{
		__debugbreak();
	}

	FBufferHelpers::ReadObject( MainScriptData.OnMission, rStream );

	for( uint32_t Index = 0; Index < MainScriptData.ContactInfo.size(); ++Index )
	{
		FContactInfo& rInfo = MainScriptData.ContactInfo[ Index ];

		FBufferHelpers::ReadObject( rInfo.MissionFlag, rStream );
		FBufferHelpers::ReadObject( rInfo.BaseBrief, rStream );
	}

	for( uint32_t Index = 0; Index < MainScriptData.Collectives.size(); ++Index )
	{
		FCollective& rCollective = MainScriptData.Collectives[ Index ];

		FBufferHelpers::ReadObject( rCollective.ColIndex, rStream );
		FBufferHelpers::ReadObject( rCollective.PedIndex, rStream );
	}

	FBufferHelpers::ReadObject( MainScriptData.NextFreeCollectiveIndex, rStream );

	for( uint32_t Index = 0; Index < MainScriptData.BuildingSwap.size(); ++Index )
	{
		FBuildingSwap& rBuildingSwap = MainScriptData.BuildingSwap[ Index ];

		int type = 0;
		FBufferHelpers::ReadObject( type, rStream );
		FBufferHelpers::ReadObject( rBuildingSwap.BuildingHandle, rStream );
		FBufferHelpers::ReadObject( rBuildingSwap.NewModel, rStream );
		FBufferHelpers::ReadObject( rBuildingSwap.OldModel, rStream );

		rBuildingSwap.Type = ( PoolType ) type;
	}

	for( uint32_t Index = 0; Index < MainScriptData.InvisibilitySetting.size(); ++Index )
	{
		FInvisibilitySetting& rInvisSetting = MainScriptData.InvisibilitySetting[ Index ];

		FBufferHelpers::ReadObject( rInvisSetting.Type, rStream );
		FBufferHelpers::ReadObject( rInvisSetting.Handle, rStream );
	}

	FBufferHelpers::ReadObject( MainScriptData.UsingMultiScriptFile, rStream );

	FBufferHelpers::SkipByte( rStream );
	FBufferHelpers::Skip2( rStream );

	FBufferHelpers::ReadObject( MainScriptData.SizeOfMainSectionInMainScr, rStream );
	FBufferHelpers::ReadObject( MainScriptData.SizeOfLargestMission, rStream );
	FBufferHelpers::ReadObject( MainScriptData.NumberOfExclusiveMissionScr, rStream );

	FBufferHelpers::Skip2( rStream );

	uint32_t numberOfRunningScripts = 0u;
	FBufferHelpers::ReadObject( numberOfRunningScripts, rStream );

	RunningScripts.resize( numberOfRunningScripts );

	for( auto& rRunningScript : RunningScripts )
	{
		FBufferHelpers::ReadObject( rRunningScript.Next, rStream );
		FBufferHelpers::ReadObject( rRunningScript.Last, rStream );

		rStream.read( reinterpret_cast< char* >( &rRunningScript.Name ), 8 );

		FBufferHelpers::ReadObject( rRunningScript.CurrentIP, rStream );

		rStream.read( reinterpret_cast< char* >( &rRunningScript.ReturnStack ), sizeof( uint32_t ) * 6 );

		FBufferHelpers::ReadObject( rRunningScript.StackCounter, rStream );

		FBufferHelpers::Skip2( rStream );

		rStream.read( reinterpret_cast< char* >( &rRunningScript.LocalVariables ), sizeof( uint32_t ) * 16 );
		FBufferHelpers::ReadObject( rRunningScript.TimerA, rStream );
		FBufferHelpers::ReadObject( rRunningScript.TimerB, rStream );

		FBufferHelpers::ReadObject( rRunningScript.IfResult, rStream );
		FBufferHelpers::ReadObject( rRunningScript.IsMissionScript, rStream );
		FBufferHelpers::ReadObject( rRunningScript.IsActive, rStream );

		FBufferHelpers::SkipByte( rStream );

		FBufferHelpers::ReadObject( rRunningScript.WakeTime, rStream );
		FBufferHelpers::ReadObject( rRunningScript.IfNumber, rStream );

		FBufferHelpers::ReadObject( rRunningScript.NotFlag, rStream );
		FBufferHelpers::ReadObject( rRunningScript.WastedBustedEnabled, rStream );
		FBufferHelpers::ReadObject( rRunningScript.WastedBustedResult, rStream );
		FBufferHelpers::ReadObject( rRunningScript.MissionFlag, rStream );

		FBufferHelpers::Skip2( rStream );
	}

	return true;
}

void FTheScriptsData::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( 26264u, rStream );
	FBufferHelpers::WriteBlockHeader( rStream, "SCR", 26256u );

	FBufferHelpers::WriteObject( VariableSpaceSize, rStream );

	for( uint32_t Index = 0; Index < VariableSpaceSize / 4; ++Index )
	{
		FBufferHelpers::WriteObject( ScriptSpace[ Index ], rStream );
	}

	FBufferHelpers::WriteObject( SCRIPT_DATA_SIZE, rStream );

	FBufferHelpers::WriteObject( MainScriptData.OnMission, rStream );

	for( uint32_t Index = 0; Index < MainScriptData.ContactInfo.size(); ++Index )
	{
		FContactInfo& rInfo = MainScriptData.ContactInfo[ Index ];

		FBufferHelpers::WriteObject( rInfo.MissionFlag, rStream );
		FBufferHelpers::WriteObject( rInfo.BaseBrief, rStream );
	}

	for( uint32_t Index = 0; Index < MainScriptData.Collectives.size(); ++Index )
	{
		FCollective& rCollective = MainScriptData.Collectives[ Index ];

		FBufferHelpers::WriteObject( rCollective.ColIndex, rStream );
		FBufferHelpers::WriteObject( rCollective.PedIndex, rStream );
	}

	FBufferHelpers::WriteObject( MainScriptData.NextFreeCollectiveIndex, rStream );

	for( uint32_t Index = 0; Index < MainScriptData.BuildingSwap.size(); ++Index )
	{
		FBuildingSwap& rBuildingSwap = MainScriptData.BuildingSwap[ Index ];

		int type = 0;
		FBufferHelpers::WriteObject( type, rStream );
		FBufferHelpers::WriteObject( rBuildingSwap.BuildingHandle, rStream );
		FBufferHelpers::WriteObject( rBuildingSwap.NewModel, rStream );
		FBufferHelpers::WriteObject( rBuildingSwap.OldModel, rStream );

		rBuildingSwap.Type = ( PoolType ) type;
	}

	for( uint32_t Index = 0; Index < MainScriptData.InvisibilitySetting.size(); ++Index )
	{
		FInvisibilitySetting& rInvisSetting = MainScriptData.InvisibilitySetting[ Index ];

		FBufferHelpers::WriteObject( rInvisSetting.Type, rStream );
		FBufferHelpers::WriteObject( rInvisSetting.Handle, rStream );
	}

	FBufferHelpers::WriteObject( MainScriptData.UsingMultiScriptFile, rStream );

	FBufferHelpers::WriteN( rStream, 3 );

	FBufferHelpers::WriteObject( MainScriptData.SizeOfMainSectionInMainScr, rStream );
	FBufferHelpers::WriteObject( MainScriptData.SizeOfLargestMission, rStream );
	FBufferHelpers::WriteObject( MainScriptData.NumberOfExclusiveMissionScr, rStream );

	FBufferHelpers::WriteN( rStream, 2 );

	FBufferHelpers::WriteObject( ( uint32_t ) RunningScripts.size(), rStream );

	for( auto& rRunningScript : RunningScripts )
	{
		FBufferHelpers::WriteObject( rRunningScript.Next, rStream );
		FBufferHelpers::WriteObject( rRunningScript.Last, rStream );

		rStream.write( reinterpret_cast< char* >( &rRunningScript.Name ), 8 );

		FBufferHelpers::WriteObject( rRunningScript.CurrentIP, rStream );

		rStream.write( reinterpret_cast< char* >( &rRunningScript.ReturnStack ), sizeof( uint32_t ) * 6 );

		FBufferHelpers::WriteObject( rRunningScript.StackCounter, rStream );

		FBufferHelpers::WriteN( rStream, 2 );

		rStream.write( reinterpret_cast< char* >( &rRunningScript.LocalVariables ), sizeof( uint32_t ) * 16 );
		FBufferHelpers::WriteObject( rRunningScript.TimerA, rStream );
		FBufferHelpers::WriteObject( rRunningScript.TimerB, rStream );

		FBufferHelpers::WriteObject( rRunningScript.IfResult, rStream );
		FBufferHelpers::WriteObject( rRunningScript.IsMissionScript, rStream );
		FBufferHelpers::WriteObject( rRunningScript.IsActive, rStream );

		FBufferHelpers::WriteByte( rStream );

		FBufferHelpers::WriteObject( rRunningScript.WakeTime, rStream );
		FBufferHelpers::WriteObject( rRunningScript.IfNumber, rStream );

		FBufferHelpers::WriteObject( rRunningScript.NotFlag, rStream );
		FBufferHelpers::WriteObject( rRunningScript.WastedBustedEnabled, rStream );
		FBufferHelpers::WriteObject( rRunningScript.WastedBustedResult, rStream );
		FBufferHelpers::WriteObject( rRunningScript.MissionFlag, rStream );

		FBufferHelpers::WriteN( rStream, 2 );
	}
}
