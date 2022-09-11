#pragma once
#include "./../IDanceBehavior.h"
#include <iostream>

class CMinuetBehavior : public IDanceBehavior
{
public:
	void Dance() override;
};
