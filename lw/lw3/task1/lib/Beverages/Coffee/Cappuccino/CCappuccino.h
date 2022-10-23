#pragma once
#include "./../CCoffee.h"

// TODO: Переимеовать Size
enum class CappuccinoType
{
	Standard,
	Double
};

class CCappuccino : public CCoffee
{
public:
	CCappuccino(const CappuccinoType& type)
		: CCoffee("Cappuccino")
	{
		switch (type)
		{
		case CappuccinoType::Standard:
			m_cost = 80;
			m_description = "Standard";
			break;
		case CappuccinoType::Double:
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
