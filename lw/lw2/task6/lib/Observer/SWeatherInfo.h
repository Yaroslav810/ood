#pragma once
#include "SWindInfo.h"
#include <optional>

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
	std::optional<SWindInfo> wind;
};
