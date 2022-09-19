#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../lib/Observable/CWeatherData/CWeatherData.h"
#include "../lib/Observer/CDisplay/CDisplay.h"

TEST_CASE("Deleting an item in Update")
{
	class CTestUpdateDisplay : public IObserver<SWeatherInfo>
	{
	public:
		CTestUpdateDisplay(CWeatherData* weatherData)
			: m_observable(weatherData)
		{
		}

	private:
		/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
		*/
		void Update(SWeatherInfo const& data) override
		{
			m_observable->RemoveObserver(*this);
		}

		CWeatherData* m_observable;
	};

	CWeatherData wd;

	CTestUpdateDisplay testUpdateDisplay(&wd);
	wd.RegisterObserver(testUpdateDisplay);

	REQUIRE_NOTHROW(wd.SetMeasurements(3, 0.7, 760));
}
