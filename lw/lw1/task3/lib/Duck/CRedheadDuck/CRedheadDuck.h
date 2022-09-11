#pragma once
#include "../../DanceBehavior/MinuetBehavior/MinuetBehavior.h"
#include "./../../FlyBehavior/FlyWithWings/FlyWithWings.h"
#include "./../../QuackBehavior/QuackBehavior/QuackBehavior.h"
#include "./../CDuck/CDuck.h"
#include <iostream>
#include <memory>

class CRedheadDuck : public CDuck
{
public:
	CRedheadDuck();

	void Display() const override;
};
