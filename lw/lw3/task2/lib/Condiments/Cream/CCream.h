#pragma once
#include "./../Condiments.h"

class CCream : public CCondimentDecorator
{
public:
	CCream(IBeveragePtr&& beverage)
		: CCondimentDecorator(move(beverage))
	{
	}

	double GetCondimentCost() const override
	{
		return 25;
	}

	std::string GetCondimentDescription() const override
	{
		return "Cream";
	}
};
