#include "CStatsDisplay.h"

CStatsDisplay::CStatsDisplay()
	: m_temperature("Temp")
	, m_humidity("Humidity")
	, m_pressure("Pressure")
{
}

void CStatsDisplay::Update(const SWeatherInfo& data)
{
	m_temperature.Update(data.temperature);
	m_humidity.Update(data.humidity);
	m_pressure.Update(data.pressure);

	// TODO: Сделать вывод тут
}
