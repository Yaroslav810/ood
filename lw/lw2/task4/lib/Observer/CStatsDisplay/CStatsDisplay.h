#pragma once
#include "../../Observable/CWeatherData/CWeatherData.h"
#include "./../IObserver.h"
#include "./../SWeatherInfo.h"
#include "CStatsCommonData/CStatsCommonData.h"
#include <iostream>

class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	CStatsDisplay(IObservable<SWeatherInfo> const& weatherDataIn, IObservable<SWeatherInfo> const& weatherDataOut);

private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data, IObservable<SWeatherInfo> const& observable) override;
	static void PrintCommonDataInStream(CStatsCommonData const& data);
	static void PrintDataInStream(CStatsData const& data);

	IObservable<SWeatherInfo> const& m_weatherDataIn;
	IObservable<SWeatherInfo> const& m_weatherDataOut;

	CStatsCommonData m_statsCommonDataIn;
	CStatsCommonData m_statsCommonDataOut;
};
