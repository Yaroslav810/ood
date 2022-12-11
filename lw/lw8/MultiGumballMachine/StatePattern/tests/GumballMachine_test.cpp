#define CATCH_CONFIG_MAIN
#include "../../../../../catch2/catch.hpp"
#include "../lib/GumballMachine/CGumballMachine/CGumballMachine.h"

std::string CreateOutputGumballMachineString(unsigned count, unsigned quarterCount, const std::string& state)
{
	std::string str;
	str.append("Mighty Gumball, Inc.\n");
	str.append("C++-enabled Standing Gumball Model #2016 (with state)\n");
	str.append("Inventory: " + std::to_string(count) + " gumball" + (count != 1 ? "s" : "") + "\n");
	str.append("Number of quarter: " + std::to_string(quarterCount) + " quarter" + (quarterCount != 1 ? "s" : "") + "\n");
	str.append("Machine is " + state + "\n");
	return str;
}

SCENARIO("The machine is being created in a valid state")
{
	WHEN("Creating a machine with 5 gumball")
	{
		CGumballMachine machine(5);
		THEN("The machine is in the state of no quarter")
		{
			REQUIRE(machine.ToString() == CreateOutputGumballMachineString(5, 0, "waiting for quarter"));
		}
	}

	WHEN("Creating a machine with 0 gumball")
	{
		CGumballMachine machine(0);
		THEN("The machine is in the state of sold out")
		{
			REQUIRE(machine.ToString() == CreateOutputGumballMachineString(0, 0, "sold out"));
		}
	}
}

SCENARIO("In the state of no quarter, you can only insert a quarter (up to 5)")
{
	GIVEN("Machine with 5 gumball")
	{
		CGumballMachine machine(5);

		WHEN("Insert quarter")
		{
			machine.InsertQuarter();
			THEN("The machine goes into the state there is a has quarter (1)")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(5, 1, "waiting for turn of crank"));
			}
		}

		WHEN("Eject quarter")
		{
			machine.EjectQuarter();
			THEN("The condition of the machine has not changed")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(5, 0, "waiting for quarter"));
			}
		}

		WHEN("Turn crank")
		{
			machine.TurnCrank();
			THEN("The machine goes into the state there is a has quarter")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(5, 0, "waiting for quarter"));
			}
		}
	}
}

SCENARIO("In the state of has quarter, you can eject a quarter or turn crank")
{
	GIVEN("Machine with 5 gumball with quarter")
	{
		CGumballMachine machine(5);
		machine.InsertQuarter();

		WHEN("Insert quarter")
		{
			machine.InsertQuarter();
			THEN("You can insert another quarter")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(5, 2, "waiting for turn of crank"));
			}

			AND_WHEN("Insert 3 more quarters")
			{
				machine.InsertQuarter();
				machine.InsertQuarter();
				machine.InsertQuarter();

				THEN("The machine goes into the state there is a has quarter (5)")
				{
					REQUIRE(machine.ToString() == CreateOutputGumballMachineString(5, 5, "waiting for turn of crank"));
				}

				AND_WHEN("Insert quarter")
				{
					machine.InsertQuarter();
					THEN("The quarter will not be added")
					{
						REQUIRE(machine.ToString() == CreateOutputGumballMachineString(5, 5, "waiting for turn of crank"));
					}
				}

				AND_WHEN("Eject quarter")
				{
					machine.EjectQuarter();
					THEN("All quarters are issued")
					{
						REQUIRE(machine.ToString() == CreateOutputGumballMachineString(5, 0, "waiting for quarter"));
					}
				}
			}
		}

		WHEN("Eject quarter")
		{
			machine.EjectQuarter();
			THEN("Quarter returned")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(5, 0, "waiting for quarter"));
			}
		}

		WHEN("Turn crank")
		{
			machine.TurnCrank();
			THEN("A gumball comes rolling out the slot and the machine goes into the state of no quarter")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(4, 0, "waiting for quarter"));
			}
		}
	}
}

SCENARIO("In the state of sold out, you can only give out quarters")
{
	GIVEN("Machine with 0 gumball")
	{
		CGumballMachine machine(0);

		WHEN("Insert quarter")
		{
			machine.InsertQuarter();
			THEN("You can't insert a quarter, the machine is sold out")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(0, 0, "sold out"));
			}
		}

		WHEN("Eject quarter")
		{
			machine.EjectQuarter();
			THEN("You can't eject, you haven't inserted a quarter yet")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(0, 0, "sold out"));
			}
		}

		WHEN("Turn crank")
		{
			machine.TurnCrank();
			THEN("You turned but there's no gumballs")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(0, 0, "sold out"));
			}
		}
	}

	GIVEN("Machine with 1 gumball and 3 quarters")
	{
		CGumballMachine machine(1);
		machine.InsertQuarter();
		machine.InsertQuarter();
		machine.InsertQuarter();

		WHEN("Turn crank")
		{
			machine.TurnCrank();
			THEN("Issuance of one gum, 2 quarters in the machine")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(0, 2, "sold out"));

				AND_WHEN("Eject quarter")
				{
					machine.EjectQuarter();

					THEN("All quarters are issued")
					{
						REQUIRE(machine.ToString() == CreateOutputGumballMachineString(0, 0, "sold out"));
					}

					AND_WHEN("Eject quarter")
					{
						machine.EjectQuarter();

						THEN("The state does not change")
						{
							REQUIRE(machine.ToString() == CreateOutputGumballMachineString(0, 0, "sold out"));
						}
					}
				}
			}
		}
	}
}
