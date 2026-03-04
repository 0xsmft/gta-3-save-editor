#pragma once

#include "Core/Common.h"

#include <array>
#include <vector>
#include <fstream>

struct FStoredCar
{
	uint32_t ModelID = 0;
	FVec3 Position{};
	FVec3 Rotation{};

	uint32_t Immunities = 0b0;

	uint8_t PrimaryColorID = 0;
	uint8_t SecondaryColorID = 0;
	uint8_t RadioStationID = 0;
	uint8_t ModelVariationA = 0;
	uint8_t ModelVariationB = 0;
	uint8_t BombTypeID = 0;

	XY_NODISCARD inline bool IsVehicleImmunityFlagSet( uint32_t flag ) const
	{
		return ( Immunities & flag ) != 0;
	}

	inline void SetImmunityFlag( uint32_t flag, bool val ) 
	{
		if( val )
			Immunities |= flag;
		else 
			Immunities &= ~flag;
	}

	bool Read( std::ifstream& rStream );
};

std::string_view VehicleModelIDToString( uint32_t ModelID );
std::string_view VehicleColorIDToString( uint8_t ColorID );

enum
{
	VEH_IMM_BULLET = 0x01,
	VEH_IMM_FIRE = 0x02,
	VEH_IMM_EXPLOSION = 0x04,
	VEH_IMM_COLLISION = 0x08,
	VEH_IMM_MELEE = 0x10,
};

enum class RadioStations
{
	HeadRadio,

	// Double clef FM.
	Classical,

	JahRadio,
	RiseFM,
	Lips,
	GameFM,
	MSXFM,
	Flashback,
	ChatterBox,
	User,
	PoliceRadio,
	Off
};

enum class VehicleBombTypes
{
	NoBomb,
	TimerBomb,
	IgnitionBomb,
	RemoteBomb,
	TimerBombArmed,
	IgnitionBombArmed
};

enum class GarageState : uint8_t
{
	FullyClosed,
	Opened,
	Closing,
	Opening,
	OpenedHasCar,
	ClosedHasCar,
	AfterDropOff
};

enum class GarageType : uint8_t
{
	None,
	Mission,
	Bombshop1,
	Bombshop2,
	Bombshop3,
	Respray,
	CollectersItem,
	CollectSpecific,
	CollectCars1,
	CollectCars2,
	CollectCars3,

	// Used in "Salvatore's called a meeting"
	ForCarToComeOutOf,
	SixitySeconds,
	Crusher,
	MissionKeep,
	ForScriptToOpen,
	HideoutOne,
	HideoutTwo,
	HideoutThree,
	ForScriptToOpenAndClose,
	KeepOpenForSpecificCar,
	MissionKeepCarRemainClosed
};

struct FGarage
{
	GarageType TypeID = GarageType::None;
	GarageState State = GarageState::FullyClosed;
	bool __unknown_0__ = false;
	bool ClosingWithoutTargetCar = false;
	bool Deactivated = false;
	bool ResprayHappenend = false;

	uint32_t TargetVehicleModelIdx = 0u;
	uint32_t Door1Ptr = 0u;
	uint32_t Door2Ptr = 0u;

	bool IsDoor1PoolIndex = false;
	bool IsDoor2PoolIndex = false;
	bool IsDoor1Object = false;
	bool IsDoor2Object = false;
	bool __unknown_1__ = false;
	bool RotatedDoor = false;
	bool CameraFollowsPlayer = false;

	float X1 = 0.0F;
	float X2 = 0.0F;
	float Y1 = 0.0F;
	float Y2 = 0.0F;
	float Z1 = 0.0F;
	float Z2 = 0.0F;

	float DoorPosition = 0.0f;
	float DoorHeight = 0.0f;

	float DoorX1 = 0.0F;
	float DoorY1 = 0.0F;
	float DoorX2 = 0.0F;
	float DoorY2 = 0.0F;
	float DoorZ1 = 0.0F;
	float DoorZ2 = 0.0F;

	uint32_t LastOpenTime = 0u;

	bool CollectedCars = false;

	uint32_t TargetVehiclePtr = 0u;
	uint32_t __unknown_2__ = 0u;

	FStoredCar StoredCar{};
};

struct FGarages
{
	uint32_t Count = 0;
	bool BombsAreFree = false;
	bool RespraysAreFree = false;
	int32_t CarsCollected = 0;
	int32_t BankVansCollected = 0;
	int32_t PoliceCarsCollected = 0;

	// What does IE mean??
	int32_t PortlandIEStatus = 0;
	int32_t ShoresideIEStatus = 0;
	int32_t UnusedIEStatus = 0;

	// GA_21 = Garage is full...
	uint32_t TimeGA21WasShown = 0;

	std::array<FStoredCar, 18> StoredCars{};
	std::vector<FGarage> Garages;

	bool Read( std::ifstream& rStream );
};
