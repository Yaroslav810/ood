#include "CCanvas.h"

// TODO: Реализовать!

CCanvas::CCanvas(sf::RenderWindow& window)
	: m_window(window)
{
}

void CCanvas::DrawLine(PointD start, PointD end, std::optional<RGBAColor> outline, std::optional<double> thickness)
{
}

void CCanvas::DrawPolygon(const std::vector<PointD>& points, std::optional<RGBAColor> outline, std::optional<RGBAColor> fill, std::optional<double> thickness)
{
}

void CCanvas::DrawEllipse(PointD center, double horizontalRadius, double verticalRadius, std::optional<RGBAColor> outline, std::optional<RGBAColor> fill, std::optional<double> thickness)
{
}
