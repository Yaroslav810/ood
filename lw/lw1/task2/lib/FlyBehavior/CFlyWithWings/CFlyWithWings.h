#pragma once
#include "./../IFlyBehavior.h"
#include <iostream>

class CFlyWithWings : public IFlyBehavior
{
public:
	CFlyWithWings();
	void Fly() override;
	void ShowNumberOfFly() override;

private:
	std::size_t m_numberOfFly;
};
