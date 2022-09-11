#pragma once
#include "../../DanceBehavior/CMinuetBehavior/CMinuetBehavior.h"
#include "./../../FlyBehavior/CFlyWithWings/CFlyWithWings.h"
#include "./../../QuackBehavior/CQuackBehavior/CQuackBehavior.h"
#include "./../CDuck/CDuck.h"
#include <iostream>
#include <memory>

class CRedheadDuck : public CDuck
{
public:
	CRedheadDuck();

	void Display() const override;
};
