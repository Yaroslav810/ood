#define CATCH_CONFIG_MAIN
#include <utility>

#include "../../../../catch2/catch.hpp"
#include "../lib/Observable/CWeatherData/CWeatherData.h"
#include "../lib/Observer/CDisplay/CDisplay.h"

TEST_CASE("Priority of the observers")
{
	class CTestPriorityDisplay : public IObserver<SWeatherInfo>
	{
	public:
		CTestPriorityDisplay(std::string&& str, std::stringstream& ss)
			: m_str(str)
			, m_ss(ss)
		{
		}

	private:
		/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
		*/
		void Update(SWeatherInfo const& data) override
		{
			m_ss << m_str;
		}

		std::string m_str;
		std::stringstream& m_ss;
	};

	CWeatherData wd;

	std::stringstream ss;

	CTestPriorityDisplay testFirstDisplay("1", ss);
	CTestPriorityDisplay testSecondDisplay("2", ss);
	CTestPriorityDisplay testThirdDisplay("3", ss);
	CTestPriorityDisplay testFourthDisplay("4", ss);

	wd.RegisterObserver(testFirstDisplay, 0);
	wd.RegisterObserver(testSecondDisplay, 1);
	wd.RegisterObserver(testThirdDisplay, 2);
	wd.RegisterObserver(testFourthDisplay, 3);

	REQUIRE_NOTHROW(wd.SetMeasurements(3, 0.7, 760));
	REQUIRE(ss.str() == "4321");
}
