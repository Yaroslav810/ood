#pragma once
#include "../Shape/IShape.h"
#include <cstdint>
#include <limits>
#include <memory>

class IShapes
{
public:
	[[nodiscard]] virtual size_t GetShapesCount() const = 0;
	virtual void InsertShape(std::shared_ptr<IShape> shape, size_t position = std::numeric_limits<size_t>::max()) = 0;
	virtual std::shared_ptr<IShape> GetShapeAtIndex(size_t index) = 0;
	[[nodiscard]] virtual std::shared_ptr<const IShape> GetShapeAtIndex(size_t index) const = 0;
	virtual void RemoveShapeAtIndex(size_t index) = 0;

	virtual ~IShapes() = default;
};
