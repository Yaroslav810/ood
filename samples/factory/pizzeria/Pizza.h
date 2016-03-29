﻿#pragma once
#include <iostream>

// Базовый класс Пиццы
class CPizza
{
public:
	virtual ~CPizza() = default;
	virtual void Prepare() = 0;

	void Bake()
	{
		std::cout << "Bake for 25 minutes at 350''\n";
	}

	virtual void Cut()
	{
		std::cout << "Cutting the pizza into diagonal slices\n";
	}

	virtual void Box()
	{
		std::cout << "Place pizza in official CPizzaStore box\n";
	}
};

/*
 Классические типы пиццы
*/

// Сырная пицца
class CCheezePizza : public CPizza
{
public:
	void Prepare() override
	{
		std::cout << "Putting some mozzarella cheese\n";
	}
};

// Пепперони
class CPeperoniPizza : public CPizza
{
public:
	void Prepare() override
	{
		std::cout << "Putting some tomato sauce, mozzarella, peperoni\n";
	}
};

// Неаполитанская
class CNapolitanaPizza : public CPizza
{
public:
	void Prepare() override
	{
		std::cout << "Putting some tomato sauce, anchovies, olives, capers\n";
	}
};

/*
Модификации пиццы, предпочитаемые жителями Нью-Йорка
*/

// Сырная
class CNYCheezePizza : public CCheezePizza
{
public:
	void Prepare() override
	{
		std::cout << "Putting a little mozzarella cheese on a slim piece of dough\n";
	}
};

// Пеперони
class CNYPeperoniPizza : public CPeperoniPizza
{
public:
	void Prepare() override
	{
		std::cout << "Putting some tomato sauce, mozzarella, peperoni on a slim piece of dough\n";
	}
};

// Неаполитанская
class CNYNapolitanaPizza : public CNapolitanaPizza
{
public:
	void Prepare() override
	{
		std::cout << "Putting some tomato sauce, anchovies, olives, capers on a slim piece of dough\n";
	}
};

