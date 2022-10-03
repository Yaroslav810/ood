#include "CStatsWindData.h"

void CStatsWindDirectionData::Update(double data)
{
	m_sinSum += sin(DegreesToRadians(data));
	m_cosSum += cos(DegreesToRadians(data));
	auto d = RadiansToDegrees(atan2(m_sinSum, m_cosSum)) + 360;
	m_average = std::fmod(d, 360);
}

double CStatsWindDirectionData::getAverageData() const
{
	return m_average;
}

double CStatsWindDirectionData::DegreesToRadians(double degrees)
{
	return degrees * (M_PI / 180);
}

double CStatsWindDirectionData::RadiansToDegrees(double radians)
{
	return radians * (180 / M_PI);
}

CStatsWindData::CStatsWindData()
	: m_speed("Wind speed")
	, m_direction()
{
}

void CStatsWindData::Update(SWindInfo data)
{
	m_speed.Update(data.speed);
	m_direction.Update(data.direction);
}

CStatsData CStatsWindData::getSpeedWind() const
{
	return m_speed;
}

CStatsWindDirectionData CStatsWindData::getDirectionWind() const
{
	return m_direction;
}
