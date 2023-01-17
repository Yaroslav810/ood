#pragma once
#include "SWindInfo.h"

enum class EWeatherIndicator
{
	Temperature,
	Humidity,
	Pressure,
	Wind,
};

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
	SWindInfo wind;
};
