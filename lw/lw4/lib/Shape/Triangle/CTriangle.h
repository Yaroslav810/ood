#pragma once
#include "../CShape.h"

class CTriangle : public CShape
{
public:
	CTriangle(const Color& color, const CPoint& firstVertex, const CPoint& secondVertex, const CPoint& thirdVertex);

	[[nodiscard]] CPoint GetFirstVertex() const;
	[[nodiscard]] CPoint GetSecondVertex() const;
	[[nodiscard]] CPoint GetThirdVertex() const;

	void Draw(ICanvas& canvas) override;

private:
	CPoint m_firstVertex;
	CPoint m_secondVertex;
	CPoint m_thirdVertex;
};
