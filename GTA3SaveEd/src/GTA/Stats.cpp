#include "sppch.h"
#include "Stats.h"

#include "Core/BufferHelpers.h"

bool FStatsData::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );

	FBufferHelpers::ReadObject( PeopleKilledByPlayer, rStream );
	FBufferHelpers::ReadObject( PeopleKilledByOthers, rStream );
	FBufferHelpers::ReadObject( CarsExploded, rStream );
	FBufferHelpers::ReadObject( RoundsFiredByPlayer, rStream );

	for( uint32_t Index = 0u; Index < PedsKilledOfThisType.size(); ++Index )
	{
		FBufferHelpers::ReadObject( PedsKilledOfThisType[ Index ], rStream );
	}

	FBufferHelpers::ReadObject( HelisDestroyed, rStream );
	FBufferHelpers::ReadObject( ProgressMade, rStream );
	FBufferHelpers::ReadObject( TotalProgressInGame, rStream );
	FBufferHelpers::ReadObject( KgsOfExplosivesUsed, rStream );
	FBufferHelpers::ReadObject( InstantHitsFiredByPlayer, rStream );
	FBufferHelpers::ReadObject( InstantHitsHitByPlayer, rStream );
	FBufferHelpers::ReadObject( CarsCrushed, rStream );
	FBufferHelpers::ReadObject( HeadsPopped, rStream );
	FBufferHelpers::ReadObject( TimesArrested, rStream );
	FBufferHelpers::ReadObject( TimesWasted, rStream );
	FBufferHelpers::ReadObject( DaysPassed, rStream );
	FBufferHelpers::ReadObject( TimeSpentRaining, rStream );

	FBufferHelpers::ReadObject( MaxJumpDistance, rStream );
	FBufferHelpers::ReadObject( MaxJumpHeight, rStream );

	FBufferHelpers::ReadObject( MaxJumpFlips, rStream );
	FBufferHelpers::ReadObject( MaxJumpSpins, rStream );
	FBufferHelpers::ReadObject( BestStuntJump, rStream );
	FBufferHelpers::ReadObject( NumberOfUniqueJumpsFound, rStream );
	FBufferHelpers::ReadObject( TotalNumberOfUniqueJumps, rStream );
	FBufferHelpers::ReadObject( MissionsGiven, rStream );
	FBufferHelpers::ReadObject( MissionsPassed, rStream );
	FBufferHelpers::ReadObject( PassengersDroppedOffWithTaxi, rStream );
	FBufferHelpers::ReadObject( MoneyMadeFromTaxi, rStream );

	FBufferHelpers::ReadObject( IndustrialPassed, rStream );
	FBufferHelpers::ReadObject( CommericalPassed, rStream );
	FBufferHelpers::ReadObject( SuburbanPassed, rStream );

	FBufferHelpers::ReadObject( ElBurroTime, rStream );
	FBufferHelpers::ReadObject( DistanceTravelledOnFoot, rStream );
	FBufferHelpers::ReadObject( DistanceTravelledInVeh, rStream );
	FBufferHelpers::ReadObject( RecordInPatriotPlayground, rStream );
	FBufferHelpers::ReadObject( RecordInARideInThePark, rStream );
	FBufferHelpers::ReadObject( RecordInGripped, rStream );
	FBufferHelpers::ReadObject( RecordInMayhem, rStream );
	FBufferHelpers::ReadObject( LivesSaved, rStream );
	FBufferHelpers::ReadObject( CriminalsCaught, rStream );
	FBufferHelpers::ReadObject( HighestLevelAmbulanceMission, rStream );
	FBufferHelpers::ReadObject( FiresExtinguished, rStream );
	FBufferHelpers::ReadObject( LongestFlight, rStream );
	FBufferHelpers::ReadObject( TimeTakenDefuseMission, rStream );
	FBufferHelpers::ReadObject( NumberKillFrenziesPassed, rStream );
	FBufferHelpers::ReadObject( TotalNumberKillFrenzies, rStream );
	FBufferHelpers::ReadObject( TotalNumberMissions, rStream );

	for( uint32_t Index = 0u; Index < FastestTimes.size(); ++Index )
	{
		FBufferHelpers::ReadObject( FastestTimes[ Index ], rStream );
	}

	for( uint32_t Index = 0u; Index < HighestScores.size(); ++Index )
	{
		FBufferHelpers::ReadObject( HighestScores[ Index ], rStream );
	}

	FBufferHelpers::ReadObject( KillsSinceLastCheckpoint, rStream );
	FBufferHelpers::ReadObject( TotalLegitimateKills, rStream );
	
	FBufferHelpers::ReadObject( LastMissionPassedName, rStream );

	return true;
}

void FStatsData::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( 424u, rStream );
	FBufferHelpers::WriteObject( 420u, rStream );

	FBufferHelpers::WriteObject( PeopleKilledByPlayer, rStream );
	FBufferHelpers::WriteObject( PeopleKilledByOthers, rStream );
	FBufferHelpers::WriteObject( CarsExploded, rStream );
	FBufferHelpers::WriteObject( RoundsFiredByPlayer, rStream );

	for( uint32_t Index = 0u; Index < PedsKilledOfThisType.size(); ++Index )
	{
		FBufferHelpers::WriteObject( PedsKilledOfThisType[ Index ], rStream );
	}

	FBufferHelpers::WriteObject( HelisDestroyed, rStream );
	FBufferHelpers::WriteObject( ProgressMade, rStream );
	FBufferHelpers::WriteObject( TotalProgressInGame, rStream );
	FBufferHelpers::WriteObject( KgsOfExplosivesUsed, rStream );
	FBufferHelpers::WriteObject( InstantHitsFiredByPlayer, rStream );
	FBufferHelpers::WriteObject( InstantHitsHitByPlayer, rStream );
	FBufferHelpers::WriteObject( CarsCrushed, rStream );
	FBufferHelpers::WriteObject( HeadsPopped, rStream );
	FBufferHelpers::WriteObject( TimesArrested, rStream );
	FBufferHelpers::WriteObject( TimesWasted, rStream );
	FBufferHelpers::WriteObject( DaysPassed, rStream );
	FBufferHelpers::WriteObject( TimeSpentRaining, rStream );

	FBufferHelpers::WriteObject( MaxJumpDistance, rStream );
	FBufferHelpers::WriteObject( MaxJumpHeight, rStream );

	FBufferHelpers::WriteObject( MaxJumpFlips, rStream );
	FBufferHelpers::WriteObject( MaxJumpSpins, rStream );
	FBufferHelpers::WriteObject( BestStuntJump, rStream );
	FBufferHelpers::WriteObject( NumberOfUniqueJumpsFound, rStream );
	FBufferHelpers::WriteObject( TotalNumberOfUniqueJumps, rStream );
	FBufferHelpers::WriteObject( MissionsGiven, rStream );
	FBufferHelpers::WriteObject( MissionsPassed, rStream );
	FBufferHelpers::WriteObject( PassengersDroppedOffWithTaxi, rStream );
	FBufferHelpers::WriteObject( MoneyMadeFromTaxi, rStream );

	FBufferHelpers::WriteObject( IndustrialPassed, rStream );
	FBufferHelpers::WriteObject( CommericalPassed, rStream );
	FBufferHelpers::WriteObject( SuburbanPassed, rStream );

	FBufferHelpers::WriteObject( ElBurroTime, rStream );
	FBufferHelpers::WriteObject( DistanceTravelledOnFoot, rStream );
	FBufferHelpers::WriteObject( DistanceTravelledInVeh, rStream );
	FBufferHelpers::WriteObject( RecordInPatriotPlayground, rStream );
	FBufferHelpers::WriteObject( RecordInARideInThePark, rStream );
	FBufferHelpers::WriteObject( RecordInGripped, rStream );
	FBufferHelpers::WriteObject( RecordInMayhem, rStream );
	FBufferHelpers::WriteObject( LivesSaved, rStream );
	FBufferHelpers::WriteObject( CriminalsCaught, rStream );
	FBufferHelpers::WriteObject( HighestLevelAmbulanceMission, rStream );
	FBufferHelpers::WriteObject( FiresExtinguished, rStream );
	FBufferHelpers::WriteObject( LongestFlight, rStream );
	FBufferHelpers::WriteObject( TimeTakenDefuseMission, rStream );
	FBufferHelpers::WriteObject( NumberKillFrenziesPassed, rStream );
	FBufferHelpers::WriteObject( TotalNumberKillFrenzies, rStream );
	FBufferHelpers::WriteObject( TotalNumberMissions, rStream );

	for( uint32_t Index = 0u; Index < FastestTimes.size(); ++Index )
	{
		FBufferHelpers::WriteObject( FastestTimes[ Index ], rStream );
	}

	for( uint32_t Index = 0u; Index < HighestScores.size(); ++Index )
	{
		FBufferHelpers::WriteObject( HighestScores[ Index ], rStream );
	}

	FBufferHelpers::WriteObject( KillsSinceLastCheckpoint, rStream );
	FBufferHelpers::WriteObject( TotalLegitimateKills, rStream );

	FBufferHelpers::WriteObject( LastMissionPassedName, rStream );
}
