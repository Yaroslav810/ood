#pragma once
#include "../Color/Color.h"
#include "../Point/CPoint.h"

class ICanvas
{
public:
	virtual void SetColor(const Color& color) = 0;
	virtual void DrawLine(const CPoint& from, const CPoint& to) = 0;
	virtual void DrawEllipse(const CPoint& center, double width, double height) = 0;
	virtual ~ICanvas() = default;
};
