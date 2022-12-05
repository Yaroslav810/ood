#include "CCanvas.h"

CCanvas::CCanvas(sf::RenderWindow& window)
	: m_window(window)
{
}

void CCanvas::DrawLine(PointD start, PointD end, std::optional<RGBAColor> outline, std::optional<double> thickness)
{
	sf::VertexArray line(sf::Quads, 4);
	sf::Vector2f startVector(start.x, start.y);
	sf::Vector2f endVector(end.x, end.y);

	sf::Vector2f difference = startVector - endVector;
	sf::Vector2f perpendicular(-difference.y / difference.x, 1);
	sf::Vector2f offset = thickness.has_value() ? float(thickness.value() / 2) * perpendicular : perpendicular * float(0);
	line[0].position = startVector + offset;
	line[1].position = endVector + offset;
	line[2].position = endVector - offset;
	line[3].position = startVector - offset;
	auto color = outline.has_value() ? outline.value() : 0;
	line[0].color = sf::Color(color);
	line[1].color = sf::Color(color);
	line[2].color = sf::Color(color);
	line[3].color = sf::Color(color);
	m_window.draw(line);
}

void CCanvas::DrawPolygon(const std::vector<PointD>& points, std::optional<RGBAColor> outline, std::optional<RGBAColor> fill, std::optional<double> thickness)
{
	sf::ConvexShape shape;
	shape.setPointCount(points.size());

	for (size_t index = 0; index < points.size(); index++)
	{
		shape.setPoint(index, sf::Vector2f((float)points[index].x, (float)points[index].y));
	}

	if (outline.has_value())
	{
		shape.setOutlineColor(sf::Color(outline.value()));
	}
	if (thickness.has_value())
	{
		shape.setOutlineThickness((float)thickness.value());
	}
	if (fill.has_value())
	{
		shape.setFillColor(sf::Color(fill.value()));
	}

	m_window.draw(shape);
}

void CCanvas::DrawEllipse(PointD center, double horizontalRadius, double verticalRadius, std::optional<RGBAColor> outline, std::optional<RGBAColor> fill, std::optional<double> thickness)
{
	sf::CircleShape circleShape((float)horizontalRadius);
	circleShape.setOrigin((float)horizontalRadius, (float)horizontalRadius);
	circleShape.move(sf::Vector2f((float)center.x, (float)m_window.getSize().y - (float)center.y));
	circleShape.setScale(1.f, (float)verticalRadius / (float)horizontalRadius);

	if (outline.has_value())
	{
		circleShape.setOutlineColor(sf::Color(outline.value()));
	}
	if (thickness.has_value())
	{
		circleShape.setOutlineThickness((float)thickness.value());
	}
	if (fill.has_value())
	{
		circleShape.setFillColor(sf::Color(fill.value()));
	}

	m_window.draw(circleShape);
}
