#include "lib/Observable/CWeatherData/CWeatherData.h"
#include "lib/Observer/CDisplay/CDisplay.h"
#include "lib/Observer/CStatsDisplay/CStatsDisplay.h"

int main()
{
	CWeatherData wdIn;
	CWeatherData wdOut;

	CDisplay display(wdIn, wdOut, std::cout);
	wdIn.RegisterObserver(display, 0);
	wdOut.RegisterObserver(display, 0);

	CStatsDisplay statsDisplay(wdIn, wdOut, std::cout);
	wdIn.RegisterObserver(statsDisplay, 0);
	wdOut.RegisterObserver(statsDisplay, 0);

	wdIn.SetMeasurements(3, 0.7, 760);
	wdIn.SetMeasurements(4, 0.8, 761);
	wdOut.SetMeasurements(0, 0, 0);
	wdOut.SetMeasurements(1, 1, 1);

	wdIn.RemoveObserver(statsDisplay);

	wdIn.SetMeasurements(10, 0.8, 761);
	wdIn.SetMeasurements(-10, 0.8, 761);
	return 0;
}
