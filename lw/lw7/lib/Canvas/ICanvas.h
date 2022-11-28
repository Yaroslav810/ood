#pragma once
#include "../Common/CommonTypes.h"
#include <optional>
#include <vector>

class ICanvas
{
public:
	virtual void DrawLine(PointD start, PointD end, std::optional<RGBAColor> outline, std::optional<double> thickness) = 0;
	virtual void DrawPolygon(
		std::vector<PointD> const& points,
		std::optional<RGBAColor> outline,
		std::optional<RGBAColor> fill,
		std::optional<double> thickness)
		= 0;
	virtual void DrawEllipse(
		PointD center,
		double horizontalRadius,
		double verticalRadius,
		std::optional<RGBAColor> outline,
		std::optional<RGBAColor> fill,
		std::optional<double> thickness)
		= 0;

	virtual ~ICanvas() = default;
};
