#pragma once
#include "../CShape/CShape.h"

class CEllipse : public CShape
{
public:
public:
	CEllipse(PointD center, double horizontalRadius, double verticalRadius);

	RectD GetFrame() override;
	void SetFrame(RectD const& rect) override;
	void Draw(ICanvas& canvas) const override;

private:
	PointD m_center;
	double m_horizontalRadius;
	double m_verticalRadius;
};