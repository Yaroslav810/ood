#pragma once
#include "./../IObserver.h"
#include "./../SWeatherInfo.h"
#include "CStatsData/CStatsData.h"
#include "CStatsWindData/CStatsWindData.h"
#include <iostream>

class CStatsDisplay : public IObserver<SWeatherInfo, EWeatherIndicator>
{
public:
	CStatsDisplay();

private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data, const EWeatherIndicator& indicator) override;
	static void PrintDataInStream(CStatsData const& data);
	void PrintWindDataInStream();
	static void PrintWindDirectionDataInStream(const CStatsWindDirectionData& data);

	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;
	CStatsWindData m_wind;
};
