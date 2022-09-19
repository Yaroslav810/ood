#pragma once
#include <iostream>

class CStatsData
{
public:
	CStatsData(std::string stats);
	void Update(double data);
	[[nodiscard]] std::string getStatisticsName() const;
	[[nodiscard]] double getMaxData() const;
	[[nodiscard]] double getMinData() const;
	[[nodiscard]] double getAverageData() const;

private:
	std::string m_statisticsName;
	double m_min = std::numeric_limits<double>::infinity();
	double m_max = -std::numeric_limits<double>::infinity();
	double m_acc = 0;
	unsigned m_countAcc = 0;
};
