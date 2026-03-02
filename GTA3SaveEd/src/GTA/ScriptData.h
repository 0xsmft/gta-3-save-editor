#pragma once

#include <array>

struct FContactInfo
{
	int32_t MissionFlag = 0;
	int32_t BaseBrief = 0;
};

enum class PoolType : int
{
	None,
	Treadable,
	Building,
	Object,
	Dummy
};

struct FBuildingSwap
{
	PoolType Type = PoolType::None;
	int32_t BuildingHandle = 0;
	int32_t NewModel = 0;
	int32_t OldModel = 0;
};

struct FInvisibilitySetting
{
	int32_t Type = 0;
	int32_t Handle = 0;
};

struct CRunningScript
{
	uint32_t Next = 0;
	uint32_t Last = 0;

	char Name[ 8 ]{ 0 };

	uint32_t CurrentIP = 0;
	std::array<uint32_t, 6> ReturnStack{};

	uint16_t StackCounter = 0;

	std::array<uint32_t, 16> LocalVariables{};
	uint32_t TimerA = 0;
	uint32_t TimerB = 0;

	uint8_t IfResult = 0;
	uint8_t IsMissionScript = 0;
	uint8_t IsActive = 0;

	uint32_t WakeTime = 0;
	uint16_t IfNumber = 0;

	uint8_t NotFlag = 0;
	uint8_t WastedBustedEnabled = 0;
	uint8_t WastedBustedResult = 0;
	uint8_t MissionFlag = 0;
};

struct FCollective
{
	int32_t ColIndex = 0;
	int32_t PedIndex = 0;
};

struct FScriptData
{
	uint32_t OnMission = 0;

	std::array<FContactInfo, 16> ContactInfo{};

	std::array<FCollective, 32> Collectives{};
	uint32_t NextFreeCollectiveIndex = 0;

	std::array<FBuildingSwap, 25> BuildingSwap{};
	std::array<FInvisibilitySetting, 20> InvisibilitySetting{};

	bool UsingMultiScriptFile = false;

	uint32_t SizeOfMainSectionInMainScr = 0;
	uint32_t SizeOfLargestMission = 0;
	uint16_t NumberOfExclusiveMissionScr = 0;
};

struct FTheScriptsData
{
	// Next sub-block
	uint32_t SizeOfBlock1 = 0;

	uint32_t VariableSpaceSize = 0;
	std::vector<uint32_t> ScriptSpace;

	FScriptData MainScriptData;

	uint32_t NumberOfActiveScripts = 0;
	std::vector<CRunningScript> RunningScripts;

	bool Read( std::ifstream& rStream );
};
