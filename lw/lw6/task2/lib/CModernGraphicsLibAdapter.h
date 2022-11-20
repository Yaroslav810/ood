#pragma once
#include "graphics_lib/graphics_lib.h"
#include "modern_graphics_lib/modern_graphics_lib.h"

class CModernGraphicsLibAdapter : public graphics_lib::ICanvas
	, public modern_graphics_lib::CModernGraphicsRenderer
{
public:
	CModernGraphicsLibAdapter(std::ostream& strm)
		: modern_graphics_lib::CModernGraphicsRenderer(strm)
		, m_currentPoint({ 0, 0 })
	{
	}

	void MoveTo(int x, int y) override
	{
		m_currentPoint = { x, y };
	}

	void LineTo(int x, int y) override
	{
		modern_graphics_lib::CPoint newPoint = { x, y };
		DrawLine(m_currentPoint, newPoint);
		m_currentPoint = newPoint;
	}

private:
	modern_graphics_lib::CPoint m_currentPoint;
};
