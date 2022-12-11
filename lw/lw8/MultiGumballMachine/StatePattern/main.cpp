#include "lib/GumballMachine/CGumballMachine/CGumballMachine.h"
#include <iostream>

template <typename GumballMachineType>
void TestGumballMachine(GumballMachineType& m)
{
	std::cout << m.ToString() << std::endl;

	m.InsertQuarter();
	m.TurnCrank();

	std::cout << m.ToString() << std::endl;

	m.InsertQuarter();
	m.EjectQuarter();
	m.TurnCrank();

	std::cout << m.ToString() << std::endl;

	m.InsertQuarter();
	m.TurnCrank();
	m.InsertQuarter();
	m.TurnCrank();
	m.EjectQuarter();

	std::cout << m.ToString() << std::endl;

	m.InsertQuarter();
	m.InsertQuarter();
	m.TurnCrank();
	m.InsertQuarter();
	m.TurnCrank();
	m.InsertQuarter();
	m.TurnCrank();

	std::cout << m.ToString() << std::endl;
}

void TestGumballMachineWithState()
{
	CGumballMachine machine(5);
	TestGumballMachine(machine);
}

int main()
{
	TestGumballMachineWithState();
	return 0;
}
