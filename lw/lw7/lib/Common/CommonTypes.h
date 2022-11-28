#pragma once
#include <cstdint>

template <typename T>
struct Rect
{
	T left;
	T top;
	T width;
	T height;
};

template <typename T>
struct Point
{
	T x;
	T y;
};

typedef Rect<double> RectD;
typedef uint32_t RGBAColor;
typedef Point<double> PointD;
