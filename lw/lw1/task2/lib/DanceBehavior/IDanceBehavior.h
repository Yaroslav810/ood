#pragma once

struct IDanceBehavior
{
	virtual ~IDanceBehavior() = default;
	virtual void Dance() = 0;
};
