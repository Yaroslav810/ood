#pragma once
#include "../CShape/CShape.h"

class CRectangle : public CShape
{
public:
	void Draw(ICanvas& canvas) const final;
};