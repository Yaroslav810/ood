#pragma once
#include "../../Color/Color.h"
#include "../../Point/CPoint.h"
#include "../CShape.h"
#include <cmath>
#include <stdexcept>
#include <vector>

class CRegularPolygon : public CShape
{
public:
	CRegularPolygon(const Color& color, int vertexCount, const CPoint& center, double radius);
	[[nodiscard]] int GetVertexCount() const;
	[[nodiscard]] CPoint GetCenterPoint() const;
	[[nodiscard]] double GetRadius() const;

	void Draw(ICanvas& canvas) override;

private:
	[[nodiscard]] std::vector<CPoint> GetVertexes() const;

	int m_vertexCount;
	CPoint m_center;
	double m_radius;
};