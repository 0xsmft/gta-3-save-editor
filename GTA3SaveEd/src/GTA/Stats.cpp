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
