#include "CTriangle.h"

CTriangle::CTriangle(const Color& color, const CPoint& firstVertex, const CPoint& secondVertex, const CPoint& thirdVertex)
	: CShape(color)
	, m_firstVertex(firstVertex)
	, m_secondVertex(secondVertex)
	, m_thirdVertex(thirdVertex)
{
}

CPoint CTriangle::GetFirstVertex() const
{
	return m_firstVertex;
}

CPoint CTriangle::GetSecondVertex() const
{
	return m_secondVertex;
}

CPoint CTriangle::GetThirdVertex() const
{
	return m_thirdVertex;
}

void CTriangle::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());
	canvas.DrawLine(m_firstVertex, m_secondVertex);
	canvas.DrawLine(m_secondVertex, m_thirdVertex);
	canvas.DrawLine(m_thirdVertex, m_firstVertex);
}
