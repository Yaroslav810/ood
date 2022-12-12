#include "CSlide.h"

CSlide::CSlide(double width, double height)
	: m_width(width)
	, m_height(height)
{
}

double CSlide::GetWidth() const
{
	return m_width;
}

double CSlide::GetHeight() const
{
	return m_height;
}

size_t CSlide::GetShapesCount() const
{
	return m_shapes.size();
}

void CSlide::InsertShape(std::shared_ptr<IShape> shape, size_t position)
{
	if (position > m_shapes.size() || position < 0)
	{
		throw std::out_of_range("Invalid position");
	}
	m_shapes.insert(m_shapes.begin() + position, shape);
}

std::shared_ptr<IShape> CSlide::GetShapeAtIndex(size_t index)
{
	if (index > m_shapes.size() || index < 0)
	{
		throw std::out_of_range("Invalid position");
	}

	return m_shapes.at(index);
}

std::shared_ptr<const IShape> CSlide::GetShapeAtIndex(size_t index) const
{
	if (index > m_shapes.size() || index < 0)
	{
		throw std::out_of_range("Invalid position");
	}

	return m_shapes.at(index);
}

void CSlide::RemoveShapeAtIndex(size_t index)
{
	if (index > m_shapes.size() || index < 0)
	{
		throw std::out_of_range("Invalid position");
	}

	m_shapes.erase(m_shapes.begin() + index);
}

void CSlide::Draw(ICanvas& canvas) const
{
	for (const auto& shape : m_shapes)
	{
		shape->Draw(canvas);
	}
}
