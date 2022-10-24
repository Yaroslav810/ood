#pragma once
#include "../Color/Color.h"
#include "ICanvas.h"
#include <iostream>

class CCanvas : public ICanvas
{
public:
	void SetColor(const Color& color) override;
	void DrawLine(const CPoint& from, const CPoint& to) override;
	void DrawEllipse(const CPoint& center, double width, double height) override;

private:
	void PrintColor();
	std::string GetColorString();
	Color m_color;
};
