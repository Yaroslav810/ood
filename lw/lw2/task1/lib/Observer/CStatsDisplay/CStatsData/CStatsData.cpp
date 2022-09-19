#include "CStatsData.h"

CStatsData::CStatsData(std::string stats)
	: m_statisticsName(std::move(stats))
{
}

void CStatsData::Update(double data)
{
	if (m_min > data)
	{
		m_min = data;
	}
	if (m_max < data)
	{
		m_max = data;
	}
	m_acc += data;
	++m_countAcc;
}

std::string CStatsData::getStatisticsName() const
{
	return m_statisticsName;
}

double CStatsData::getMaxData() const
{
	return m_max;
}

double CStatsData::getMinData() const
{
	return m_min;
}

double CStatsData::getAverageData() const
{
	return m_acc / m_countAcc;
}
