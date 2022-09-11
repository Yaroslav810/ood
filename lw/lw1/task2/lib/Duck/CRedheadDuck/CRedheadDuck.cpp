#include "CRedheadDuck.h"

CRedheadDuck::CRedheadDuck()
	: CDuck(
		std::make_unique<CFlyWithWings>(),
		std::make_unique<CQuackBehavior>(),
		std::make_unique<CMinuetBehavior>())
{
}

void CRedheadDuck::Display() const
{
	std::cout << "I'm redhead duck" << std::endl;
}
