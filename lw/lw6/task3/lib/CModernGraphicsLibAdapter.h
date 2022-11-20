#pragma once
#include "graphics_lib/graphics_lib.h"
#include "modern_graphics_lib/modern_graphics_lib.h"

class CModernGraphicsLibAdapter : public graphics_lib::ICanvas
{
public:
	CModernGraphicsLibAdapter(modern_graphics_lib::CModernGraphicsRenderer& modernGraphicsRenderer)
		: m_modernGraphicsRenderer(modernGraphicsRenderer)
		, m_currentPoint({ 0, 0 })
		, m_RGBAColor({ 0, 0, 0, 0 })
	{
	}

	void SetColor(uint32_t rgbColor) override
	{
		auto red = float(rgbColor & 0xFF);
		auto green = float((rgbColor >> 8) & 0xFF);
		auto blue = float((rgbColor >> 16) & 0xFF);
		m_RGBAColor = { red, green, blue, 1 };
	}

	void MoveTo(int x, int y) override
	{
		m_currentPoint = { x, y };
	}

	void LineTo(int x, int y) override
	{
		modern_graphics_lib::CPoint newPoint = { x, y };
		m_modernGraphicsRenderer.DrawLine(m_currentPoint, newPoint, m_RGBAColor);
		m_currentPoint = newPoint;
	}

private:
	modern_graphics_lib::CModernGraphicsRenderer& m_modernGraphicsRenderer;
	modern_graphics_lib::CPoint m_currentPoint;
	modern_graphics_lib::CRGBAColor m_RGBAColor;
};
