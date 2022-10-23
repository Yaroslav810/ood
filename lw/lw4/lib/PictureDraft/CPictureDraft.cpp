#include "CPictureDraft.h"

size_t CPictureDraft::GetShapesCount() const
{
	return m_shapes.size();
}

CShape& CPictureDraft::GetShape(size_t index) const
{
	if (index >= GetShapesCount())
	{
		throw std::out_of_range("Unavailable index");
	}

	return *m_shapes[index];
}

void CPictureDraft::AddShape(CShape::ShapePtr&& shape)
{
	m_shapes.push_back(std::move(shape));
}
