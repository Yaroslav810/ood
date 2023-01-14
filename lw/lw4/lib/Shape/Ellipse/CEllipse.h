#pragma once
#include "../CShape.h"

class CEllipse : public CShape
{
public:
	CEllipse(const Color& color, const CPoint& center, double horizontalRadius, double verticalRadius);
	[[nodiscard]] CPoint GetCenter() const;
	[[nodiscard]] double GetHorizontalRadius() const;
	[[nodiscard]] double GetVerticalRadius() const;

	void Draw(ICanvas& canvas) const override;

private:
	CPoint m_center;
	double m_horizontalRadius;
	double m_verticalRadius;
};