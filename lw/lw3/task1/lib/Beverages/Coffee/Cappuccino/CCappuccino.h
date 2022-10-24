#pragma once
#include "./../CCoffee.h"

enum class CappuccinoSize
{
	Standard,
	Double
};

class CCappuccino : public CCoffee
{
public:
	CCappuccino(const CappuccinoSize& type)
		: CCoffee("Cappuccino")
	{
		switch (type)
		{
		case CappuccinoSize::Standard:
			m_cost = 80;
			m_description = "Standard";
			break;
		case CappuccinoSize::Double:
			m_cost = 120;
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
