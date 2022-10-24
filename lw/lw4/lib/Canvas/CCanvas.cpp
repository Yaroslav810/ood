#include "CCanvas.h"

void CCanvas::SetColor(const Color& color)
{
	m_color = color;
}

void CCanvas::DrawLine(const CPoint& from, const CPoint& to)
{
	PrintColor();
	std::cout << "draw line from {"
			  << std::to_string(from.GetX()) << ", " << std::to_string(from.GetY())
			  << "} to {"
			  << std::to_string(to.GetX()) << ", " << std::to_string(to.GetY())
			  << "}" << std::endl;
}

void CCanvas::DrawEllipse(const CPoint& center, double width, double height)
{
	PrintColor();
	std::cout << "draw ellipse with center {"
			  << std::to_string(center.GetX()) << ", " << std::to_string(center.GetY())
			  << "} and width = "
			  << std::to_string(width) << " and height = " << std::to_string(height)
			  << std::endl;
}

void CCanvas::PrintColor()
{
	std::cout << "(" << GetColorString() << ") ";
}

std::string CCanvas::GetColorString()
{
	switch (m_color)
	{
	case Color::Green:
		return "green";
	case Color::Red:
		return "red";
	case Color::Blue:
		return "blue";
	case Color::Yellow:
		return "yellow";
	case Color::Pink:
		return "pink";
	case Color::Black:
		return "black";
	}
}
