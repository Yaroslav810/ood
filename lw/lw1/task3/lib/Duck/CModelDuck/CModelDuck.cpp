#include "CModelDuck.h"

CModelDuck::CModelDuck()
	: CDuck(
		FlyNoWay,
		QuackBehavior,
		WithoutDancingBehavior)
{
}

void CModelDuck::Display() const
{
	std::cout << "I'm model duck" << std::endl;
}
