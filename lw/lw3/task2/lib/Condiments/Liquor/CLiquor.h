#pragma once
#include "./../Condiments.h"

enum class LiquorTaste
{
	Nutty,
	Chocolate
};

class CLiquor : public CCondimentDecorator
{
public:
	CLiquor(IBeveragePtr&& beverage, LiquorTaste type = LiquorTaste::Nutty)
		: CCondimentDecorator(move(beverage))
		, m_type(type)
	{
	}

protected:
	[[nodiscard]] double GetCondimentCost() const override
	{
		return 50;
	}

	[[nodiscard]] std::string GetCondimentDescription() const override
	{
		return std::string(m_type == LiquorTaste::Nutty ? "Nutty" : "Chocolate")
			+ " liquor";
	}

private:
	LiquorTaste m_type;
};
