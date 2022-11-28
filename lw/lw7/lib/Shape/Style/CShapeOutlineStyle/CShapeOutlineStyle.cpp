#include "CShapeOutlineStyle.h"

std::optional<bool> CShapeOutlineStyle::IsEnabled() const
{
	return m_enabled;
}

void CShapeOutlineStyle::Enable(bool enable)
{
	m_enabled = enable;
}

std::optional<RGBAColor> CShapeOutlineStyle::GetColor() const
{
	return m_color;
}

void CShapeOutlineStyle::SetColor(RGBAColor color)
{
	m_color = color;
}

void CShapeOutlineStyle::SetThickness(double thickness)
{
	m_thickness = thickness;
}

std::optional<double> CShapeOutlineStyle::GetThickness() const
{
	return m_thickness;
}
