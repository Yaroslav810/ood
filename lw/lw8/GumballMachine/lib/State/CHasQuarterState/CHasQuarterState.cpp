#include "CHasQuarterState.h"

CHasQuarterState::CHasQuarterState(IGumballMachine& gumballMachine)
	: m_gumballMachine(gumballMachine)
{
}

void CHasQuarterState::InsertQuarter()
{
	std::cout << "You can't insert another quarter" << std::endl;
}

void CHasQuarterState::EjectQuarter()
{
	std::cout << "Quarter returned" << std::endl;
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
