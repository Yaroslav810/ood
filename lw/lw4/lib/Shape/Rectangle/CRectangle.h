#pragma once
#include "../CShape.h"

class CRectangle : public CShape
{
public:
	CRectangle(const Color& color, const CPoint& leftTop, const CPoint& rightBottom);
	[[nodiscard]] CPoint GetLeftTop() const;
	[[nodiscard]] CPoint GetRightBottom() const;

	void Draw(ICanvas& canvas) const override;

private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
};
