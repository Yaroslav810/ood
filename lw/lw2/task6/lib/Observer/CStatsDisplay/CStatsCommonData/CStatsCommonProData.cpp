#include "CStatsCommonProData.h"

CStatsCommonProData::CStatsCommonProData()
	: m_temperature("Temp")
	, m_humidity("Humidity")
	, m_pressure("Pressure")
	, m_wind()
{
}

void CStatsCommonProData::Update(const SWeatherInfo& data)
{
	m_temperature.Update(data.temperature);
	m_humidity.Update(data.humidity);
	m_pressure.Update(data.pressure);
	if (data.wind.has_value()) {
		m_wind.Update(data.wind.value());
	}
}

CStatsData CStatsCommonProData::GetTemperature() const
{
	return m_temperature;
}

CStatsData CStatsCommonProData::GetHumidity() const
{
	return m_humidity;
}

CStatsData CStatsCommonProData::GetPressure() const
{
	return m_pressure;
}

CStatsWindData CStatsCommonProData::GetWind() const
{
	return m_wind;
}
