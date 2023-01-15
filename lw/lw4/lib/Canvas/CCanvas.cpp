#include "CCanvas.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/VertexArray.hpp>

CCanvas::CCanvas(sf::RenderWindow& window)
	: m_window(window)
{
}

void CCanvas::SetColor(const Color& color)
{
	m_color = color;
}

void CCanvas::DrawLine(const CPoint& from, const CPoint& to)
{
	sf::Vertex line[] = {
		sf::Vertex(sf::Vector2f(float(from.GetX()), float(from.GetY()))),
		sf::Vertex(sf::Vector2f(float(to.GetX()), float(to.GetY())))
	};
	auto color = GetSFColor();
	line[0].color = color;
	line[1].color = color;
	m_window.draw(line, 2, sf::Lines);
}

void CCanvas::DrawEllipse(const CPoint& center, double width, double height)
{
	sf::CircleShape circleShape((float)width);
	circleShape.setOrigin((float)width, (float)width);
	circleShape.move(sf::Vector2f((float)center.GetX(), (float)m_window.getSize().y - (float)center.GetY()));
	circleShape.setScale(1.f, (float)height / (float)width);
	circleShape.setFillColor(sf::Color::Transparent);
	circleShape.setOutlineThickness(2);
	circleShape.setOutlineColor(GetSFColor());
	m_window.draw(circleShape);
}

sf::Color CCanvas::GetSFColor()
{
	switch (m_color)
	{
	case Color::Green:
		return sf::Color::Green;
	case Color::Red:
		return sf::Color::Red;
	case Color::Blue:
		return sf::Color::Blue;
	case Color::Yellow:
		return sf::Color::Yellow;
	case Color::Pink:
		return { 255, 192, 203 };
	case Color::Black:
		return sf::Color::Black;
	}
}
