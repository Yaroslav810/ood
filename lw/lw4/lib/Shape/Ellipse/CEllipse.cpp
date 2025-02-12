#include "CEllipse.h"

CEllipse::CEllipse(const Color& color, const CPoint& center, double horizontalRadius, double verticalRadius)
	: CShape(color)
	, m_center(center)
	, m_horizontalRadius(horizontalRadius)
	, m_verticalRadius(verticalRadius)
{
}

CPoint CEllipse::GetCenter() const
{
	return m_center;
}

double CEllipse::GetHorizontalRadius() const
{
	return m_horizontalRadius;
}

double CEllipse::GetVerticalRadius() const
{
	return m_verticalRadius;
}

void CEllipse::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());
	canvas.DrawEllipse({m_center.GetX() - m_horizontalRadius, m_center.GetY() - m_verticalRadius}, 2 * m_horizontalRadius, 2 * m_verticalRadius);
}
