#pragma once
#include "./../CCoffee.h"

enum class LatteSize
{
	Standard,
	Double
};

class CLatte : public CCoffee
{
public:
	CLatte(const LatteSize& type)
		: CCoffee("Latte")
	{
		switch (type)
		{
		case LatteSize::Standard:
			m_cost = 90;
			m_description = "Standard";
			break;
		case LatteSize::Double:
			m_cost = 130;
			m_description = "Double";
			break;
		}
	}

	[[nodiscard]] double GetCost() const override
	{
		return m_cost;
	}

	[[nodiscard]] std::string GetDescription() const override
	{
		return CCoffee::GetDescription() + '(' + m_description + ')';
	}

private:
	std::string m_description;
	double m_cost;
};
