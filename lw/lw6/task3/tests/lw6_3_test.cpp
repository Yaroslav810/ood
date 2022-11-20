#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../lib/CModernGraphicsLibAdapter.h"

SCENARIO("Working with the adapter")
{
	GIVEN("Class CModernGraphicsRenderer of the modern_graphics_lib library")
	{
		std::ostringstream oss;
		modern_graphics_lib::CModernGraphicsRenderer renderer(oss);
		WHEN("An adapter is being created")
		{
			CModernGraphicsLibAdapter adapter(renderer);
			THEN("Can call MoveTo")
			{
				REQUIRE_NOTHROW(adapter.MoveTo(100, 100));
			}
			THEN("An exception is thrown when calling LineTo")
			{
				REQUIRE_THROWS(adapter.LineTo(200, 200));
			}

			AND_WHEN("Calling the method BeginDraw")
			{
				renderer.BeginDraw();
				THEN("Can call MoveTo and LineTo")
				{
					REQUIRE_NOTHROW(adapter.MoveTo(100, 100));
					REQUIRE_NOTHROW(adapter.LineTo(200, 200));
				}

				AND_WHEN("Draw a line")
				{
					adapter.MoveTo(100, 100);
					adapter.LineTo(200, 200);
					THEN("Shapes are being drawn")
					{
						REQUIRE(oss.str() == "<draw>\n<line fromX=100 fromY=100 toX=200 toY=200 />\n");
					}

					AND_WHEN("Calling the method EndDraw")
					{
						renderer.EndDraw();
						THEN("The final draw is added")
						{
							REQUIRE(oss.str() == "<draw>\n<line fromX=100 fromY=100 toX=200 toY=200 />\n</draw>\n");
						}
					}
				}

				AND_WHEN("Calling the method EndDraw")
				{
					renderer.EndDraw();
					THEN("Can call MoveTo")
					{
						REQUIRE_NOTHROW(adapter.MoveTo(100, 100));
					}
					THEN("An exception is thrown when calling LineTo")
					{
						REQUIRE_THROWS(adapter.LineTo(200, 200));
					}
				}
			}
		}
	}
}
