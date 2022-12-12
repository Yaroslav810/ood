#pragma once
#include "../IGroupShape.h"

class CGroupShape : public IGroupShape
{
public:
	CGroupShape();

	std::optional<RectD> GetFrame() override;
	void SetFrame(const RectD& rect) override;

	std::shared_ptr<ILineStyle> GetOutlineStyle() override;
	[[nodiscard]] std::shared_ptr<const ILineStyle> GetOutlineStyle() const override;

	std::shared_ptr<IFillStyle> GetFillStyle() override;
	[[nodiscard]] std::shared_ptr<const IFillStyle> GetFillStyle() const override;

	std::shared_ptr<IGroupShape> GetGroup() override;
	[[nodiscard]] std::shared_ptr<const IGroupShape> GetGroup() const override;

	[[nodiscard]] size_t GetShapesCount() const override;
	void InsertShape(std::shared_ptr<IShape> shape, size_t position) override;
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index) override;
	std::shared_ptr<const IShape> GetShapeAtIndex(size_t index) const override;
	void RemoveShapeAtIndex(size_t index) override;

	void Draw(ICanvas& canvas) const override;

private:
	std::vector<std::shared_ptr<IShape>> m_shapes;
	std::shared_ptr<ILineStyle> m_outlineStyle;
	std::shared_ptr<IFillStyle> m_fillStyle;
};
