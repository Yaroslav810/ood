#pragma once
#include "../../SWeatherInfo.h"
#include "../CStatsData/CStatsData.h"
#include "../CStatsWindData/CStatsWindData.h"
#include <iostream>

class CStatsCommonProData
{
public:
	CStatsCommonProData();
	void Update(SWeatherInfo const& data);

	[[nodiscard]] CStatsData GetTemperature() const;
	[[nodiscard]] CStatsData GetHumidity() const;
	[[nodiscard]] CStatsData GetPressure() const;
	[[nodiscard]] CStatsWindData GetWind() const;

private:
	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;
	CStatsWindData m_wind;
};