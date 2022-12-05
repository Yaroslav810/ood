#pragma once
#include "../CShape/CShape.h"

class CTriangle : public CShape
{
public:
	CTriangle(PointD vertex1, PointD vertex2, PointD vertex3);

	std::optional<RectD> GetFrame() final;
	void SetFrame(RectD const& rect) final;
	void Draw(ICanvas& canvas) const final;

private:
	PointD m_vertex1;
	PointD m_vertex2;
	PointD m_vertex3;
};
