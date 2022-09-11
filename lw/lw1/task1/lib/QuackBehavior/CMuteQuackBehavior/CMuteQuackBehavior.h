#pragma once
#include "./../IQuackBehavior.h"
#include <iostream>

class CMuteQuackBehavior : public IQuackBehavior
{
public:
	void Quack() override;
};
