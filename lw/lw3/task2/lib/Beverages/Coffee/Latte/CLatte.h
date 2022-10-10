#pragma once
#include "./../CCoffee.h"

enum class LatteType
{
	Standard,
	Double
};

class CLatte : public CCoffee
{
public:
	CLatte(const LatteType& type)
		: CCoffee("Latte")
	{
		switch (type)
		{
		case LatteType::Standard:
			m_cost = 90;
			m_description = "Standard";
			break;
		case LatteType::Double:
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
