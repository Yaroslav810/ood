#pragma once
#include "../../DanceBehavior/CWithoutDancingBehavior/CWithoutDancingBehavior.h"
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
};
