#pragma once
#include "../Color/Color.h"
#include "ICanvas.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

class CCanvas : public ICanvas
{
public:
	explicit CCanvas(sf::RenderWindow& window);
	void SetColor(const Color& color) override;
	void DrawLine(const CPoint& from, const CPoint& to) override;
	void DrawEllipse(const CPoint& center, double width, double height) override;

private:
	sf::Color GetSFColor();
	sf::RenderWindow& m_window;
	Color m_color;
};
