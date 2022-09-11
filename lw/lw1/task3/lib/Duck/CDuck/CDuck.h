#pragma once
#include <cassert>
#include <functional>
#include <iostream>
#include <memory>

class CDuck
{
public:
	using Strategy = std::function<void()>;

	CDuck(Strategy flyBehavior,
		Strategy quackBehavior,
		Strategy danceBehavior);
	void Quack() const;
	void Fly() const;
	void Dance() const;
	static void Swim();

	void SetFlyBehavior(Strategy&& flyBehavior);

	virtual void Display() const = 0;
	virtual ~CDuck() = default;

private:
	Strategy m_flyBehavior;
	Strategy m_quackBehavior;
	Strategy m_danceBehavior;
};
