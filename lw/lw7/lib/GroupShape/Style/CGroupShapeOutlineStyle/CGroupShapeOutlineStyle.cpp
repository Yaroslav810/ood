#include "CGroupShapeOutlineStyle.h"

CGroupShapeOutlineStyle::CGroupShapeOutlineStyle(GroupShapeOutlineStyleEnumeratorAll& enumerator)
	: m_enumeratorAll(enumerator)
{
}

std::optional<bool> CGroupShapeOutlineStyle::IsEnabled() const
{
	std::optional<bool> result;
	bool initialized = false;
	m_enumeratorAll([&result, &initialized](ILineStyle& style) {
		if (!initialized)
		{
			result = style.IsEnabled();
			initialized = true;
		}
		if (result != style.IsEnabled())
		{
			result = std::nullopt;
		}
	});
	return result;
}

void CGroupShapeOutlineStyle::Enable(bool enable)
{
	m_enumeratorAll([enable](ILineStyle& style) {
		style.Enable(enable);
	});
}

std::optional<RGBAColor> CGroupShapeOutlineStyle::GetColor() const
{
	std::optional<RGBAColor> result;
	bool initialized = false;
	m_enumeratorAll([&result, &initialized](ILineStyle& style) {
		if (!initialized)
		{
			result = style.GetColor();
			initialized = true;
		}
		if (result != style.GetColor())
		{
			result = std::nullopt;
		}
	});
	return result;
}

void CGroupShapeOutlineStyle::SetColor(RGBAColor color)
{
	m_enumeratorAll([color](ILineStyle& style) {
		style.SetColor(color);
	});
}

void CGroupShapeOutlineStyle::SetThickness(double thickness)
{
	m_enumeratorAll([thickness](ILineStyle& style) {
		style.SetThickness(thickness);
	});
}

std::optional<double> CGroupShapeOutlineStyle::GetThickness() const
{
	std::optional<double> result;
	bool initialized = false;
	m_enumeratorAll([&result, &initialized](ILineStyle& style) {
		if (!initialized)
		{
			result = style.GetThickness();
			initialized = true;
		}
		if (result != style.GetThickness())
		{
			result = std::nullopt;
		}
	});
	return result;
}
