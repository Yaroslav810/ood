#pragma once
#include "../Common/IDrawable.h"
#include "../GroupShape/IShapes.h"

class ISlide : public IDrawable
{
public:
	[[nodiscard]] virtual double GetWidth() const = 0;
	[[nodiscard]] virtual double GetHeight() const = 0;

	[[nodiscard]] virtual IShapes& GetShapes() const = 0;
};
