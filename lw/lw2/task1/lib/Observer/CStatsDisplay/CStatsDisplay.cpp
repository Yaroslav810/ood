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

	PrintDataInStream(m_temperature);
	PrintDataInStream(m_humidity);
	PrintDataInStream(m_pressure);
}

void CStatsDisplay::PrintDataInStream(const CStatsData& data)
{
	auto statName = data.GetStatisticsName();
	std::cout << "Max " << statName << " " << data.GetMaxData() << std::endl;
	std::cout << "Min " << statName << " " << data.GetMinData() << std::endl;
	std::cout << "Average " << statName << " " << data.GetAverageData() << std::endl;
	std::cout << "----------------" << std::endl;
}
