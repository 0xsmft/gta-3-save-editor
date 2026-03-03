#pragma once

#include "Core/Common.h"

#include "SimpleData.h"
#include "ScriptData.h"
#include "PlayerPeds.h"
#include "Garages.h"
#include "Vehicles.h"
#include "Objects.h"
#include "PathFinding.h"
#include "Cranes.h"
#include "Pickups.h"
#include "PhoneInfo.h"
#include "RestartPoints.h"
#include "RadarBlips.h"
#include "ZoneInfo.h"
#include "Gangs.h"
#include "CarGenerators.h"
#include "Particles.h"
#include "AudioScriptObjects.h"
#include "PlayerInfo.h"
#include "Stats.h"
#include "StreamingData.h"
#include "PedTypeInfo.h"

#include <filesystem>

struct FSaveFileStructure
{
	// Block 0
	FSimpleData SimpleData{};
	FTheScriptsData TheScriptsData{};

	// Block 1
	FPlayerPeds PlayerPedsData;

	// Block 2
	FGarages Garages;

	// Block 3
	FVehicles Vehicles;
	
	// Block 4
	FObjects Objects;

	// Block 5
	FPathFinding PathFinding;

	// Block 6
	FCranes Cranes;

	// Block 7
	FPickups Pickups;

	// Block 8
	FPhones Phones;
	
	// Block 9
	FRestartInfo Restarts;

	// Block 10
	FRadarBlips RadarBlips;

	// Block 11
	FTheZones TheZones;
	
	// Block 12
	FGangs Gangs;

	// Block 13
	FTheCarGenerators CarGenerators;

	// Block 14
	FParticles Particles;

	// Block 15
	FAudioScriptObjects AudioScriptObjects;

	// Block 16
	FPlayerInfo PlayerInfo;

	// Block 17
	FStatsData PlayerStats;

	// Block 18
	FStreamingData StreamingData;

	// Block 19
	FPedTypeInfos PedTypeInfos;
};

class FSaveFile
{
public:
	FSaveFile();
	~FSaveFile();

public:	 
	bool Read( const std::filesystem::path& rPath );

private:
	FSaveFileStructure m_SaveFile{};
};
