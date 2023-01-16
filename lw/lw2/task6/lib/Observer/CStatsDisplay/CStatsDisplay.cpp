#include "CStatsDisplay.h"

CStatsDisplay::CStatsDisplay(IObservable<SWeatherInfo> const& weatherDataIn, IObservable<SWeatherInfo> const& weatherDataOut, std::ostream& output)
	: m_weatherDataIn(weatherDataIn)
	, m_weatherDataOut(weatherDataOut)
	, m_output(output)
{
}

void CStatsDisplay::Update(const SWeatherInfo& data, IObservable<SWeatherInfo> const& observable)
{
	if (&observable == &m_weatherDataIn)
	{
		m_statsCommonDataIn.Update(data);
		PrintCommonDataInStream(m_statsCommonDataIn);
	}

	if (&observable == &m_weatherDataOut)
	{
		m_statsCommonDataOut.Update(data);
		PrintCommonProDataInStream(m_statsCommonDataOut);
	}
}

void CStatsDisplay::PrintCommonDataInStream(CStatsCommonData const& data)
{
	PrintDataInStream(data.GetTemperature());
	PrintDataInStream(data.GetHumidity());
	PrintDataInStream(data.GetPressure());
}

void CStatsDisplay::PrintDataInStream(CStatsData const& data)
{
	auto statName = data.GetStatisticsName();
	m_output << "Max " << statName << " " << data.GetMaxData() << std::endl;
	m_output << "Min " << statName << " " << data.GetMinData() << std::endl;
	m_output << "Average " << statName << " " << data.GetAverageData() << std::endl;
	m_output << "----------------" << std::endl;
}

void CStatsDisplay::PrintCommonProDataInStream(const CStatsCommonProData& data)
{
	PrintDataInStream(data.GetTemperature());
	PrintDataInStream(data.GetHumidity());
	PrintDataInStream(data.GetPressure());
	PrintWindDataInStream(data.GetWind());
}

void CStatsDisplay::PrintWindDataInStream(CStatsWindData const& data)
{
	PrintDataInStream(data.GetWindSpeed());
	PrintWindDirectionDataInStream(data.GetDirectionWind());
}

void CStatsDisplay::PrintWindDirectionDataInStream(const CStatsWindDirectionData& data)
{
	std::cout << "Average Wind direction " << data.GetAverageData() << std::endl;
	std::cout << "----------------" << std::endl;
}
