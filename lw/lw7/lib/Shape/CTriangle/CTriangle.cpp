#include "CTriangle.h"

CTriangle::CTriangle(PointD vertex1, PointD vertex2, PointD vertex3)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

std::optional<RectD> CTriangle::GetFrame()
{
	auto minX = std::min({ m_vertex1.x, m_vertex2.x, m_vertex3.x });
	auto minY = std::min({ m_vertex1.y, m_vertex2.y, m_vertex3.y });
	auto maxX = std::min({ m_vertex1.x, m_vertex2.x, m_vertex3.x });
	auto maxY = std::min({ m_vertex1.y, m_vertex2.y, m_vertex3.y });

	return RectD{ minX, minY, maxX - minX, maxY - minY };
}

void CTriangle::SetFrame(const RectD& rect)
{
	auto frame = GetFrame().value();
	auto relationshipX = rect.width / frame.width;
	auto relationshipY = rect.height / frame.height;

	m_vertex1.x = rect.left + (m_vertex1.x - frame.left) * relationshipX;
	m_vertex1.y = rect.top + (m_vertex1.y - frame.top) * relationshipY;
	m_vertex2.x = rect.left + (m_vertex2.x - frame.left) * relationshipX;
	m_vertex2.y = rect.top + (m_vertex2.y - frame.top) * relationshipY;
	m_vertex3.x = rect.left + (m_vertex3.x - frame.left) * relationshipX;
	m_vertex3.y = rect.top + (m_vertex3.y - frame.top) * relationshipY;
}

void CTriangle::Draw(ICanvas& canvas) const
{
	canvas.DrawPolygon(
		{ m_vertex1, m_vertex2, m_vertex3 },
		GetOutlineStyle()->GetColor(),
		GetFillStyle()->GetColor(),
		GetOutlineStyle()->GetThickness());
}
