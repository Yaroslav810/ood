#pragma once
#include "../CShape/CShape.h"

class CEllipse : public CShape
{
public:
public:
	CEllipse(PointD center, double horizontalRadius, double verticalRadius);

	RectD GetFrame() final;
	void SetFrame(RectD const& rect) final;
	void Draw(ICanvas& canvas) const final;

private:
	PointD m_center;
	double m_horizontalRadius;
	double m_verticalRadius;
};