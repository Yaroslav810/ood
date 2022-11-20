#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../lib/CModernGraphicsLibAdapter.h"

SCENARIO("Working with the adapter")
{
	GIVEN("Ostringstream")
	{
		std::ostringstream oss;
		WHEN("An adapter is being created")
		{
			CModernGraphicsLibAdapter adapter(oss);
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
				adapter.BeginDraw();
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
						adapter.EndDraw();
						THEN("The final draw is added")
						{
							REQUIRE(oss.str() == "<draw>\n<line fromX=100 fromY=100 toX=200 toY=200 />\n</draw>\n");
						}
					}
				}

				AND_WHEN("Calling the method EndDraw")
				{
					adapter.EndDraw();
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
