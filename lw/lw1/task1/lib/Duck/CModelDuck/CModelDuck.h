#pragma once
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

	void Dance() override;
};
