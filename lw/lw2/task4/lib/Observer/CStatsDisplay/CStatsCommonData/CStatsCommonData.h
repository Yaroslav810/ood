#pragma once
#include "../../SWeatherInfo.h"
#include "CStatsData/CStatsData.h"
#include <iostream>

class CStatsCommonData
{
public:
	CStatsCommonData();
	void Update(SWeatherInfo const& data);

	[[nodiscard]] CStatsData getTemperature() const;
	[[nodiscard]] CStatsData getHumidity() const;
	[[nodiscard]] CStatsData getPressure() const;

private:
	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;
};