#include "CDecoyDuck.h"

CDecoyDuck::CDecoyDuck()
	: CDuck(
		std::make_unique<CFlyNoWay>(),
		std::make_unique<CMuteQuackBehavior>())
{
}

void CDecoyDuck::Display() const
{
	std::cout << "I'm decoy duck" << std::endl;
}

void CDecoyDuck::Dance() {}
