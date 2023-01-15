#include "CRectangle.h"

CRectangle::CRectangle(const Color& color, const CPoint& leftTop, const CPoint& rightBottom)
	: CShape(color)
	, m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
}

CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

void CRectangle::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());

	CPoint rightTop(m_rightBottom.GetX(), m_leftTop.GetY());
	CPoint leftBottom(m_leftTop.GetX(), m_rightBottom.GetY());

	canvas.DrawLine(m_leftTop, rightTop);
	canvas.DrawLine(rightTop, m_rightBottom);
	canvas.DrawLine(m_rightBottom, leftBottom);
	canvas.DrawLine(leftBottom, m_leftTop);
}
