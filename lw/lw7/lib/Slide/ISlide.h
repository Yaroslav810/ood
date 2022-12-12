#pragma once
#include "../Common/IDrawable.h"
#include "../GroupShape/IShapes.h"
#include "../Shape//IShape.h"

class ISlide : public IDrawable
	, public IShapes
{
public:
	[[nodiscard]] virtual double GetWidth() const = 0;
	[[nodiscard]] virtual double GetHeight() const = 0;
};
