#include "lib/Duck/CDecoyDuck/CDecoyDuck.h"
#include "lib/Duck/CDuck/CDuck.h"
#include "lib/Duck/CMallardDuck/CMallardDuck.h"
#include "lib/Duck/CModelDuck/CModelDuck.h"
#include "lib/Duck/CRedheadDuck/CRedheadDuck.h"
#include "lib/Duck/CRubberDuck/CRubberDuck.h"
#include <iostream>

void DrawDuck(CDuck const& duck)
{
	duck.Display();
}

void PlayWithDuck(CDuck& duck)
{
	DrawDuck(duck);
	duck.Quack();
	duck.Fly();
	duck.Dance();
	CDuck::Swim();
	std::cout << std::endl;
}

int main()
{
	CMallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);

	CRedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);

	CRubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);

	CDecoyDuck decoyDuck;
	PlayWithDuck(decoyDuck);

	CModelDuck modelDuck;
	PlayWithDuck(modelDuck);
	modelDuck.SetFlyBehavior(FlyWithWings);
	PlayWithDuck(modelDuck);
}
