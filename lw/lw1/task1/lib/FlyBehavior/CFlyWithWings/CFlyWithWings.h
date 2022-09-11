#pragma once
#include "./../IFlyBehavior.h"
#include <iostream>

class CFlyWithWings : public IFlyBehavior
{
public:
	void Fly() override;
};
