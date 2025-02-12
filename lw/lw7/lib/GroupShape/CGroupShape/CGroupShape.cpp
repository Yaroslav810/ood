#include "CGroupShape.h"
#include "../Style/CGroupShapeFillStyle/CGroupShapeFillStyle.h"
#include "../Style/CGroupShapeOutlineStyle/CGroupShapeOutlineStyle.h"

CGroupShape::CGroupShape()
{
	GroupShapeOutlineStyleEnumeratorAll outlineCallback = [this](GroupShapeOutlineStyleCallback const& callback) {
		for (const auto& shape : m_shapes)
		{
			callback(*shape->GetOutlineStyle());
		}
	};
	GroupShapeFillStyleEnumeratorAll fillCallback = [this](GroupShapeFillStyleCallback const& callback) {
		for (const auto& shape : m_shapes)
		{
			callback(*shape->GetFillStyle());
		}
	};
	m_outlineStyle = std::make_shared<CGroupShapeOutlineStyle>(outlineCallback);
	m_fillStyle = std::make_shared<CGroupShapeFillStyle>(fillCallback);
}

std::optional<RectD> CGroupShape::GetFrame()
{
	if (m_shapes.empty())
	{
		return std::nullopt;
	}

	double minX = std::numeric_limits<double>::max();
	double minY = std::numeric_limits<double>::max();
	double maxX = std::numeric_limits<double>::min();
	double maxY = std::numeric_limits<double>::min();

	std::optional<RectD> rect = std::nullopt;
	for (const auto& shape : m_shapes)
	{
		auto frame = shape->GetFrame();
		if (!frame.has_value())
		{
			continue;
		}

		auto data = frame.value();
		minX = std::min(minX, data.left);
		minY = std::min(minY, data.top - data.height);
		maxX = std::max(maxX, data.left + data.width);
		maxY = std::max(maxY, data.top);
		rect = RectD{ minX, maxY, maxX - minX, maxY - minY };
	}

	return rect;
}

void CGroupShape::SetFrame(const RectD& rect)
{
	auto frameOpt = GetFrame();
	if (!frameOpt.has_value())
	{
		return;
	}

	auto frame = frameOpt.value();
	auto ratioX = rect.width / frame.width;
	auto ratioY = rect.height / frame.height;

	for (const auto& shape : m_shapes)
	{
		auto shapeFrameOpt = shape->GetFrame();
		if (!shapeFrameOpt.has_value())
		{
			continue;
		}

		auto shapeFrame = shapeFrameOpt.value();
		auto newX = rect.left + (shapeFrame.left - frame.left) * ratioX;
		auto newY = rect.top - std::abs((shapeFrame.top - frame.top) * ratioY);
		auto newWidth = shapeFrame.width * ratioX;
		auto newHeight = shapeFrame.height * ratioY;

		shape->SetFrame({ newX, newY, newWidth, newHeight });
	}
}

std::shared_ptr<ILineStyle> CGroupShape::GetOutlineStyle()
{
	return m_outlineStyle;
}

std::shared_ptr<const ILineStyle> CGroupShape::GetOutlineStyle() const
{
	return m_outlineStyle;
}

std::shared_ptr<IFillStyle> CGroupShape::GetFillStyle()
{
	return m_fillStyle;
}

std::shared_ptr<const IFillStyle> CGroupShape::GetFillStyle() const
{
	return m_fillStyle;
}

std::shared_ptr<IGroupShape> CGroupShape::GetGroup()
{
	return shared_from_this();
}

std::shared_ptr<const IGroupShape> CGroupShape::GetGroup() const
{
	return shared_from_this();
}

size_t CGroupShape::GetShapesCount() const
{
	return m_shapes.size();
}

void CGroupShape::InsertShape(std::shared_ptr<IShape> shape, size_t position)
{
	if (position > m_shapes.size() || position < 0)
	{
		throw std::out_of_range("Invalid position");
	}
	m_shapes.insert(m_shapes.begin() + position, shape);
}

std::shared_ptr<IShape> CGroupShape::GetShapeAtIndex(size_t index)
{
	if (index >= m_shapes.size() || index < 0)
	{
		throw std::out_of_range("Invalid position");
	}

	return m_shapes.at(index);
}

std::shared_ptr<const IShape> CGroupShape::GetShapeAtIndex(size_t index) const
{
	if (index >= m_shapes.size() || index < 0)
	{
		throw std::out_of_range("Invalid position");
	}

	return m_shapes.at(index);
}

void CGroupShape::RemoveShapeAtIndex(size_t index)
{
	if (index >= m_shapes.size() || index < 0)
	{
		throw std::out_of_range("Invalid position");
	}

	m_shapes.erase(m_shapes.begin() + index);
}

void CGroupShape::Draw(ICanvas& canvas) const
{
	for (const auto& shape : m_shapes)
	{
		shape->Draw(canvas);
	}
}
