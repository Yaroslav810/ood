#pragma once

struct IQuackBehavior
{
	virtual ~IQuackBehavior() = default;
	virtual void Quack() = 0;
};
