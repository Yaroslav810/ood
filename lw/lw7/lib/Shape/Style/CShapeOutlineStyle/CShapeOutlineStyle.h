#pragma once
#include "../../../Common/ILineStyle.h"

class CShapeOutlineStyle : public ILineStyle
{
public:
	[[nodiscard]] std::optional<bool> IsEnabled() const override;
	void Enable(bool enable) override;

	[[nodiscard]] std::optional<RGBAColor> GetColor() const override;
	void SetColor(RGBAColor color) override;

	void SetThickness(double thickness) override;
	[[nodiscard]] std::optional<double> GetThickness() const override;

private:
	bool m_enabled = true;
	RGBAColor m_color = 0;
	double m_thickness = 1;
};
