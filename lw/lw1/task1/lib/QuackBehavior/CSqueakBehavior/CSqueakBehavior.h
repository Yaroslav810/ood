#pragma once
#include "./../IQuackBehavior.h"
#include <iostream>

class CSqueakBehavior : public IQuackBehavior
{
public:
	void Quack() override;
};
