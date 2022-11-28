#pragma once
#include "../../Common/ILineStyle.h"
#include "../IShape.h"
#include "../Style/CShapeFillStyle/CShapeFillStyle.h"
#include "../Style/CShapeOutlineStyle/CShapeOutlineStyle.h"

class CShape : public IShape
{
public:
	CShape();

	std::shared_ptr<ILineStyle> GetOutlineStyle() override;
	[[nodiscard]] std::shared_ptr<const ILineStyle> GetOutlineStyle() const override;

	std::shared_ptr<IFillStyle> GetFillStyle() override;
	[[nodiscard]] std::shared_ptr<const IFillStyle> GetFillStyle() const override;

	std::shared_ptr<IGroupShape> GetGroup() override;
	[[nodiscard]] std::shared_ptr<const IGroupShape> GetGroup() const override;

private:
	std::shared_ptr<ILineStyle> m_outlineStyle;
	std::shared_ptr<IFillStyle> m_fillStyle;
};
