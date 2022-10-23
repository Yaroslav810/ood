#pragma once
#include "../Shape/CShape.h"
#include <memory>
#include <string>

struct IShapeFactory
{
	virtual CShape::ShapePtr CreateShape(const std::string& description) = 0;
	virtual ~IShapeFactory() = default;
};
