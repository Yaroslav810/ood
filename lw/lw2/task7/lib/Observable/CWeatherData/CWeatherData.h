#pragma once
#include "./../../Observer/SWeatherInfo.h"
#include "./../CObservable.h"

class CWeatherData : public CObservable<SWeatherInfo, EWeatherIndicator>
{
public:
	// Температура в градусах Цельсия
	[[nodiscard]] double GetTemperature() const;

	// Относительная влажность (0...100)
	[[nodiscard]] double GetHumidity() const;

	// Атмосферное давление (в мм.рт.ст)
	[[nodiscard]] double GetPressure() const;

	// Скорость и направление ветра
	[[nodiscard]] SWindInfo GetWind() const;

	void MeasurementsChanged();

	void SetMeasurements(double temp, double humidity, double pressure, double speedWind, double directionWind);

protected:
	[[nodiscard]] SWeatherInfo GetChangedData() const override;
	[[nodiscard]] std::set<EWeatherIndicator> GetIndicatorsData() const override;

private:
	void UpdateChangedData(double temp, double humidity, double pressure, double speedWind, double directionWind);
	std::set<EWeatherIndicator> m_changedData;

	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;
	SWindInfo m_wind;
};