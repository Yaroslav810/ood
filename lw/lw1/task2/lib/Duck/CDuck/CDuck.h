#pragma once
#include "../../DanceBehavior/IDanceBehavior.h"
#include "../../FlyBehavior/IFlyBehavior.h"
#include "../../QuackBehavior/IQuackBehavior.h"
#include <cassert>
#include <iostream>
#include <memory>

class CDuck
{
public:
	CDuck(std::unique_ptr<IFlyBehavior>&& flyBehavior,
		std::unique_ptr<IQuackBehavior>&& quackBehavior,
		std::unique_ptr<IDanceBehavior>&& danceBehavior);
	void Quack() const;
	void Fly() const;
	void Dance() const;
	static void Swim();

	void SetFlyBehavior(std::unique_ptr<IFlyBehavior>&& flyBehavior);
	void ShowNumberOfFly() const;

	virtual void Display() const = 0;
	virtual ~CDuck() = default;

private:
	std::unique_ptr<IFlyBehavior> m_flyBehavior;
	std::unique_ptr<IQuackBehavior> m_quackBehavior;
	std::unique_ptr<IDanceBehavior> m_danceBehavior;
};
