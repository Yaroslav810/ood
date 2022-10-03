#include "CWeatherData.h"

double CWeatherData::GetTemperature() const
{
	return m_temperature;
}

double CWeatherData::GetHumidity() const
{
	return m_humidity;
}

double CWeatherData::GetPressure() const
{
	return m_pressure;
}

SWindInfo CWeatherData::GetWind() const
{
	return m_wind;
}

void CWeatherData::MeasurementsChanged()
{
	NotifyObservers();
}

void CWeatherData::SetMeasurements(double temp, double humidity, double pressure, double speedWind, double directionWind)
{
	m_humidity = humidity;
	m_temperature = temp;
	m_pressure = pressure;
	m_wind = { speedWind, directionWind };

	MeasurementsChanged();
}

SWeatherInfo CWeatherData::GetChangedData() const
{
	SWeatherInfo info;
	info.temperature = GetTemperature();
	info.humidity = GetHumidity();
	info.pressure = GetPressure();
	info.wind = GetWind();
	return info;
}
