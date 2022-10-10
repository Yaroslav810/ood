#pragma once
#include "./../Condiments.h"

class CCinnamon : public CCondimentDecorator
{
public:
	CCinnamon(IBeveragePtr&& beverage)
		: CCondimentDecorator(move(beverage))
	{
	}

protected:
	[[nodiscard]] double GetCondimentCost() const override
	{
		return 20;
	}

	[[nodiscard]] std::string GetCondimentDescription() const override
	{
		return "Cinnamon";
	}
};
