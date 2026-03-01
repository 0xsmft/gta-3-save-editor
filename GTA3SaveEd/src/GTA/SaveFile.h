#pragma once

#include "Base/Common.h"

#include "SimpleData.h"
#include "ScriptData.h"
#include "PlayerPeds.h"
#include "Garages.h"
#include "Vehicles.h"
#include "Objects.h"
#include "PathFinding.h"

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
};

class FGtaSaveFile
{
public:
	FGtaSaveFile();
	~FGtaSaveFile();

public:	 
	bool Read( const std::filesystem::path& rPath );

private:
	FSaveFileStructure m_SaveFile{};
};
