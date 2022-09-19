#include "CStatsData.h"

CStatsData::CStatsData(const std::string& stats)
	: m_statisticsTitle(stats)
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

	std::cout << "Max " << m_statisticsTitle << " " << m_max << std::endl;
	std::cout << "Min " << m_statisticsTitle << " " << m_min << std::endl;
	std::cout << "Average " << m_statisticsTitle << " " << (m_acc / m_countAcc) << std::endl;
	std::cout << "----------------" << std::endl;
}
