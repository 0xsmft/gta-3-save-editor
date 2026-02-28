#pragma once

#include <vector>
#include <array>
#include <fstream>

struct FWeaponSlot
{
	uint32_t WeaponID = 0;
	uint32_t ___unknown_0__ = 0;
	uint32_t BulletsInMag = 0;
	uint32_t BulletsInTotal = 0;
	uint32_t ___unknown_1__ = 0;
	uint32_t ___unknown_2__ = 0;
};

struct FCPed
{
	uint8_t ___unknown_0__[ 52 ]{ 0 };

	float XYZ[ 3 ];

	uint8_t ___unknown_1__[ 640 ]{ 0 };

	float Health = 0.0f;
	float Armour = 0.0f;

	uint8_t ___unknown_2__[ 148 ]{ 0 };

	std::array<FWeaponSlot, 13> Weapons;

	uint8_t ___unknown_3__[ 348 ]{ 0 };
};

struct FPlayerPed
{
	uint32_t ___unknown_0__ = 0;
	uint16_t ___unknown_1__ = 0;
	uint32_t ___unknown_2__ = 0;

	FCPed CPed{};

	uint32_t MaxWantedLevel = 0;
	uint32_t MaxChaosLevel = 0;
	char ModelName[ 24 ]{ 0 };

	uint8_t Padding0[ 2 ]{ 0 };
};

struct FPlayerPeds
{
	std::vector<FPlayerPed> PlayerPeds;

	bool Read( std::ifstream& rStream );
};
