#pragma once
#include "../../Observable/CWeatherData/CWeatherData.h"
#include "./../IObserver.h"
#include "./../SWeatherInfo.h"
#include <iostream>

class CDisplay : public IObserver<SWeatherInfo>
{
public:
	CDisplay(CWeatherData const& weatherDataIn, CWeatherData const& weatherDataOut);

private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
	*/
	void Update(SWeatherInfo const& data, IObservable<SWeatherInfo> const& observable) override;
	static void PrintDataInStream(SWeatherInfo const& data, std::string const& prefix);

	CWeatherData const& m_weatherDataIn;
	CWeatherData const& m_weatherDataOut;
};
