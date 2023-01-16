#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../lib/GroupShape/CGroupShape/CGroupShape.h"
#include "../lib/Shape/CEllipse/CEllipse.h"
#include "../lib/Shape/CRectangle/CRectangle.h"
#include "../lib/Shape/CTriangle/CTriangle.h"

SCENARIO("Creating a group")
{
	WHEN("A group is being created")
	{
		CGroupShape groupShape;

		THEN("The group is empty")
		{
			REQUIRE(groupShape.GetShapesCount() == 0);
		}
	}
}

SCENARIO("Working with an empty group")
{
	GIVEN("Empty group")
	{
		CGroupShape groupShape;

		WHEN("We get the zero element")
		{
			THEN("An exception is thrown")
			{
				REQUIRE_THROWS_AS(groupShape.GetShapeAtIndex(0), std::out_of_range);
			}
		}

		WHEN("We remove the zero element")
		{
			THEN("An exception is thrown")
			{
				REQUIRE_THROWS_AS(groupShape.RemoveShapeAtIndex(0), std::out_of_range);
			}
		}

		WHEN("We get the frame")
		{
			THEN("std::nullopt is returned")
			{
				REQUIRE(groupShape.GetFrame() == std::nullopt);
			}
		}
	}
}

SCENARIO("Adding items to a group")
{
	GIVEN("Empty group")
	{
		CGroupShape groupShape;

		WHEN("Adding an ellipse to the group")
		{
			auto ellipse = std::make_shared<CEllipse>(PointD{ 100, 100 }, 100, 50);
			groupShape.InsertShape(ellipse, 0);

			THEN("The number of figures in the group is 1")
			{
				REQUIRE(groupShape.GetShapesCount() == 1);
			}

			AND_THEN("The first element is equal to an ellipse")
			{
				REQUIRE(groupShape.GetShapeAtIndex(0) == ellipse);
			}
		}

		WHEN("Adding a rectangle to the group")
		{
			auto rectangle = std::make_shared<CRectangle>(PointD{ 100, 100 }, 100, 50);
			groupShape.InsertShape(rectangle, 0);

			THEN("The number of figures in the group is 1")
			{
				REQUIRE(groupShape.GetShapesCount() == 1);
			}

			AND_THEN("The first element is equal to a rectangle")
			{
				REQUIRE(groupShape.GetShapeAtIndex(0) == rectangle);
			}
		}

		WHEN("Adding a triangle to the group")
		{
			auto triangle = std::make_shared<CTriangle>(PointD{ 100, 100 }, PointD{ 125, 150 }, PointD{ 150, 100 });
			groupShape.InsertShape(triangle, 0);

			THEN("The number of figures in the group is 1")
			{
				REQUIRE(groupShape.GetShapesCount() == 1);
			}

			AND_THEN("The first element is equal to a triangle")
			{
				REQUIRE(groupShape.GetShapeAtIndex(0) == triangle);
			}
		}

		WHEN("Adding a groupShape to the group")
		{
			auto innerGroupShape = std::make_shared<CGroupShape>();
			groupShape.InsertShape(innerGroupShape, 0);

			THEN("The number of figures in the group is 1")
			{
				REQUIRE(groupShape.GetShapesCount() == 1);
			}

			AND_THEN("The first element is equal to a group")
			{
				REQUIRE(groupShape.GetShapeAtIndex(0) == innerGroupShape);
			}
		}

		WHEN("Adding a ellipse to the group in the first position")
		{
			auto ellipse = std::make_shared<CEllipse>(PointD{ 100, 100 }, 100, 50);

			THEN("An exception is thrown")
			{
				REQUIRE_THROWS_AS(groupShape.InsertShape(ellipse, 1), std::out_of_range);
			}

			AND_THEN("The number of figures in the group is 0")
			{
				REQUIRE(groupShape.GetShapesCount() == 0);
			}
		}

		WHEN("Adding a ellipse to the group in a negative position")
		{
			auto ellipse = std::make_shared<CEllipse>(PointD{ 100, 100 }, 100, 50);

			THEN("An exception is thrown")
			{
				REQUIRE_THROWS_AS(groupShape.InsertShape(ellipse, -1), std::out_of_range);
			}

			AND_THEN("The number of figures in the group is 0")
			{
				REQUIRE(groupShape.GetShapesCount() == 0);
			}
		}

		WHEN("Several shapes are added to the end")
		{
			auto ellipse = std::make_shared<CEllipse>(PointD{ 100, 100 }, 100, 50);
			auto rectangle = std::make_shared<CRectangle>(PointD{ 100, 100 }, 100, 50);
			auto triangle = std::make_shared<CTriangle>(PointD{ 100, 100 }, PointD{ 125, 150 }, PointD{ 150, 100 });
			groupShape.InsertShape(ellipse, 0);
			groupShape.InsertShape(rectangle, 1);
			groupShape.InsertShape(triangle, 2);

			THEN("The number of figures in the group is 3")
			{
				REQUIRE(groupShape.GetShapesCount() == 3);
			}

			AND_THEN("The figures were added in the right order")
			{
				REQUIRE(groupShape.GetShapeAtIndex(0) == ellipse);
				REQUIRE(groupShape.GetShapeAtIndex(1) == rectangle);
				REQUIRE(groupShape.GetShapeAtIndex(2) == triangle);
			}
		}

		WHEN("Several shapes are added to the begin")
		{
			auto ellipse = std::make_shared<CEllipse>(PointD{ 100, 100 }, 100, 50);
			auto rectangle = std::make_shared<CRectangle>(PointD{ 100, 100 }, 100, 50);
			auto triangle = std::make_shared<CTriangle>(PointD{ 100, 100 }, PointD{ 125, 150 }, PointD{ 150, 100 });
			groupShape.InsertShape(ellipse, 0);
			groupShape.InsertShape(rectangle, 0);
			groupShape.InsertShape(triangle, 0);

			THEN("The number of figures in the group is 3")
			{
				REQUIRE(groupShape.GetShapesCount() == 3);
			}

			AND_THEN("The figures were added in the right order")
			{
				REQUIRE(groupShape.GetShapeAtIndex(0) == triangle);
				REQUIRE(groupShape.GetShapeAtIndex(1) == rectangle);
				REQUIRE(groupShape.GetShapeAtIndex(2) == ellipse);
			}
		}
	}
}

SCENARIO("Removing items from a group")
{
	GIVEN("A group with 4 figures")
	{
		CGroupShape groupShape;
		auto ellipse = std::make_shared<CEllipse>(PointD{ 100, 100 }, 100, 50);
		auto rectangle = std::make_shared<CRectangle>(PointD{ 100, 100 }, 100, 50);
		auto triangle = std::make_shared<CTriangle>(PointD{ 100, 100 }, PointD{ 125, 150 }, PointD{ 150, 100 });
		auto innerGroupShape = std::make_shared<CGroupShape>();
		groupShape.InsertShape(ellipse, 0);
		groupShape.InsertShape(rectangle, 1);
		groupShape.InsertShape(triangle, 2);
		groupShape.InsertShape(innerGroupShape, 3);

		WHEN("Removing an element from the beginning")
		{
			groupShape.RemoveShapeAtIndex(0);

			THEN("The number of figures in the group is 3")
			{
				REQUIRE(groupShape.GetShapesCount() == 3);
			}

			AND_THEN("The first element is equal to an ellipse")
			{
				REQUIRE(groupShape.GetShapeAtIndex(0) == rectangle);
				REQUIRE(groupShape.GetShapeAtIndex(1) == triangle);
				REQUIRE(groupShape.GetShapeAtIndex(2) == innerGroupShape);
			}
		}

		WHEN("Removing an element from the beginning")
		{
			groupShape.RemoveShapeAtIndex(3);

			THEN("The number of figures in the group is 3")
			{
				REQUIRE(groupShape.GetShapesCount() == 3);
			}

			AND_THEN("The first element is equal to an ellipse")
			{
				REQUIRE(groupShape.GetShapeAtIndex(0) == ellipse);
				REQUIRE(groupShape.GetShapeAtIndex(1) == rectangle);
				REQUIRE(groupShape.GetShapeAtIndex(2) == triangle);
			}
		}

		WHEN("Deleting an element by a nonexistent index")
		{
			THEN("An exception is thrown")
			{
				REQUIRE_THROWS_AS(groupShape.RemoveShapeAtIndex(4), std::out_of_range);
			}

			AND_THEN("The number of figures in the group is 4")
			{
				REQUIRE(groupShape.GetShapesCount() == 4);
			}
		}

		WHEN("Deleting an element by a negative index")
		{
			THEN("An exception is thrown")
			{
				REQUIRE_THROWS_AS(groupShape.RemoveShapeAtIndex(-1), std::out_of_range);
			}

			AND_THEN("The number of figures in the group is 4")
			{
				REQUIRE(groupShape.GetShapesCount() == 4);
			}
		}
	}
}

SCENARIO("Getting and installing a frame")
{
	GIVEN("A group with 2 figures")
	{
		CGroupShape groupShape;
		auto ellipse = std::make_shared<CEllipse>(PointD{ 10, 10 }, 10, 5);
		auto rectangle = std::make_shared<CRectangle>(PointD{ 10, 20 }, 20, 10);
		groupShape.InsertShape(ellipse, 0);
		groupShape.InsertShape(rectangle, 1);

		WHEN("Getting the frame")
		{
			auto frameOpt = groupShape.GetFrame();

			THEN("The frame exists")
			{
				REQUIRE(frameOpt.has_value() == true);
			}

			AND_THEN("The frame captures all the shapes")
			{
				auto frame = frameOpt.value();
				REQUIRE(frame.left == 0);
				REQUIRE(frame.top == 20);
				REQUIRE(frame.width == 30);
				REQUIRE(frame.height == 15);
			}
		}

		WHEN("The frame is moving")
		{
			groupShape.SetFrame({ 10, 25, 30, 15 });
			auto frameOpt = groupShape.GetFrame();

			THEN("The frame exists")
			{
				REQUIRE(frameOpt.has_value() == true);
			}

			AND_THEN("The frame captures all the shapes")
			{
				auto frame = frameOpt.value();
				REQUIRE(frame.left == 10);
				REQUIRE(frame.top == 25);
				REQUIRE(frame.width == 30);
				REQUIRE(frame.height == 15);
			}
		}

		WHEN("The frame increases in size")
		{
			groupShape.SetFrame({ 0, 35, 60, 30 });
			auto frameOpt = groupShape.GetFrame();

			THEN("The frame exists")
			{
				REQUIRE(frameOpt.has_value() == true);
			}

			AND_THEN("The frame captures all the shapes")
			{
				auto frame = frameOpt.value();
				REQUIRE(frame.left == 0);
				REQUIRE(frame.top == 35);
				REQUIRE(frame.width == 60);
				REQUIRE(frame.height == 30);
			}

			AND_THEN("The dimensions of each figure have changed")
			{
				auto ellipseChanged = groupShape.GetShapeAtIndex(0)->GetFrame().value();
				auto rectangleChanged = groupShape.GetShapeAtIndex(1)->GetFrame().value();
				REQUIRE(ellipseChanged.left == 0);
				REQUIRE(ellipseChanged.top == 25);
				REQUIRE(ellipseChanged.width == 40);
				REQUIRE(ellipseChanged.height == 20);
				REQUIRE(rectangleChanged.left == 20);
				REQUIRE(rectangleChanged.top == 35);
				REQUIRE(rectangleChanged.width == 40);
				REQUIRE(rectangleChanged.height == 20);
			}
		}

		WHEN("The shapes have different styles")
		{
			auto fillStyleEllipse = ellipse->GetFillStyle();
			auto fillStyleRectangle = rectangle->GetFillStyle();
			auto outlineStyleEllipse = ellipse->GetOutlineStyle();
			auto outlineStyleRectangle = rectangle->GetOutlineStyle();
			fillStyleEllipse->Enable(true);
			fillStyleRectangle->Enable(false);
			fillStyleEllipse->SetColor(0xFF0000);
			fillStyleRectangle->SetColor(0x0000FF);
			outlineStyleEllipse->Enable(false);
			outlineStyleRectangle->Enable(true);
			outlineStyleEllipse->SetColor(0x0000FF);
			outlineStyleRectangle->SetColor(0xFF0000);
			outlineStyleEllipse->SetThickness(1);
			outlineStyleRectangle->SetThickness(2);

			THEN("Common styles are not defined")
			{
				auto fillStyle = groupShape.GetFillStyle();
				auto outlineStyle = groupShape.GetOutlineStyle();
				REQUIRE(fillStyle->GetColor().has_value() == false);
				REQUIRE(fillStyle->IsEnabled().has_value() == false);
				REQUIRE(outlineStyle->GetColor().has_value() == false);
				REQUIRE(outlineStyle->IsEnabled().has_value() == false);
				REQUIRE(outlineStyle->GetThickness().has_value() == false);
			}

			AND_WHEN("Set common styles")
			{
				groupShape.GetFillStyle()->SetColor(0xFFFF00);
				groupShape.GetFillStyle()->Enable(true);
				groupShape.GetOutlineStyle()->SetColor(0x00FFFF);
				groupShape.GetOutlineStyle()->Enable(true);
				groupShape.GetOutlineStyle()->SetThickness(3);

				THEN("Common styles defined")
				{
					auto fillStyle = groupShape.GetFillStyle();
					auto outlineStyle = groupShape.GetOutlineStyle();
					REQUIRE(fillStyle->GetColor().has_value() == true);
					REQUIRE(fillStyle->IsEnabled().has_value() == true);
					REQUIRE(outlineStyle->GetColor().has_value() == true);
					REQUIRE(outlineStyle->IsEnabled().has_value() == true);
					REQUIRE(outlineStyle->GetThickness().has_value() == true);
				}

				AND_THEN("Common styles have the same values")
				{
					auto fillStyle = groupShape.GetFillStyle();
					auto outlineStyle = groupShape.GetOutlineStyle();
					REQUIRE(fillStyle->GetColor().value() == 0xFFFF00);
					REQUIRE(fillStyle->IsEnabled().value() == true);
					REQUIRE(outlineStyle->GetColor().value() == 0x00FFFF);
					REQUIRE(outlineStyle->IsEnabled().value() == true);
					REQUIRE(outlineStyle->GetThickness().value() == 3);
				}

				AND_THEN("Each figure's styles have changed")
				{
					fillStyleEllipse = ellipse->GetFillStyle();
					fillStyleRectangle = rectangle->GetFillStyle();
					outlineStyleEllipse = ellipse->GetOutlineStyle();
					outlineStyleRectangle = rectangle->GetOutlineStyle();
					REQUIRE(fillStyleEllipse->GetColor().value() == 0xFFFF00);
					REQUIRE(fillStyleRectangle->GetColor().value() == 0xFFFF00);
					REQUIRE(fillStyleEllipse->IsEnabled().value() == true);
					REQUIRE(fillStyleRectangle->IsEnabled().value() == true);
					REQUIRE(outlineStyleEllipse->GetColor().value() == 0x00FFFF);
					REQUIRE(outlineStyleRectangle->GetColor().value() == 0x00FFFF);
					REQUIRE(outlineStyleEllipse->IsEnabled().value() == true);
					REQUIRE(outlineStyleRectangle->IsEnabled().value() == true);
					REQUIRE(outlineStyleEllipse->GetThickness().value() == 3);
					REQUIRE(outlineStyleRectangle->GetThickness().value() == 3);
				}
			}
		}
	}
}

SCENARIO("Testing an empty CGroupShape frame")
{
	CGroupShape groupShape;

	WHEN("group includes rectangle and ellipse")
	{
		auto ellipse = std::make_shared<CEllipse>(PointD{ 10, 10 }, 10, 5);
		auto rectangle = std::make_shared<CRectangle>(PointD{ 10, 20 }, 20, 10);
		auto innerGroupShape = std::make_shared<CGroupShape>();
		groupShape.InsertShape(ellipse, 0);
		groupShape.InsertShape(rectangle, 1);
		groupShape.InsertShape(innerGroupShape, 2);

		WHEN("Getting the group frame")
		{
			auto frameOpt = groupShape.GetFrame();

			THEN("The frame exists")
			{
				REQUIRE(frameOpt.has_value());

				AND_WHEN("We get the values")
				{
					auto frame = frameOpt.value();
					REQUIRE(frame.left == 0);
					REQUIRE(frame.top == 20);
					REQUIRE(frame.width == 30);
					REQUIRE(frame.height == 15);
				}
			}
		}
	}
}
