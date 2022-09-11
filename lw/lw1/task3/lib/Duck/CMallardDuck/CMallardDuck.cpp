#include "CMallardDuck.h"

CMallardDuck::CMallardDuck()
	: CDuck(
		FlyWithWings,
		QuackBehavior,
		WaltzBehavior)
{
}

void CMallardDuck::Display() const
{
	std::cout << "I'm mallard duck" << std::endl;
}
