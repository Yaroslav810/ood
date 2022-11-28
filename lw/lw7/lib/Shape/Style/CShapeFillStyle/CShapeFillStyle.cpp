#include "CShapeFillStyle.h"

std::optional<bool> CShapeFillStyle::IsEnabled() const
{
	return m_enabled;
}

void CShapeFillStyle::Enable(bool enable)
{
	m_enabled = enable;
}

std::optional<RGBAColor> CShapeFillStyle::GetColor() const
{
	return m_color;
}

void CShapeFillStyle::SetColor(RGBAColor color)
{
	m_color = color;
}
