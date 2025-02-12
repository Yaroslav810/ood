#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../lib/GumballMachine/CGumballMachine/CGumballMachine.h"

std::string CreateOutputGumballMachineString(unsigned count, const std::string& state)
{
	std::string str;
	str.append("Mighty Gumball, Inc.\n");
	str.append("C++-enabled Standing Gumball Model #2016 (with state)\n");
	str.append("Inventory: " + std::to_string(count) + " gumball" + (count != 1 ? "s" : "") + "\n");
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
			REQUIRE(machine.ToString() == CreateOutputGumballMachineString(5, "waiting for quarter"));
		}
	}

	WHEN("Creating a machine with 0 gumball")
	{
		CGumballMachine machine(0);
		THEN("The machine is in the state of sold out")
		{
			REQUIRE(machine.ToString() == CreateOutputGumballMachineString(0, "sold out"));
		}
	}
}

SCENARIO("In the state of no quarter, you can only insert a quarter")
{
	GIVEN("Machine with 5 gumball")
	{
		CGumballMachine machine(5);

		WHEN("Insert quarter")
		{
			machine.InsertQuarter();
			THEN("The machine goes into the state there is a has quarter")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(5, "waiting for turn of crank"));
			}
		}

		WHEN("Eject quarter")
		{
			machine.EjectQuarter();
			THEN("The condition of the machine has not changed")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(5, "waiting for quarter"));
			}
		}

		WHEN("Turn crank")
		{
			machine.TurnCrank();
			THEN("The machine goes into the state there is a has quarter")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(5, "waiting for quarter"));
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
			THEN("You can't insert another quarter")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(5, "waiting for turn of crank"));
			}
		}

		WHEN("Eject quarter")
		{
			machine.EjectQuarter();
			THEN("Quarter returned")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(5, "waiting for quarter"));
			}
		}

		WHEN("Turn crank")
		{
			machine.TurnCrank();
			THEN("A gumball comes rolling out the slot and the machine goes into the state of no quarter")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(4, "waiting for quarter"));
			}
		}

		// TODO: Добавить в 0
		WHEN("Turn crank 5 times")
		{
			machine.InsertQuarter();
			machine.TurnCrank();
			machine.InsertQuarter();
			machine.TurnCrank();
			machine.InsertQuarter();
			machine.TurnCrank();
			machine.InsertQuarter();
			machine.TurnCrank();
			THEN("A gumball comes rolling out the slot and the machine goes into the state of no quarter")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(4, "waiting for quarter"));
			}
		}
	}
}

SCENARIO("In the state of sold out, nothing can be done")
{
	GIVEN("Machine with 0 gumball")
	{
		CGumballMachine machine(0);

		WHEN("Insert quarter")
		{
			machine.InsertQuarter();
			THEN("You can't insert a quarter, the machine is sold out")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(0, "sold out"));
			}
		}

		WHEN("Eject quarter")
		{
			machine.EjectQuarter();
			THEN("You can't eject, you haven't inserted a quarter yet")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(0, "sold out"));
			}
		}

		WHEN("Turn crank")
		{
			machine.TurnCrank();
			THEN("You turned but there's no gumballs")
			{
				REQUIRE(machine.ToString() == CreateOutputGumballMachineString(0, "sold out"));
			}
		}
	}
}
