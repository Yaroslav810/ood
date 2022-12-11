#pragma once
#include <iostream>

unsigned MAX_QUARTER = 5;

class CGumballMachine
{
public:
	enum class State
	{
		SoldOut, // Жвачка закончилась
		NoQuarter, // Нет монетки
		HasQuarter, // Есть монетка
		Sold, // Монетка выдана
	};

	explicit CGumballMachine(unsigned count)
		: m_count(count)
		, m_quarterCount(0)
		, m_state(count > 0 ? State::NoQuarter : State::SoldOut)
	{
	}

	void InsertQuarter()
	{
		using namespace std;
		switch (m_state)
		{
		case State::SoldOut:
			cout << "You can't insert a quarter, the machine is sold out\n";
			break;
		case State::NoQuarter:
			cout << "You inserted a quarter\n";
			m_state = State::HasQuarter;
			++m_quarterCount;
			break;
		case State::HasQuarter:
			if (m_quarterCount == MAX_QUARTER)
			{
				cout << "You can't insert another quarter\n";
			}
			else
			{
				cout << "You inserted another quarter\n";
				++m_quarterCount;
			}
			break;
		case State::Sold:
			cout << "Please wait, we're already giving you a gumball\n";
			break;
		}
	}

	void EjectQuarter()
	{
		using namespace std;
		switch (m_state)
		{
		case State::HasQuarter:
			cout << "Quarter returned\n";
			m_state = State::NoQuarter;
			m_quarterCount = 0;
			break;
		case State::NoQuarter:
			cout << "You haven't inserted a quarter\n";
			break;
		case State::Sold:
			cout << "Sorry you already turned the crank\n";
			break;
		case State::SoldOut:
			if (m_quarterCount == 0)
			{
				cout << "You can't eject, you haven't inserted a quarter yet\n";
			}
			else
			{
				cout << "Quarter returned\n";
				m_quarterCount = 0;
			}
			break;
		}
	}

	void TurnCrank()
	{
		using namespace std;
		switch (m_state)
		{
		case State::SoldOut:
			cout << "You turned but there's no gumballs\n";
			break;
		case State::NoQuarter:
			cout << "You turned but there's no quarter\n";
			break;
		case State::HasQuarter:
			cout << "You turned...\n";
			m_state = State::Sold;
			Dispense();
			break;
		case State::Sold:
			cout << "Turning twice doesn't get you another gumball\n";
			break;
		}
	}

	void Refill(unsigned numBalls)
	{
		m_count = numBalls;
		m_state = numBalls > 0 ? State::NoQuarter : State::SoldOut;
	}

	[[nodiscard]] std::string ToString() const
	{
		std::string state = (m_state == State::SoldOut) ? "sold out" : (m_state == State::NoQuarter) ? "waiting for quarter"
			: (m_state == State::HasQuarter)														 ? "waiting for turn of crank"
																									 : "delivering a gumball";
		std::string str;
		str.append("Mighty Gumball, Inc.\n");
		str.append("C++-enabled Standing Gumball Model #2016 (with state)\n");
		str.append("Inventory: " + std::to_string(m_count) + " gumball" + (m_count != 1 ? "s" : "") + "\n");
		str.append("Number of quarter: " + std::to_string(m_quarterCount) + " quarter" + (m_quarterCount != 1 ? "s" : "") + "\n");
		str.append("Machine is " + state + "\n");
		return str;
	}

private:
	void Dispense()
	{
		using namespace std;
		switch (m_state)
		{
		case State::Sold:
			cout << "A gumball comes rolling out the slot\n";
			--m_count;
			--m_quarterCount;
			if (m_count == 0)
			{
				cout << "Oops, out of gumballs\n";
				m_state = State::SoldOut;
			}
			else
			{
				m_state = m_quarterCount > 0 ? State::HasQuarter : State::NoQuarter;
			}
			break;
		case State::NoQuarter:
			cout << "You need to pay first\n";
			break;
		case State::SoldOut:
		case State::HasQuarter:
			cout << "No gumball dispensed\n";
			break;
		}
	}

	unsigned m_count; // Количество шариков
	unsigned m_quarterCount;
	State m_state = State::SoldOut;
};
