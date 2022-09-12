#include "FlyWithWings.h"

std::function<void()> FlyWithWings()
{
	std::size_t flyCount = 0;

	return [flyCount]() mutable {
		++flyCount;
		std::cout << "I'm flying with wings!!" << std::endl;
		std::cout << "I've been out " << flyCount << " times" << std::endl;
	};
}
