#pragma once
#include "ISlide.h"

class CSlide : public ISlide
{
public:
	CSlide(double width, double height);

	[[nodiscard]] double GetWidth() const final;
	[[nodiscard]] double GetHeight() const final;

	[[nodiscard]] size_t GetShapesCount() const final;
	void InsertShape(std::shared_ptr<IShape> shape, size_t position) final;
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index) final;
	void RemoveShapeAtIndex(size_t index) final;

	void Draw(ICanvas& canvas) const final;

private:
	std::vector<std::shared_ptr<IShape>> m_shapes;
	double m_width;
	double m_height;
};
