#pragma once
#include "./../Condiments.h"

enum class LiquorType
{
	Nutty,
	Chocolate
};

class CLiquor : public CCondimentDecorator
{
public:
	CLiquor(IBeveragePtr&& beverage, LiquorType type = LiquorType::Nutty)
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
		return std::string(m_type == LiquorType::Nutty ? "Nutty" : "Chocolate")
			+ " liquor";
	}

private:
	LiquorType m_type;
};
