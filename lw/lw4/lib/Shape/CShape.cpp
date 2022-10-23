#include "CShape.h"

CShape::CShape(const Color& color)
	: m_color(color)
{
}

Color CShape::GetColor() const
{
	return m_color;
}
