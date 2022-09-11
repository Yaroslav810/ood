#pragma once
#include "./../IQuackBehavior.h"
#include <iostream>

class CQuackBehavior : public IQuackBehavior
{
public:
	void Quack() override;
};
