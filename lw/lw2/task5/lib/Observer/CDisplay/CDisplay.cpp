#include "CDisplay.h"

void CDisplay::Update(const SWeatherInfo& data)
{
	std::cout << "Current Temp " << data.temperature << std::endl;
	std::cout << "Current Hum " << data.humidity << std::endl;
	std::cout << "Current Pressure " << data.pressure << std::endl;
	std::cout << "Current Wind speed: " << data.wind.speed << "; direction: " << data.wind.direction << std::endl;
	std::cout << "----------------" << std::endl;
}
