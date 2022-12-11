#pragma once
#include "../../GumballMachine/IGumballMachine.h"
#include "../IState.h"
#include <iostream>

class CSoldOutState : public IState
{
public:
	explicit CSoldOutState(IGumballMachine& gumballMachine);
	void InsertQuarter() override;
	void EjectQuarter() override;
	void TurnCrank() override;
	void Dispense() override;
	void AddBalls(unsigned numBalls) override;
	[[nodiscard]] std::string ToString() const override;

private:
	IGumballMachine& m_gumballMachine;
};
