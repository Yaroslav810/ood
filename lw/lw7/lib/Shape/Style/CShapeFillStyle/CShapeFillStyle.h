#pragma once
#include "../../../Common/IFillStyle.h"

class CShapeFillStyle : public IFillStyle
{
public:
	[[nodiscard]] std::optional<bool> IsEnabled() const override;
	void Enable(bool enable) override;

	[[nodiscard]] std::optional<RGBAColor> GetColor() const override;
	void SetColor(RGBAColor color) override;

private:
	bool m_enabled = true;
	RGBAColor m_color = 0;
};
