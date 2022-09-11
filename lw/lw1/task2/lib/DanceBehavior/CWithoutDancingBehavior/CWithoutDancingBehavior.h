#pragma once
#include "./../IDanceBehavior.h"
#include <iostream>

class CWithoutDancingBehavior : public IDanceBehavior
{
public:
	void Dance() override;
};
