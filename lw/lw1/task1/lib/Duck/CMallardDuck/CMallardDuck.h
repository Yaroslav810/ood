#pragma once
#include "../../DanceBehavior/CWaltzBehavior/CWaltzBehavior.h"
#include "./../../FlyBehavior/CFlyWithWings/CFlyWithWings.h"
#include "./../../QuackBehavior/CQuackBehavior/CQuackBehavior.h"
#include "./../CDuck/CDuck.h"
#include <iostream>
#include <memory>

class CMallardDuck : public CDuck
{
public:
	CMallardDuck();

	void Display() const override;
};
