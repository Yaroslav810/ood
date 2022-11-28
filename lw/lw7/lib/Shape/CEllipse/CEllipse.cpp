#include "CEllipse.h"

CEllipse::CEllipse(PointD center, double horizontalRadius, double verticalRadius)
	: m_center(center)
	, m_horizontalRadius(horizontalRadius)
	, m_verticalRadius(verticalRadius)
{
}

RectD CEllipse::GetFrame()
{
	return {
		.left = m_center.x - m_horizontalRadius,
		.top = m_center.y - m_verticalRadius,
		.width = m_horizontalRadius * 2,
		.height = m_verticalRadius * 2,
	};
}

void CEllipse::SetFrame(const RectD& rect)
{
	m_center = { rect.left + rect.width / 2, rect.top + rect.height / 2 };
	m_horizontalRadius = rect.width / 2;
	m_verticalRadius = rect.height / 2;
}

void CEllipse::Draw(ICanvas& canvas) const
{
	canvas.DrawEllipse()
}
