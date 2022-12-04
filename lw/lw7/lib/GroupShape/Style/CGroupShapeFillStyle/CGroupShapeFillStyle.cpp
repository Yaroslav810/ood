#include "CGroupShapeFillStyle.h"

CGroupShapeFillStyle::CGroupShapeFillStyle(GroupShapeFillStyleEnumeratorAll& enumerator)
	: m_enumeratorAll(enumerator)
{
}

std::optional<bool> CGroupShapeFillStyle::IsEnabled() const
{
	std::optional<bool> result;
	bool initialized = false;
	m_enumeratorAll([&result, &initialized](IFillStyle& style) {
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

void CGroupShapeFillStyle::Enable(bool enable)
{
	m_enumeratorAll([enable](IFillStyle& style) {
		style.Enable(enable);
	});
}

std::optional<RGBAColor> CGroupShapeFillStyle::GetColor() const
{
	std::optional<RGBAColor> result;
	bool initialized = false;
	m_enumeratorAll([&result, &initialized](IFillStyle& style) {
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

void CGroupShapeFillStyle::SetColor(RGBAColor color)
{
	m_enumeratorAll([color](IFillStyle& style) {
		style.SetColor(color);
	});
}
