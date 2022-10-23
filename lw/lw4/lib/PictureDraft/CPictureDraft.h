#pragma once
#include "../Shape/CShape.h"
#include <memory>
#include <vector>

class CPictureDraft
{
public:
	[[nodiscard]] size_t GetShapesCount() const;
	[[nodiscard]] CShape& GetShape(size_t index) const;
	void AddShape(CShape::ShapePtr&& shape);

private:
	using ShapeVector = std::vector<CShape::ShapePtr>;

	ShapeVector m_shapes{};
};
