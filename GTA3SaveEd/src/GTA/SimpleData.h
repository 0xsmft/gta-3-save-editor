#pragma once

#include "Island.h"

#include "Base/Common.h"

struct FSimpleData
{
	wchar_t SaveName[ 24 ];

	uint16_t Year = 0;
	uint16_t Month = 0;
	uint16_t DayOfWeek = 0;
	uint16_t Day = 0;
	uint16_t Hour = 0;
	uint16_t Minute = 0;
	uint16_t Second = 0;
	uint16_t Milisecond = 0;

	uint32_t SizeOfGameInBytes = 0;

	CurrentIsland Island = CurrentIsland::Unknown;

	FVec3 CameraXYZ{};

	uint32_t MinuteLength = 0;

	uint32_t LastClockTick = 0;

	uint8_t GameHour = 0;
	uint8_t Padding0[ 3 ];
	uint8_t GameMinute = 0;
	uint8_t Padding1[ 3 ];
	uint8_t CurrentPadMode = 0;
	uint8_t Padding2[ 2 ];

	uint32_t TimeMs = 0;
	float TimeScale = 0.0F;
	float TimeStepDelta = 0.0F;
	float TimeStepNC = 0.0F;

	uint32_t NumberOfFramesProcessed = 0;
	float TimestepConst = 1.0f;
	float FramesPerUpdateConst = 1.0f;
	float TimeScaleConst = 1.0f;

	uint16_t OldWeatherType = 0;
	uint8_t Padding3[ 2 ];
	uint16_t NewWeatherType = 0;
	uint8_t Padding4[ 2 ];
	uint16_t ForcedWeatherType = 0;
	uint8_t Padding5[ 2 ];

	float WeatherInterpolationValue = 0.0f;
	uint8_t Padding6[ 24 ];
	uint32_t WeatherTypeList = 0;

	float CameraModeInCar = 0.0f;
	float CameraModeOnFoot = 0.0f;
};