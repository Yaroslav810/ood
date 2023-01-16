#include "CWeatherDataPro.h"

double CWeatherDataPro::GetTemperature() const
{
	return m_temperature;
}

double CWeatherDataPro::GetHumidity() const
{
	return m_humidity;
}

double CWeatherDataPro::GetPressure() const
{
	return m_pressure;
}

SWindInfo CWeatherDataPro::GetWind() const
{
	return m_wind;
}

void CWeatherDataPro::MeasurementsChanged()
{
	NotifyObservers();
}

void CWeatherDataPro::SetMeasurements(double temp, double humidity, double pressure, double speedWind, double directionWind)
{
	m_humidity = humidity;
	m_temperature = temp;
	m_pressure = pressure;
	m_wind = { speedWind, directionWind };

	MeasurementsChanged();
}

SWeatherInfo CWeatherDataPro::GetChangedData() const
{
	SWeatherInfo info;
	info.temperature = GetTemperature();
	info.humidity = GetHumidity();
	info.pressure = GetPressure();
	info.wind = GetWind();
	return info;
}
