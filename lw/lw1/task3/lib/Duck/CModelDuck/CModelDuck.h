#pragma once
#include "../../DanceBehavior/WithoutDancingBehavior/WithoutDancingBehavior.h"
#include "./../../FlyBehavior/FlyNoWay/FlyNoWay.h"
#include "./../../QuackBehavior/QuackBehavior/QuackBehavior.h"
#include "./../CDuck/CDuck.h"
#include <iostream>
#include <memory>

class CModelDuck : public CDuck
{
public:
	CModelDuck();

	void Display() const override;
};
