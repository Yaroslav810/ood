#pragma once
#include "../CShape/CShape.h"

class CTriangle : public CShape
{
public:
	void Draw(const ICanvas& canvas) final;
};
