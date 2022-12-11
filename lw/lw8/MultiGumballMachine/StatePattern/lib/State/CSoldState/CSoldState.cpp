#include "CSoldState.h"

CSoldState::CSoldState(IGumballMachine& gumballMachine)
	: m_gumballMachine(gumballMachine)
{
}

void CSoldState::InsertQuarter()
{
	std::cout << "Please wait, we're already giving you a gumball" << std::endl;
}

void CSoldState::EjectQuarter()
{
	std::cout << "Sorry you already turned the crank" << std::endl;
}

void CSoldState::TurnCrank()
{
	std::cout << "Turning twice doesn't get you another gumball" << std::endl;
}

void CSoldState::Dispense()
{
	m_gumballMachine.ReleaseBall();
	m_gumballMachine.PulloutQuarter();
	if (m_gumballMachine.GetBallCount() == 0)
	{
		std::cout << "Oops, out of gumballs" << std::endl;
		m_gumballMachine.SetSoldOutState();
	}
	else
	{
		if (m_gumballMachine.GetQuarterCount() > 0)
		{
			m_gumballMachine.SetHasQuarterState();
		}
		else
		{
			m_gumballMachine.SetNoQuarterState();
		}
	}
}

std::string CSoldState::ToString() const
{
	return "delivering a gumball";
}
