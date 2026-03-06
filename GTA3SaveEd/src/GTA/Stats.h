#pragma once

#include "Core/Common.h"

#include <array>
#include <fstream>

struct FStatsData
{
	uint32_t PeopleKilledByPlayer = 0u;
	uint32_t PeopleKilledByOthers = 0u;
	uint32_t CarsExploded = 0u;
	uint32_t RoundsFiredByPlayer = 0u;

	std::array<uint32_t, 23> PedsKilledOfThisType{ 0u };

	uint32_t HelisDestroyed = 0u;
	uint32_t ProgressMade = 0u;
	uint32_t TotalProgressInGame = 0u;
	uint32_t KgsOfExplosivesUsed = 0u;
	uint32_t InstantHitsFiredByPlayer = 0u;
	uint32_t InstantHitsHitByPlayer = 0u;
	uint32_t CarsCrushed = 0u;
	uint32_t HeadsPopped = 0u;
	uint32_t TimesArrested = 0u;
	uint32_t TimesWasted = 0u;
	uint32_t DaysPassed = 0u;
	uint32_t TimeSpentRaining = 0u;

	float MaxJumpDistance = 0.0f;
	float MaxJumpHeight = 0.0f;

	uint32_t MaxJumpFlips = 0u;
	uint32_t MaxJumpSpins = 0u;

	uint32_t BestStuntJump = 0u;

	uint32_t NumberOfUniqueJumpsFound = 0u;
	uint32_t TotalNumberOfUniqueJumps = 0u;
	uint32_t MissionsGiven = 0u;
	uint32_t MissionsPassed = 0u;
	uint32_t PassengersDroppedOffWithTaxi = 0u;
	uint32_t MoneyMadeFromTaxi = 0u;

	// These are four bytes... for some reason...
	// prob for aligment sake.
	uint32_t IndustrialPassed = false;
	uint32_t CommericalPassed = false;
	uint32_t SuburbanPassed = false;

	uint32_t ElBurroTime = 0u;

	float DistanceTravelledOnFoot = 0.0f;
	float DistanceTravelledInVeh = 0.0f;

	uint32_t RecordInPatriotPlayground = 0u;
	uint32_t RecordInARideInThePark = 0u;
	uint32_t RecordInGripped = 0u;
	uint32_t RecordInMayhem = 0u;

	// AMBULAN SIDE MISSIONS.
	uint32_t LivesSaved = 0u;

	uint32_t CriminalsCaught = 0u;
	uint32_t HighestLevelAmbulanceMission = 0u;
	uint32_t FiresExtinguished = 0u;
	uint32_t LongestFlight = 0u;
	uint32_t TimeTakenDefuseMission = 0u;
	uint32_t NumberKillFrenziesPassed = 0u;
	uint32_t TotalNumberKillFrenzies = 0u;
	uint32_t TotalNumberMissions = 0u;

	std::array<uint32_t, 16> FastestTimes{ 0u };
	std::array<uint32_t, 16> HighestScores{ 0u };

	uint32_t KillsSinceLastCheckpoint = 0u;
	uint32_t TotalLegitimateKills = 0u;

	char LastMissionPassedName[ 8 ] = { 0 };

	bool Read( std::ifstream& rStream );
	void Write( std::ofstream& rStream );
};
