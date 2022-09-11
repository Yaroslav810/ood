#pragma once
#include "./../IFlyBehavior.h"
#include <iostream>

class CFlyNoWay : public IFlyBehavior
{
public:
	void Fly() override;
};
