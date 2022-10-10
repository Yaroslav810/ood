#pragma once
#include "./../Beverages.h"

enum class MilkshakeType
{
	Small,
	Medium,
	Big
};

class CMilkshake : public CBeverage
{
public:
	CMilkshake(const MilkshakeType& type)
		: CBeverage("Milkshake")
	{
		switch (type)
		{
		case MilkshakeType::Small:
			m_description = "Small";
			m_cost = 50;
			break;
		case MilkshakeType::Medium:
			m_description = "Medium";
			m_cost = 60;
			break;
		case MilkshakeType::Big:
			m_description = "Big";
			m_cost = 80;
			break;
		}
	}

	[[nodiscard]] double GetCost() const override
	{
		return m_cost;
	}

	[[nodiscard]] std::string GetDescription() const override
	{
		return CBeverage::GetDescription() + '(' + m_description + ')';
	}

private:
	std::string m_description;
	double m_cost;
};
