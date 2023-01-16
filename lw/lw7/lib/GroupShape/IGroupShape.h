#pragma once
#include "../Shape/IShape.h"
#include "IShapes.h"

class IGroupShape : public IShape
	, public IShapes
{
public:
	virtual ~IGroupShape() = default;
};
