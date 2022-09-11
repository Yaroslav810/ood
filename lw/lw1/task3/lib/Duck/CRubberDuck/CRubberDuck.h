#pragma once
#include "../../DanceBehavior/WithoutDancingBehavior/WithoutDancingBehavior.h"
#include "./../../FlyBehavior/FlyNoWay/FlyNoWay.h"
#include "./../../QuackBehavior/SqueakBehavior/SqueakBehavior.h"
#include "./../CDuck/CDuck.h"
#include <iostream>
#include <memory>

class CRubberDuck : public CDuck
{
public:
	CRubberDuck();

	void Display() const override;
};
