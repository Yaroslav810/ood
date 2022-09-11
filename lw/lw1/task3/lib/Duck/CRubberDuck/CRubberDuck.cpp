#include "CRubberDuck.h"

CRubberDuck::CRubberDuck()
	: CDuck(
		FlyNoWay,
		SqueakBehavior,
		WithoutDancingBehavior)
{
}

void CRubberDuck::Display() const
{
	std::cout << "I'm rubber duck" << std::endl;
}
