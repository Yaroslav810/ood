#pragma once
#include "./../../Observer/SWeatherInfo.h"
#include "./../CObservable.h"

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
	// Температура в градусах Цельсия
	[[nodiscard]] double GetTemperature() const;

	// Относительная влажность (0...100)
	[[nodiscard]] double GetHumidity() const;

	// Атмосферное давление (в мм.рт.ст)
	[[nodiscard]] double GetPressure() const;

	void MeasurementsChanged();

	void SetMeasurements(double temp, double humidity, double pressure);

protected:
	[[nodiscard]] SWeatherInfo GetChangedData() const override;

private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;
};
