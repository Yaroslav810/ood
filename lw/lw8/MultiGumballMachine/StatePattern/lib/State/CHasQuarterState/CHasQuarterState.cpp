#include "CHasQuarterState.h"

CHasQuarterState::CHasQuarterState(IGumballMachine& gumballMachine)
	: m_gumballMachine(gumballMachine)
{
}

void CHasQuarterState::InsertQuarter()
{
	if (m_gumballMachine.GetQuarterCount() == MAX_QUARTER)
	{
		std::cout << "You can't insert another quarter\n";
	}
	else
	{
		std::cout << "You inserted another quarter\n";
		m_gumballMachine.AddQuarter();
	}
}

void CHasQuarterState::EjectQuarter()
{
	std::cout << "Quarter returned" << std::endl;
	m_gumballMachine.PulloutQuarterAll();
	m_gumballMachine.SetNoQuarterState();
}

void CHasQuarterState::TurnCrank()
{
	std::cout << "You turned..." << std::endl;
	m_gumballMachine.SetSoldState();
}

void CHasQuarterState::Dispense()
{
	std::cout << "No gumball dispensed" << std::endl;
}

std::string CHasQuarterState::ToString() const
{
	return "waiting for turn of crank";
}
