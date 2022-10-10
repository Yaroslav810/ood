#pragma once
#include "./../Condiments.h"

class CLemon : public CCondimentDecorator
{
public:
	CLemon(IBeveragePtr&& beverage, unsigned quantity = 1)
		: CCondimentDecorator(move(beverage))
		, m_quantity(quantity)
	{
	}

protected:
	[[nodiscard]] double GetCondimentCost() const override
	{
		return 10.0 * m_quantity;
	}
	[[nodiscard]] std::string GetCondimentDescription() const override
	{
		return "Lemon x " + std::to_string(m_quantity);
	}

private:
	unsigned m_quantity;
};
