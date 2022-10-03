#pragma once
#include "../../SWindInfo.h"
#include "../CStatsData/CStatsData.h"
#include <cmath>
#include <iostream>

class CStatsWindDirectionData
{
public:
	void Update(double data);
	[[nodiscard]] double getAverageData() const;

private:
	static double DegreesToRadians(double degrees);
	static double RadiansToDegrees(double radians);

	double m_sinSum = 0;
	double m_cosSum = 0;
	double m_average = 0;
};

class CStatsWindData
{
public:
	CStatsWindData();
	void Update(SWindInfo data);
	[[nodiscard]] CStatsData getSpeedWind() const;
	[[nodiscard]] CStatsWindDirectionData getDirectionWind() const;

private:
	CStatsData m_speed;
	CStatsWindDirectionData m_direction;
};
