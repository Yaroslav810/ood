#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../lib/Color/Color.h"
#include "../lib/Designer/CDesigner.h"
#include "../lib/PictureDraft/CPictureDraft.h"
#include "../lib/Point/CPoint.h"
#include "../lib/Shape/Ellipse/CEllipse.h"
#include "../lib/Shape/Rectangle/CRectangle.h"
#include "../lib/Shape/RegularPolygon/CRegularPolygon.h"
#include "../lib/Shape/Triangle/CTriangle.h"
#include "../lib/ShapeFactory/CShapeFactory.h"

SCENARIO("Creating shapes")
{
	WHEN("Creating a Rectangle")
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

	WHEN("Creating a Triangle")
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

	WHEN("Creating an Ellipse")
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

	WHEN("Creating a Regular Polygon")
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

	WHEN("Creating Invalid a Regular Polygon")
	{
		CPoint centerPoint(10, 10);
		int vertexCount = 2;
		double radius = 5;
		THEN("Throwing an exception")
		{
			REQUIRE_THROWS(CRegularPolygon(Color::Pink, vertexCount, centerPoint, radius));
		}
	}
}

SCENARIO("Testing CPictureDraft")
{
	WHEN("Creating CPictureDraft")
	{
		CPictureDraft cPictureDraft;

		THEN("An empty draft is created")
		{
			REQUIRE(cPictureDraft.GetShapesCount() == 0);
			REQUIRE_THROWS_AS(cPictureDraft.GetShape(0), std::out_of_range);
		}
	}

	WHEN("Fill in the draft with figures")
	{
		CPictureDraft pictureDraft;
		CRectangle rectangle(Color::Green, { 10, 10 }, {100, 60});
		CTriangle triangle(Color::Red, {5, 5}, {15, 5}, {10, 10});
		CEllipse ellipse(Color::Blue, {20, 20}, 8, 5);
		CRegularPolygon regularPolygon(Color::Yellow, 4, {10, 10}, 5);

		REQUIRE_NOTHROW(pictureDraft.AddShape(std::make_unique<CRectangle>(rectangle)));
		REQUIRE_NOTHROW(pictureDraft.AddShape(std::make_unique<CTriangle>(triangle)));
		REQUIRE_NOTHROW(pictureDraft.AddShape(std::make_unique<CEllipse>(ellipse)));
		REQUIRE_NOTHROW(pictureDraft.AddShape(std::make_unique<CRegularPolygon>(regularPolygon)));

		THEN("Figures have been added")
		{
			REQUIRE(pictureDraft.GetShapesCount() == 4);

			AND_WHEN("We get the second figure of the draft")
			{
				CEllipse shape = dynamic_cast<CEllipse&>(pictureDraft.GetShape(2));
				REQUIRE(shape.GetCenter().GetX() == 20);
				REQUIRE(shape.GetCenter().GetY() == 20);
				REQUIRE(shape.GetHorizontalRadius() == 8);
				REQUIRE(shape.GetVerticalRadius() == 5);
				REQUIRE(shape.GetColor() == Color::Blue);
			}
		}
	}
}

SCENARIO("Testing CShapeFactory")
{
	CShapeFactory shapeFactory;

	WHEN("When we submit an invalid string")
	{
		THEN("An exception is thrown")
		{
			REQUIRE_THROWS_AS(shapeFactory.CreateShape(""), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeFactory.CreateShape("shape 100, 100"), std::invalid_argument);
			REQUIRE_THROWS_AS(shapeFactory.CreateShape("rectangle"), std::invalid_argument);
		}
	}

	WHEN("Creating a Rectangle")
	{
		auto shape = shapeFactory.CreateShape("rectangle red 50 50 150 100");
		auto rectangle = dynamic_cast<CRectangle&>(*shape);

		THEN("Created Rectangle")
		{
			REQUIRE(rectangle.GetColor() == Color::Red);
			REQUIRE(rectangle.GetLeftTop().GetX() == 50);
			REQUIRE(rectangle.GetLeftTop().GetY() == 50);
			REQUIRE(rectangle.GetRightBottom().GetX() == 150);
			REQUIRE(rectangle.GetRightBottom().GetY() == 100);
		}
	}

	WHEN("Creating a Triangle")
	{
		auto shape = shapeFactory.CreateShape("triangle yellow 50 200 100 250 200 200");
		auto triangle = dynamic_cast<CTriangle&>(*shape);

		THEN("Created Triangle")
		{
			REQUIRE(triangle.GetColor() == Color::Yellow);
			REQUIRE(triangle.GetFirstVertex().GetX() == 50);
			REQUIRE(triangle.GetFirstVertex().GetY() == 200);
			REQUIRE(triangle.GetSecondVertex().GetX() == 100);
			REQUIRE(triangle.GetSecondVertex().GetY() == 250);
			REQUIRE(triangle.GetThirdVertex().GetX() == 200);
			REQUIRE(triangle.GetThirdVertex().GetY() == 200);
		}
	}

	WHEN("Creating an Ellipse")
	{
		auto shape = shapeFactory.CreateShape("ellipse green 400 300 100 50");
		auto ellipse = dynamic_cast<CEllipse&>(*shape);

		THEN("Created Ellipse")
		{
			REQUIRE(ellipse.GetColor() == Color::Green);
			REQUIRE(ellipse.GetCenter().GetX() == 400);
			REQUIRE(ellipse.GetCenter().GetY() == 300);
			REQUIRE(ellipse.GetHorizontalRadius() == 100);
			REQUIRE(ellipse.GetVerticalRadius() == 50);
		}
	}

	WHEN("Creating a Regular Polygon")
	{
		auto shape = shapeFactory.CreateShape("regular-polygon pink 5 600 200 50");
		auto regularPolygon = dynamic_cast<CRegularPolygon&>(*shape);

		THEN("Created Regular Polygon")
		{
			REQUIRE(regularPolygon.GetColor() == Color::Pink);
			REQUIRE(regularPolygon.GetVertexCount() == 5);
			REQUIRE(regularPolygon.GetCenterPoint().GetX() == 600);
			REQUIRE(regularPolygon.GetCenterPoint().GetY() == 200);
			REQUIRE(regularPolygon.GetRadius() == 50);
		}
	}
}

SCENARIO("Testing CDesigner")
{
	WHEN("Creating CDesigner")
	{
		CShapeFactory shapeFactory;
		CDesigner designer(shapeFactory);

		AND_WHEN("Calling CreateDraft")
		{
			std::stringstream ss;
			ss << "rectangle red 50 50 150 100" << std::endl << "triangle yellow 50 200 100 250 200 200" << std::endl;
			auto pictureDraft = designer.CreateDraft(ss);

			THEN("A valid CPictureDraft has been created")
			{
				REQUIRE(pictureDraft.GetShapesCount() == 2);
				CRectangle rectangle = dynamic_cast<CRectangle&>(pictureDraft.GetShape(0));
				REQUIRE(rectangle.GetLeftTop().GetX() == 50);
				REQUIRE(rectangle.GetLeftTop().GetY() == 50);
				REQUIRE(rectangle.GetRightBottom().GetX() == 150);
				REQUIRE(rectangle.GetRightBottom().GetY() == 100);
				REQUIRE(rectangle.GetColor() == Color::Red);
				CTriangle triangle = dynamic_cast<CTriangle&>(pictureDraft.GetShape(1));
				REQUIRE(triangle.GetFirstVertex().GetX() == 50);
				REQUIRE(triangle.GetFirstVertex().GetY() == 200);
				REQUIRE(triangle.GetSecondVertex().GetX() == 100);
				REQUIRE(triangle.GetSecondVertex().GetY() == 250);
				REQUIRE(triangle.GetThirdVertex().GetX() == 200);
				REQUIRE(triangle.GetThirdVertex().GetY() == 200);
				REQUIRE(triangle.GetColor() == Color::Yellow);
			}
		}
	}
}
