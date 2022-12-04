#pragma once
#include "../Common/IDrawable.h"
#include "../Common/IFillStyle.h"
#include "../Common/ILineStyle.h"
#include <memory>

class IGroupShape;

class IShape : public IDrawable
{
public:
	virtual std::optional<RectD> GetFrame() = 0;
	virtual void SetFrame(const RectD& rect) = 0;

	virtual std::shared_ptr<ILineStyle> GetOutlineStyle() = 0;
	[[nodiscard]] virtual std::shared_ptr<const ILineStyle> GetOutlineStyle() const = 0;

	virtual std::shared_ptr<IFillStyle> GetFillStyle() = 0;
	[[nodiscard]] virtual std::shared_ptr<const IFillStyle> GetFillStyle() const = 0;

	virtual std::shared_ptr<IGroupShape> GetGroup() = 0;
	[[nodiscard]] virtual std::shared_ptr<const IGroupShape> GetGroup() const = 0;
};
