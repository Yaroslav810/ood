#include "CShape.h"

CShape::CShape()
	: m_outlineStyle(std::make_shared<CShapeOutlineStyle>())
	, m_fillStyle(std::make_shared<CShapeFillStyle>())
{
}

std::shared_ptr<ILineStyle> CShape::GetOutlineStyle()
{
	return m_outlineStyle;
}

std::shared_ptr<const ILineStyle> CShape::GetOutlineStyle() const
{
	return m_outlineStyle;
}

std::shared_ptr<IFillStyle> CShape::GetFillStyle()
{
	return m_fillStyle;
}

std::shared_ptr<const IFillStyle> CShape::GetFillStyle() const
{
	return m_fillStyle;
}

std::shared_ptr<IGroupShape> CShape::GetGroup()
{
	return nullptr;
}

std::shared_ptr<const IGroupShape> CShape::GetGroup() const
{
	return nullptr;
}
