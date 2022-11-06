#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../lib/Color/Color.h"
#include "../lib/Point/CPoint.h"
#include "../lib/Shape/Ellipse/CEllipse.h"
#include "../lib/Shape/Rectangle/CRectangle.h"
#include "../lib/Shape/RegularPolygon/CRegularPolygon.h"
#include "../lib/Shape/Triangle/CTriangle.h"
#include "../lib/ShapeFactory/CShapeFactory.h"

TEST_CASE("Creating a Rectangle")
{
	CPoint leftTop(10, 10);
	CPoint rightBottom(100, 60);
	CRectangle rectangle(Color::Green, leftTop, rightBottom);

	THEN("Created Rectangle")
	{
		REQUIRE(rectangle.GetColor() == Color::Green);
		REQUIRE(rectangle.GetLeftTop().GetX() == leftTop.GetX());
		REQUIRE(rectangle.GetLeftTop().GetY() == leftTop.GetY());
		REQUIRE(rectangle.GetRightBottom().GetX() == rightBottom.GetX());
		REQUIRE(rectangle.GetRightBottom().GetY() == rightBottom.GetY());
	}
}

TEST_CASE("Creating a Triangle")
{
	CPoint firstVertex(5, 5);
	CPoint secondVertex(15, 5);
	CPoint thirdVertex(10, 10);
	CTriangle triangle(Color::Red, firstVertex, secondVertex, thirdVertex);

	THEN("Created Triangle")
	{
		REQUIRE(triangle.GetColor() == Color::Red);
		REQUIRE(triangle.GetFirstVertex().GetX() == firstVertex.GetX());
		REQUIRE(triangle.GetFirstVertex().GetY() == firstVertex.GetY());
		REQUIRE(triangle.GetSecondVertex().GetX() == secondVertex.GetX());
		REQUIRE(triangle.GetSecondVertex().GetY() == secondVertex.GetY());
		REQUIRE(triangle.GetThirdVertex().GetX() == thirdVertex.GetX());
		REQUIRE(triangle.GetThirdVertex().GetY() == thirdVertex.GetY());
	}
}

TEST_CASE("Creating an Ellipse")
{
	CPoint centerPoint(20, 20);
	int horizontalRadius = 8;
	int verticalRadius = 5;

	CEllipse ellipse(Color::Blue, centerPoint, horizontalRadius, verticalRadius);

	THEN("Created Ellipse")
	{
		REQUIRE(ellipse.GetColor() == Color::Blue);
		REQUIRE(ellipse.GetCenter().GetX() == centerPoint.GetX());
		REQUIRE(ellipse.GetCenter().GetY() == centerPoint.GetY());
		REQUIRE(ellipse.GetHorizontalRadius() == horizontalRadius);
		REQUIRE(ellipse.GetVerticalRadius() == verticalRadius);
	}
}

TEST_CASE("Creating a Regular Polygon")
{
	CPoint centerPoint(10, 10);
	int vertexCount = 4;
	double radius = 5;
	CRegularPolygon regularPolygon(Color::Yellow, vertexCount, centerPoint, radius);
	THEN("Created Regular Polygon")
	{
		REQUIRE(regularPolygon.GetColor() == Color::Yellow);
		REQUIRE(regularPolygon.GetVertexCount() == vertexCount);
		REQUIRE(regularPolygon.GetCenterPoint().GetX() == centerPoint.GetX());
		REQUIRE(regularPolygon.GetCenterPoint().GetY() == centerPoint.GetY());
		REQUIRE(regularPolygon.GetRadius() == radius);
	}
}

TEST_CASE("Creating Invalid a Regular Polygon")
{
	CPoint centerPoint(10, 10);
	int vertexCount = 2;
	double radius = 5;
	THEN("Throwing an exception")
	{
		REQUIRE_THROWS(CRegularPolygon(Color::Pink, vertexCount, centerPoint, radius));
	}
}

TEST_CASE("Creating a Regular Polygon")
{
	CShapeFactory shapeFactory;
	auto shape = shapeFactory.CreateShape("rectangle red 1 4 3 2");
	// auto rectanle = // TODO: Првести к типу
	THEN("Created Rectangle")
	{
	}
}
