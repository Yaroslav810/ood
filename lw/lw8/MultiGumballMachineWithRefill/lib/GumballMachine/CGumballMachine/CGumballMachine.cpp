#include "CGumballMachine.h"

CGumballMachine::CGumballMachine(unsigned int numBalls)
	: m_soldState(*this)
	, m_soldOutState(*this)
	, m_noQuarterState(*this)
	, m_hasQuarterState(*this)
	, m_state(&m_soldOutState)
	, m_count(numBalls)
{
	if (m_count > 0)
	{
		m_state = &m_noQuarterState;
	}
}

void CGumballMachine::EjectQuarter()
{
	m_state->EjectQuarter();
}

void CGumballMachine::InsertQuarter()
{
	m_state->InsertQuarter();
}

void CGumballMachine::TurnCrank()
{
	m_state->TurnCrank();
	m_state->Dispense();
}

void CGumballMachine::AddBalls(unsigned int numBalls)
{
	m_state->AddBalls(numBalls);
}

std::string CGumballMachine::ToString() const
{
	std::string str;
	str.append("Mighty Gumball, Inc.\n");
	str.append("C++-enabled Standing Gumball Model #2016 (with state)\n");
	str.append("Inventory: " + std::to_string(m_count) + " gumball" + (m_count != 1 ? "s" : "") + "\n");
	str.append("Number of quarter: " + std::to_string(m_quarterCount) + " quarter" + (m_quarterCount != 1 ? "s" : "") + "\n");
	str.append("Machine is " + m_state->ToString() + "\n");
	return str;
}

void CGumballMachine::Refill(unsigned numBalls)
{
	m_count = numBalls;
}

unsigned CGumballMachine::GetBallCount() const
{
	return m_count;
}

void CGumballMachine::ReleaseBall()
{
	if (m_count != 0)
	{
		std::cout << "A gumball comes rolling out the slot...\n";
		--m_count;
	}
}

void CGumballMachine::AddQuarter()
{
	if (m_quarterCount != MAX_QUARTER)
	{
		++m_quarterCount;
	}
}

void CGumballMachine::PulloutQuarter()
{
	if (m_quarterCount != 0)
	{
		--m_quarterCount;
	}
}

void CGumballMachine::PulloutQuarterAll()
{
	m_quarterCount = 0;
}

unsigned CGumballMachine::GetQuarterCount() const
{
	return m_quarterCount;
}

void CGumballMachine::SetSoldOutState()
{
	m_state = &m_soldOutState;
}

void CGumballMachine::SetNoQuarterState()
{
	m_state = &m_noQuarterState;
}

void CGumballMachine::SetSoldState()
{
	m_state = &m_soldState;
}

void CGumballMachine::SetHasQuarterState()
{
	m_state = &m_hasQuarterState;
}