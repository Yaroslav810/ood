#pragma once
#include "./../Condiments.h"

// Тип сиропа
enum class SyrupType
{
	Chocolate, // Шоколадный
	Maple, // Кленовый
};

// Добавка "Сироп"
class CSyrup : public CCondimentDecorator
{
public:
	CSyrup(IBeveragePtr&& beverage, SyrupType syrupType)
		: CCondimentDecorator(move(beverage))
		, m_syrupType(syrupType)
	{
	}

protected:
	[[nodiscard]] double GetCondimentCost() const override
	{
		return 15;
	}
	[[nodiscard]] std::string GetCondimentDescription() const override
	{
		return std::string(m_syrupType == SyrupType::Chocolate ? "Chocolate" : "Maple")
			+ " syrup";
	}

private:
	SyrupType m_syrupType;
};
