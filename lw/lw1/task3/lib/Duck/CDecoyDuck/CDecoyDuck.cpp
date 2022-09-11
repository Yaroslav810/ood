#include "CDecoyDuck.h"

CDecoyDuck::CDecoyDuck()
	: CDuck(
		FlyNoWay,
		MuteQuackBehavior,
		WithoutDancingBehavior)
{
}

void CDecoyDuck::Display() const
{
	std::cout << "I'm decoy duck" << std::endl;
}
