#pragma once

struct IFlyBehavior
{
	virtual ~IFlyBehavior() = default;
	virtual void Fly() = 0;
};
