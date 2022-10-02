#include "CDisplay.h"

CDisplay::CDisplay(const CWeatherData& weatherDataIn, const CWeatherData& weatherDataOut)
	: m_weatherDataIn(weatherDataIn)
	, m_weatherDataOut(weatherDataOut)
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
	std::cout << prefix << std::endl;
	std::cout << "Current Temp " << data.temperature << std::endl;
	std::cout << "Current Hum " << data.humidity << std::endl;
	std::cout << "Current Pressure " << data.pressure << std::endl;
	std::cout << "----------------" << std::endl;
}
