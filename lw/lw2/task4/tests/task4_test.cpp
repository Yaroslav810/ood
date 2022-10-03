#define CATCH_CONFIG_MAIN
#include <utility>

#include "../../../../catch2/catch.hpp"
#include "../lib/Observable/CWeatherData/CWeatherData.h"
#include "../lib/Observer/CDisplay/CDisplay.h"

std::string GetDataString(std::string const& prefix, double temperature, double humidity, double pressure)
{
	std::stringstream ss;
	ss << prefix << std::endl;
	ss << "Current Temp " << temperature << std::endl;
	ss << "Current Hum " << humidity << std::endl;
	ss << "Current Pressure " << pressure << std::endl;
	ss << "----------------" << std::endl;
	return ss.str();
}

TEST_CASE("Monitoring of two CWeatherData")
{
	CWeatherData wdIn;
	CWeatherData wdOut;

	std::stringstream ss;

	CDisplay display(wdIn, wdOut, ss);
	wdIn.RegisterObserver(display, 0);
	wdOut.RegisterObserver(display, 0);

	REQUIRE_NOTHROW(wdIn.SetMeasurements(3, 0.7, 760));
	REQUIRE(ss.str() == GetDataString("In", 3, 0.7, 760));

	ss.str(std::string());

	REQUIRE_NOTHROW(wdOut.SetMeasurements(5, 1, 750));
	REQUIRE(ss.str() == GetDataString("Out", 5, 1, 750));

	ss.str(std::string());

	REQUIRE_NOTHROW(wdIn.SetMeasurements(3, 0.7, 760));
	REQUIRE(ss.str() == GetDataString("In", 3, 0.7, 760));
}
