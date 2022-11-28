#pragma once
#include "../CShape/CShape.h"

class CTriangle : public CShape
{
public:
	void Draw(ICanvas& canvas) const final;
};
