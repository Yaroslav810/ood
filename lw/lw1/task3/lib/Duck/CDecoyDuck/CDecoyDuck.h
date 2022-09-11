#pragma once
#include "../../DanceBehavior/WithoutDancingBehavior/WithoutDancingBehavior.h"
#include "./../../FlyBehavior/FlyNoWay/FlyNoWay.h"
#include "./../../QuackBehavior/MuteQuackBehavior/MuteQuackBehavior.h"
#include "./../CDuck/CDuck.h"
#include <iostream>
#include <memory>

class CDecoyDuck : public CDuck
{
public:
	CDecoyDuck();

	void Display() const override;
};
