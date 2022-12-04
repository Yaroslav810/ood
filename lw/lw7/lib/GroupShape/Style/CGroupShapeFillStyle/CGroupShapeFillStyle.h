#pragma once
#include "../../../Common/ILineStyle.h"
#include <functional>
#include <iostream>
#include <optional>

using GroupShapeFillStyleCallback = std::function<void(IFillStyle& style)>;
using GroupShapeFillStyleEnumeratorAll = std::function<void(GroupShapeFillStyleCallback)>;

class CGroupShapeFillStyle : public IFillStyle
{
public:
	explicit CGroupShapeFillStyle(GroupShapeFillStyleEnumeratorAll& enumerator);

	[[nodiscard]] std::optional<bool> IsEnabled() const override;
	void Enable(bool enable) override;

	[[nodiscard]] std::optional<RGBAColor> GetColor() const override;
	void SetColor(RGBAColor color) override;

private:
	GroupShapeFillStyleEnumeratorAll m_enumeratorAll;
};