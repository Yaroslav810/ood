#include "CStatsDisplay.h"

CStatsDisplay::CStatsDisplay()
	: m_temperature("Temp")
	, m_humidity("Humidity")
	, m_pressure("Pressure")
	, m_wind()
{
}

void CStatsDisplay::Update(const SWeatherInfo& data)
{
	m_temperature.Update(data.temperature);
	m_humidity.Update(data.humidity);
	m_pressure.Update(data.pressure);
	m_wind.Update(data.wind);

	PrintDataInStream(m_temperature);
	PrintDataInStream(m_humidity);
	PrintDataInStream(m_pressure);
	PrintWindDataInStream();
}

void CStatsDisplay::PrintDataInStream(const CStatsData& data)
{
	auto statName = data.getStatisticsName();
	std::cout << "Max " << statName << " " << data.getMaxData() << std::endl;
	std::cout << "Min " << statName << " " << data.getMinData() << std::endl;
	std::cout << "Average " << statName << " " << data.getAverageData() << std::endl;
	std::cout << "----------------" << std::endl;
}

void CStatsDisplay::PrintWindDirectionDataInStream(const CStatsWindDirectionData& data)
{
	std::cout << "Average Wind direction " << data.getAverageData() << std::endl;
	std::cout << "----------------" << std::endl;
}

void CStatsDisplay::PrintWindDataInStream()
{
	PrintDataInStream(m_wind.getSpeedWind()); // TODO: getWindSpeed
	PrintWindDirectionDataInStream(m_wind.getDirectionWind()); // TODO: Upper
}
