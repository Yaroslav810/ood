#pragma once
#include "./../../FlyBehavior/CFlyNoWay/CFlyNoWay.h"
#include "./../../QuackBehavior/CMuteQuackBehavior/CMuteQuackBehavior.h"
#include "./../CDuck/CDuck.h"
#include <iostream>
#include <memory>

class CDecoyDuck : public CDuck
{
public:
	CDecoyDuck();

	void Display() const override;

	void Dance() override;
};
