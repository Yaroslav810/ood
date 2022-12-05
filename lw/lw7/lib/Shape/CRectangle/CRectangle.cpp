#include "CRectangle.h"

CRectangle::CRectangle(PointD leftTop, double width, double height)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
{
}

std::optional<RectD> CRectangle::GetFrame()
{
	return RectD{
		m_leftTop.x,
		m_leftTop.y,
		m_width,
		m_height,
	};
}

void CRectangle::SetFrame(const RectD& rect)
{
	m_leftTop = { rect.left, rect.top };
	m_width = rect.width;
	m_height = rect.height;
}

void CRectangle::Draw(ICanvas& canvas) const
{
	PointD leftTopPoint = m_leftTop;
	PointD rightTopPoint = { m_leftTop.x + m_width, m_leftTop.y };
	PointD rightBottomPoint = { m_leftTop.x + m_width, m_leftTop.y + m_height };
	PointD leftBottomPoint = { m_leftTop.x, m_leftTop.y + m_height };

	canvas.DrawPolygon(
		{ leftTopPoint, rightTopPoint, rightBottomPoint, leftBottomPoint },
		GetOutlineStyle()->GetColor(),
		GetFillStyle()->GetColor(),
		GetOutlineStyle()->GetThickness());
}
