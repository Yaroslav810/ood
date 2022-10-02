#include "CStatsCommonData.h"

CStatsCommonData::CStatsCommonData()
	: m_temperature("Temp")
	, m_humidity("Humidity")
	, m_pressure("Pressure")
{
}

void CStatsCommonData::Update(const SWeatherInfo& data)
{
	m_temperature.Update(data.temperature);
	m_humidity.Update(data.humidity);
	m_pressure.Update(data.pressure);
}

CStatsData CStatsCommonData::getTemperature() const
{
	return m_temperature;
}

CStatsData CStatsCommonData::getHumidity() const
{
	return m_humidity;
}

CStatsData CStatsCommonData::getPressure() const
{
	return m_pressure;
}
