#include "CSoldOutState.h"

CSoldOutState::CSoldOutState(IGumballMachine& gumballMachine)
	: m_gumballMachine(gumballMachine)
{
}

void CSoldOutState::InsertQuarter()
{
	std::cout << "You can't insert a quarter, the machine is sold out" << std::endl;
}

void CSoldOutState::EjectQuarter()
{
	if (m_gumballMachine.GetQuarterCount() == 0)
	{
		std::cout << "You can't eject, you haven't inserted a quarter yet\n";
	}
	else
	{
		std::cout << "Quarter returned\n";
		m_gumballMachine.PulloutQuarterAll();
	}
}

void CSoldOutState::TurnCrank()
{
	std::cout << "You turned but there's no gumballs" << std::endl;
}

void CSoldOutState::Dispense()
{
	std::cout << "No gumball dispensed" << std::endl;
}

std::string CSoldOutState::ToString() const
{
	return "sold out";
}
