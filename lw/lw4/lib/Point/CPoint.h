#pragma once

class CPoint
{
public:
	CPoint(double x, double y);
	[[nodiscard]] double GetX() const;
	[[nodiscard]] double GetY() const;

private:
	double m_x;
	double m_y;
};
