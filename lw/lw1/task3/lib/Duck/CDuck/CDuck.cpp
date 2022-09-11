#include "CDuck.h"

#include <utility>

CDuck::CDuck(
	CDuck::Strategy flyBehavior,
	CDuck::Strategy quackBehavior,
	CDuck::Strategy danceBehavior)
	: m_flyBehavior(std::move(flyBehavior))
	, m_quackBehavior(std::move(quackBehavior))
	, m_danceBehavior(std::move(danceBehavior))
{
	assert(m_flyBehavior);
	assert(m_quackBehavior);
	assert(m_danceBehavior);
}

void CDuck::Quack() const
{
	m_quackBehavior();
}

void CDuck::Fly() const
{
	m_flyBehavior();
}

void CDuck::Dance() const
{
	m_danceBehavior();
}

void CDuck::Swim()
{
	std::cout << "I'm swimming" << std::endl;
}

void CDuck::SetFlyBehavior(CDuck::Strategy&& flyBehavior)
{
	assert(flyBehavior);
	m_flyBehavior = std::move(flyBehavior);
}
