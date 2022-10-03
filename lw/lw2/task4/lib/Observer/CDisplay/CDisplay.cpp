#include "CDisplay.h"

CDisplay::CDisplay(const CWeatherData& weatherDataIn, const CWeatherData& weatherDataOut, std::ostream& output)
	: m_weatherDataIn(weatherDataIn)
	, m_weatherDataOut(weatherDataOut)
	, m_output(output)
{
}

void CDisplay::Update(SWeatherInfo const& data, IObservable<SWeatherInfo> const& observable)
{
	if (&observable == &m_weatherDataIn)
	{
		PrintDataInStream(data, "In");
	}

	if (&observable == &m_weatherDataOut)
	{
		PrintDataInStream(data, "Out");
	}
}

void CDisplay::PrintDataInStream(SWeatherInfo const& data, std::string const& prefix)
{
	m_output << prefix << std::endl;
	m_output << "Current Temp " << data.temperature << std::endl;
	m_output << "Current Hum " << data.humidity << std::endl;
	m_output << "Current Pressure " << data.pressure << std::endl;
	m_output << "----------------" << std::endl;
}
