#pragma once
#include "../Shape/IShape.h"
#include "IShapes.h"

class IGroupShape : public IShape
	, public IShapesCollection
{
public:
	virtual ~IGroupShape() = default;
};
