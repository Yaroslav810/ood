#pragma once
#include "./../IDanceBehavior.h"
#include <iostream>

class CWaltzBehavior : public IDanceBehavior
{
public:
	void Dance() override;
};
