#pragma once
#include "../Common/IDrawable.h"
#include "../Shape//IShape.h"

class ISlide : public IDrawable
{
public:
	[[nodiscard]] virtual double GetWidth() const = 0;
	[[nodiscard]] virtual double GetHeight() const = 0;

	[[nodiscard]] virtual size_t GetShapesCount() const = 0;
	virtual void InsertShape(std::shared_ptr<IShape> shape, size_t position) = 0;
	virtual std::shared_ptr<IShape> GetShapeAtIndex(size_t index) = 0;
	virtual void RemoveShapeAtIndex(size_t index) = 0;
};
