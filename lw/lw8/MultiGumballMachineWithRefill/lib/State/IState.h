#pragma once
#include <string>

struct IState
{
	virtual void InsertQuarter() = 0;
	virtual void EjectQuarter() = 0;
	virtual void TurnCrank() = 0;
	virtual void Dispense() = 0;
	virtual void AddBalls(unsigned numBalls) = 0;
	[[nodiscard]] virtual std::string ToString() const = 0;
	virtual ~IState() = default;
};
