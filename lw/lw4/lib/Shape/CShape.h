#pragma once
#include "../Canvas/ICanvas.h"
#include "../Color/Color.h"
#include <memory>

class CShape
{
public:
	using ShapePtr = std::unique_ptr<CShape>;

	explicit CShape(const Color& color);
	[[nodiscard]] Color GetColor() const;
	virtual ~CShape() = default;

	virtual void Draw(ICanvas& canvas) const = 0;

private:
	Color m_color;
};
