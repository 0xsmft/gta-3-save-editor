#pragma once

#include "Core/Common.h"

#include <array>

enum class CraneState : uint8_t
{
	Idle,
	GoingTowardsTarget,
	LiftingTarget,
	GoingTowardsTargetOnlyHeight,
	RotatingTarget,
	DroppingTarget
};

enum class CraneStatus : uint8_t
{
	None,
	Activated,
	Unactivated
};

struct FCrane
{
	int32_t Index = 0;
	int32_t HookIndex = 0;
	int32_t AudioEntityIndex = 0;

	float PickupZoneX1 = 0.0F;
	float PickupZoneX2 = 0.0F;
	float PickupZoneY1 = 0.0F;
	float PickupZoneY2 = 0.0F;

	FVec3 DropOffPoint{};

	float DropOffHeadingRad = 0.0F;
	float ArmPickUpRotRad = 0.0F;
	float ArmDropOffRotRad = 0.0F;
	float ArmPickUpDistFromCenter = 0.0F;
	float ArmDropOffDistFromCenter = 0.0F;
	float ArmPickUpHeight = 0.0F;
	float ArmDropOffHeight = 0.0F;
	float ArmCurrentRotationRad = 0.0F;
	float ArmDistanceFromCenter = 0.0F;
	float ArmCurrentHeight = 0.0F;

	FVec3 InitialPosition{};
	FVec3 HookCurrentXYZ{};

	FVec2 HookVelocity{};

	int32_t VehPickupPtr = 0;
	int32_t CurrentGameTime = 0;

	uint8_t Activity = 0u;
	uint8_t Status = 0u;
	
	uint8_t NumberOfVehiclesCollected = 0u;
	bool IsCrusherCrane = false;
	bool IsMilitaryCare = false;
	
	uint8_t __unknown_1__ = 0u;
	bool ModelIsNotDoc_Crane_Cab = false;
};

struct FCranes
{
	int32_t NumberOfCranes = 0;
	int32_t CarsCollectedByMilitaryCare = 0;

	std::array<FCrane, 8> Cranes;

	bool Read( std::ifstream& rStream );
};
