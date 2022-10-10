#pragma once
#include "./../Condiments.h"

const unsigned MAX_QUANTITY = 5;

class CChocolate : public CCondimentDecorator
{
public:
	CChocolate(IBeveragePtr&& beverage, unsigned quantity = 1)
		: CCondimentDecorator(move(beverage))
		, m_quantity(std::min(quantity, MAX_QUANTITY))
	{
	}

protected:
	[[nodiscard]] double GetCondimentCost() const override
	{
		return 10.0 * m_quantity;
	}
	[[nodiscard]] std::string GetCondimentDescription() const override
	{
		return "Chocolate x " + std::to_string(m_quantity);
	}

private:
	unsigned m_quantity;
};