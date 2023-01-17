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
	UpdateChangedData(temp, humidity, pressure, speedWind, directionWind);
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

std::set<EWeatherIndicator> CWeatherData::GetIndicatorsData() const
{
	return m_changedData;
}

void CWeatherData::UpdateChangedData(double temp, double humidity, double pressure, double speedWind, double directionWind)
{
	m_changedData.clear();
	if (temp != m_temperature)
	{
		m_changedData.emplace(EWeatherIndicator::Temperature);
	}
	if (humidity != m_humidity)
	{
		m_changedData.emplace(EWeatherIndicator::Humidity);
	}
	if (pressure != m_pressure)
	{
		m_changedData.emplace(EWeatherIndicator::Pressure);
	}
	if (speedWind != m_wind.speed || directionWind != m_wind.direction)
	{
		m_changedData.emplace(EWeatherIndicator::Wind);
	}
}
