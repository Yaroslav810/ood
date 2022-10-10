#pragma once
#include "./../Condiments.h"

// Шоколадная крошка
class CChocolateCrumbs : public CCondimentDecorator
{
public:
	CChocolateCrumbs(IBeveragePtr&& beverage, unsigned mass)
		: CCondimentDecorator(move(beverage))
		, m_mass(mass)
	{
	}

	[[nodiscard]] double GetCondimentCost() const override
	{
		return 2.0 * m_mass;
	}

	[[nodiscard]] std::string GetCondimentDescription() const override
	{
		return "Chocolate crumbs " + std::to_string(m_mass) + "g";
	}

private:
	unsigned m_mass;
};
