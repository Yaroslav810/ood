#pragma once
#include "../../State/CHasQuarterState/CHasQuarterState.h"
#include "../../State/CNoQuarterState/CNoQuarterState.h"
#include "../../State/CSoldOutState/CSoldOutState.h"
#include "../../State/CSoldState/CSoldState.h"
#include "../../State/IState.h"
#include "../IGumballMachine.h"

class CGumballMachine : private IGumballMachine
{
public:
	explicit CGumballMachine(unsigned numBalls);
	void EjectQuarter();
	void InsertQuarter();
	void TurnCrank();
	[[nodiscard]] std::string ToString() const;

private:
	[[nodiscard]] unsigned GetBallCount() const override;
	void ReleaseBall() override;
	void AddQuarter() override;
	void PulloutQuarter() override;
	void PulloutQuarterAll() override;
	[[nodiscard]] unsigned GetQuarterCount() const override;
	void SetSoldOutState() override;
	void SetNoQuarterState() override;
	void SetSoldState() override;
	void SetHasQuarterState() override;

private:
	unsigned m_count = 0;
	unsigned m_quarterCount = 0;
	CSoldState m_soldState;
	CSoldOutState m_soldOutState;
	CNoQuarterState m_noQuarterState;
	CHasQuarterState m_hasQuarterState;
	IState* m_state;
};
