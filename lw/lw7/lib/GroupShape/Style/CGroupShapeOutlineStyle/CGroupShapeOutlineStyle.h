#pragma once
#include "../../../Common/ILineStyle.h"
#include <functional>
#include <iostream>
#include <optional>

using GroupShapeOutlineStyleCallback = std::function<void(ILineStyle& style)>;
using GroupShapeOutlineStyleEnumeratorAll = std::function<void(GroupShapeOutlineStyleCallback)>;

class CGroupShapeOutlineStyle : public ILineStyle
{
public:
	explicit CGroupShapeOutlineStyle(GroupShapeOutlineStyleEnumeratorAll& enumerator);

	[[nodiscard]] std::optional<bool> IsEnabled() const override;
	void Enable(bool enable) override;

	[[nodiscard]] std::optional<RGBAColor> GetColor() const override;
	void SetColor(RGBAColor color) override;

	void SetThickness(double thickness) override;
	[[nodiscard]] std::optional<double> GetThickness() const override;

private:
	GroupShapeOutlineStyleEnumeratorAll m_enumeratorAll;
};