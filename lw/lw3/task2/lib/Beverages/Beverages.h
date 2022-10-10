#pragma once
#include "IBeverage.h"
#include <utility>

// Базовая реализация напитка, предоставляющая его описание
class CBeverage : public IBeverage
{
public:
	CBeverage(std::string description)
		: m_description(std::move(description))
	{
	}

	[[nodiscard]] std::string GetDescription() const override
	{
		return m_description;
	}

private:
	std::string m_description;
};
