#pragma once
#include "../../SWeatherInfo.h"
#include "../CStatsData/CStatsData.h"
#include <iostream>

class CStatsCommonData
{
public:
	CStatsCommonData();
	void Update(SWeatherInfo const& data);

	[[nodiscard]] CStatsData GetTemperature() const;
	[[nodiscard]] CStatsData GetHumidity() const;
	[[nodiscard]] CStatsData GetPressure() const;

private:
	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;
};