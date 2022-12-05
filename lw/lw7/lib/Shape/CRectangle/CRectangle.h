#pragma once
#include "../CShape/CShape.h"

class CRectangle : public CShape
{
public:
	CRectangle(PointD leftTop, double width, double height);

	std::optional<RectD> GetFrame() final;
	void SetFrame(RectD const& rect) final;
	void Draw(ICanvas& canvas) const final;

private:
	PointD m_leftTop;
	double m_width;
	double m_height;
};