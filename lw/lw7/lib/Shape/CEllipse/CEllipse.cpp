#include "CEllipse.h"

CEllipse::CEllipse(PointD center, double horizontalRadius, double verticalRadius)
	: m_center(center)
	, m_horizontalRadius(horizontalRadius)
	, m_verticalRadius(verticalRadius)
{
}

std::optional<RectD> CEllipse::GetFrame()
{
	return RectD{
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
	auto outline = GetOutlineStyle();
	canvas.DrawEllipse(
		m_center,
		m_horizontalRadius,
		m_verticalRadius,
		outline->GetColor(),
		GetFillStyle()->GetColor(),
		outline->GetThickness());
}
