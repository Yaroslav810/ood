#pragma once
#include "CommonTypes.h"
#include <optional>

class IFillStyle
{
public:
	[[nodiscard]] virtual std::optional<bool> IsEnabled() const = 0;
	virtual void Enable(bool enable) = 0;

	[[nodiscard]] virtual std::optional<RGBAColor> GetColor() const = 0;
	virtual void SetColor(RGBAColor color) = 0;

	virtual ~IFillStyle() = default;
};
