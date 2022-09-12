#include "CRedheadDuck.h"

CRedheadDuck::CRedheadDuck()
	: CDuck(
		FlyWithWings(),
		QuackBehavior,
		MinuetBehavior)
{
}

void CRedheadDuck::Display() const
{
	std::cout << "I'm redhead duck" << std::endl;
}
