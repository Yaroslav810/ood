#include "CRegularPolygon.h"

CRegularPolygon::CRegularPolygon(const Color& color, int vertexCount, const CPoint& center, double radius)
	: CShape(color)
	, m_center(center)
	, m_radius(radius)
{
	if (vertexCount < 3)
	{
		throw std::invalid_argument("Incorrect number of vertices. Minimum 3");
	}

	m_vertexCount = vertexCount;
}

int CRegularPolygon::GetVertexCount() const
{
	return m_vertexCount;
}

CPoint CRegularPolygon::GetCenterPoint() const
{
	return m_center;
}

double CRegularPolygon::GetRadius() const
{
	return m_radius;
}

std::vector<CPoint> CRegularPolygon::GetVertexes() const
{
	auto angle = 2 * M_PI / m_vertexCount;
	std::vector<CPoint> vertexes;
	for (int i = 0; i < m_vertexCount; ++i)
	{
		auto x = m_center.GetX() + m_radius * std::cos(angle * i);
		auto y = m_center.GetY() + m_radius * std::sin(angle * i);
		vertexes.emplace_back(x, y);
	}
	return vertexes;
}

void CRegularPolygon::Draw(ICanvas& canvas)
{
	canvas.SetColor(GetColor());
	std::vector<CPoint> vertexes = GetVertexes();
	for (int i = 0; i < m_vertexCount - 1; ++i)
	{
		canvas.DrawLine(vertexes[i], vertexes[i + 1]);
	}
	canvas.DrawLine(vertexes[m_vertexCount - 1], vertexes[0]);
}
