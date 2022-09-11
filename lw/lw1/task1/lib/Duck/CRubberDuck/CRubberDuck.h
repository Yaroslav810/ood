#pragma once
#include "./../../FlyBehavior/CFlyNoWay/CFlyNoWay.h"
#include "./../../QuackBehavior/CSqueakBehavior/CSqueakBehavior.h"
#include "./../CDuck/CDuck.h"
#include <iostream>
#include <memory>

class CRubberDuck : public CDuck
{
public:
	CRubberDuck();

	void Display() const override;

	void Dance() override;
};
