#pragma once
#include <iostream>

class CStatsData
{
public:
	CStatsData(const std::string& stats);
	void Update(double data);

private:
	std::string m_statisticsTitle;
	double m_min = std::numeric_limits<double>::infinity();
	double m_max = -std::numeric_limits<double>::infinity();
	double m_acc = 0;
	unsigned m_countAcc = 0;
};
