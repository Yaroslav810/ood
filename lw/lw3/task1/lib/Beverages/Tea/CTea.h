#pragma once
#include "./../Beverages.h"

enum class TeaType
{
	Black,
	Oolong,
	Puer,
	EarlGrey
};

class CTea : public CBeverage
{
public:
	CTea(const TeaType& type)
		: CBeverage("Tea")
	{
		switch (type)
		{
		case TeaType::Black:
			m_description = "Black";
			break;
		case TeaType::Oolong:
			m_description = "Oolong";
			break;
		case TeaType::Puer:
			m_description = "Puer";
			break;
		case TeaType::EarlGrey:
			m_description = "EarlGrey";
			break;
		}
	}

	[[nodiscard]] double GetCost() const override
	{
		return 30;
	}

	[[nodiscard]] std::string GetDescription() const override
	{
		return CBeverage::GetDescription() + '(' + m_description + ')';
	}

private:
	std::string m_description;
};
