#include "CDuck.h"

CDuck::CDuck(
	std::unique_ptr<IFlyBehavior>&& flyBehavior,
	std::unique_ptr<IQuackBehavior>&& quackBehavior,
	std::unique_ptr<IDanceBehavior>&& danceBehavior)
	: m_flyBehavior(move(flyBehavior))
	, m_quackBehavior(move(quackBehavior))
	, m_danceBehavior(move(danceBehavior))
{
	assert(m_flyBehavior);
	assert(m_quackBehavior);
	assert(m_danceBehavior);
}

void CDuck::Quack() const
{
	m_quackBehavior->Quack();
}

void CDuck::Fly() const
{
	m_flyBehavior->Fly();
}

void CDuck::Dance() const
{
	m_danceBehavior->Dance();
}

void CDuck::Swim()
{
	std::cout << "I'm swimming" << std::endl;
}

void CDuck::SetFlyBehavior(std::unique_ptr<IFlyBehavior>&& flyBehavior)
{
	assert(flyBehavior);
	m_flyBehavior = move(flyBehavior);
}

void CDuck::ShowNumberOfFly() const
{
	m_flyBehavior->ShowNumberOfFly();
}
