#pragma once
#include "./../Beverages.h"

class CCoffee : public CBeverage
{
public:
	CCoffee(const std::string& description = "Coffee")
		: CBeverage(description)
	{
	}

	[[nodiscard]] double GetCost() const override
	{
		return 60;
	}
};
