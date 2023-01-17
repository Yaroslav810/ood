#include "CDisplay.h"

void CDisplay::Update(const SWeatherInfo& data, const EWeatherIndicator& indicator)
{
	if (indicator == EWeatherIndicator::Temperature) {
		std::cout << "Current Temp " << data.temperature << std::endl;
	}
	if (indicator == EWeatherIndicator::Humidity) {
		std::cout << "Current Hum " << data.humidity << std::endl;
	}
	if (indicator == EWeatherIndicator::Pressure) {
		std::cout << "Current Pressure " << data.pressure << std::endl;
	}
	if (indicator == EWeatherIndicator::Wind) {
		std::cout << "Current Wind speed: " << data.wind.speed << "; direction: " << data.wind.direction << std::endl;
	}
	std::cout << "----------------" << std::endl;
}
