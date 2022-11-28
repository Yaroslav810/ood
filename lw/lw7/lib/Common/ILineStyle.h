#pragma once
#include "CommonTypes.h"
#include "IFillStyle.h"
#include <optional>

class ILineStyle : public IFillStyle
{
public:
	virtual void SetThickness(double thickness) = 0;
	[[nodiscard]] virtual std::optional<double> GetThickness() const = 0;
};
