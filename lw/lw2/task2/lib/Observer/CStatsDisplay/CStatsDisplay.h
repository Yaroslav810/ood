#pragma once
#include "./../IObserver.h"
#include "./../SWeatherInfo.h"
#include "CStatsData/CStatsData.h"
#include <iostream>

class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	CStatsDisplay();

private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data) override;
	static void PrintDataInStream(CStatsData const& data);

	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;
};
