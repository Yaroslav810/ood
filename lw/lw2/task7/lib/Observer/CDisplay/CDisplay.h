#pragma once
#include "./../IObserver.h"
#include "./../SWeatherInfo.h"
#include <iostream>

class CDisplay : public IObserver<SWeatherInfo, EWeatherIndicator>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
	*/
	void Update(SWeatherInfo const& data, const EWeatherIndicator& indicator) override;
};
