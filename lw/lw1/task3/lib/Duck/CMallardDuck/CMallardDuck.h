#pragma once
#include "../../DanceBehavior/WaltzBehavior/WaltzBehavior.h"
#include "./../../FlyBehavior/FlyWithWings/FlyWithWings.h"
#include "./../../QuackBehavior/QuackBehavior/QuackBehavior.h"
#include "./../CDuck/CDuck.h"
#include <iostream>
#include <memory>

class CMallardDuck : public CDuck
{
public:
	CMallardDuck();

	void Display() const override;
};
