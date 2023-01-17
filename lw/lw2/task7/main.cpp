#include "lib/Observable/CWeatherData/CWeatherData.h"
#include "lib/Observer/CDisplay/CDisplay.h"
#include "lib/Observer/CStatsDisplay/CStatsDisplay.h"

int main()
{
	CWeatherData wd;

	CDisplay display;
	wd.RegisterObserver(display, EWeatherIndicator::Temperature);

	CStatsDisplay statsDisplay;
	wd.RegisterObserver(statsDisplay, EWeatherIndicator::Pressure);

	wd.SetMeasurements(3, 0.7, 760, 5, 1);
	wd.SetMeasurements(4, 0.8, 761, 10, 359);

	wd.RemoveObserver(statsDisplay);

	wd.SetMeasurements(10, 0.8, 761, 10, 90);
	wd.SetMeasurements(-10, 0.8, 761, 10, 270);
	return 0;
}
