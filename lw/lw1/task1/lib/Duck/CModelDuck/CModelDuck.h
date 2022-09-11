#pragma once
#include "../../DanceBehavior/CWithoutDancingBehavior/CWithoutDancingBehavior.h"
#include "./../../FlyBehavior/CFlyNoWay/CFlyNoWay.h"
#include "./../../QuackBehavior/CQuackBehavior/CQuackBehavior.h"
#include "./../CDuck/CDuck.h"
#include <iostream>
#include <memory>

class CModelDuck : public CDuck
{
public:
	CModelDuck();

	void Display() const override;
};
