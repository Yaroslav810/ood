#pragma once
#include "./../ICanvas.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

class CCanvas : public ICanvas
{
public:
	explicit CCanvas(sf::RenderWindow& window);
	void DrawLine(PointD start, PointD end, std::optional<RGBAColor> outline, std::optional<double> thickness) override;
	void DrawPolygon(
		std::vector<PointD> const& points,
		std::optional<RGBAColor> outline,
		std::optional<RGBAColor> fill,
		std::optional<double> thickness)
		override;
	void DrawEllipse(
		PointD center,
		double horizontalRadius,
		double verticalRadius,
		std::optional<RGBAColor> outline,
		std::optional<RGBAColor> fill,
		std::optional<double> thickness)
		override;

private:
	sf::RenderWindow& m_window;
};