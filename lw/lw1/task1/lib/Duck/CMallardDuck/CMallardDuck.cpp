#include "CMallardDuck.h"

CMallardDuck::CMallardDuck()
	: CDuck(
		std::make_unique<CFlyWithWings>(),
		std::make_unique<CQuackBehavior>())
{
}

void CMallardDuck::Display() const
{
	std::cout << "I'm mallard duck" << std::endl;
}
