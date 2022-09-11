#include "CFlyWithWings.h"

CFlyWithWings::CFlyWithWings()
	: m_numberOfFly(0)
{
}

void CFlyWithWings::Fly()
{
	m_numberOfFly++;
	std::cout << "I'm flying with wings!!" << std::endl;
}

void CFlyWithWings::ShowNumberOfFly()
{
	std::cout << "I've been out " << m_numberOfFly << " times" << std::endl;
}
