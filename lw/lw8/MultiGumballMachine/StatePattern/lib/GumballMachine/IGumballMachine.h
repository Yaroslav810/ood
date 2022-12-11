#pragma once

constexpr unsigned MAX_QUARTER = 5;

struct IGumballMachine
{
	virtual void ReleaseBall() = 0;
	[[nodiscard]] virtual unsigned GetBallCount() const = 0;

	virtual void AddQuarter() = 0;
	virtual void PulloutQuarter() = 0;
	virtual void PulloutQuarterAll() = 0;
	[[nodiscard]] virtual unsigned GetQuarterCount() const = 0;

	virtual void SetSoldOutState() = 0;
	virtual void SetNoQuarterState() = 0;
	virtual void SetSoldState() = 0;
	virtual void SetHasQuarterState() = 0;

	virtual ~IGumballMachine() = default;
};
