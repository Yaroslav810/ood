#pragma once
#include "../../Observable/CWeatherData/CWeatherData.h"
#include "./../IObserver.h"
#include "./../SWeatherInfo.h"
#include "CStatsCommonData/CStatsCommonData.h"
#include "CStatsCommonData/CStatsCommonProData.h"
#include <iostream>

class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	CStatsDisplay(IObservable<SWeatherInfo> const& weatherDataIn, IObservable<SWeatherInfo> const& weatherDataOut, std::ostream& output);

private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data, IObservable<SWeatherInfo> const& observable) override;
	void PrintCommonDataInStream(CStatsCommonData const& data);
	void PrintDataInStream(CStatsData const& data);
	void PrintCommonProDataInStream(CStatsCommonProData const& data);
	void PrintWindDataInStream(CStatsWindData const& data);
	static void PrintWindDirectionDataInStream(const CStatsWindDirectionData& data);

	IObservable<SWeatherInfo> const& m_weatherDataIn;
	IObservable<SWeatherInfo> const& m_weatherDataOut;
	std::ostream& m_output;

	CStatsCommonData m_statsCommonDataIn;
	CStatsCommonProData m_statsCommonDataOut;
};
