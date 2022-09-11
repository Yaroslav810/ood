#include "CDuck.h"

CDuck::CDuck(
	std::unique_ptr<IFlyBehavior>&& flyBehavior,
	std::unique_ptr<IQuackBehavior>&& quackBehavior)
	: m_flyBehavior(move(flyBehavior))
	, m_quackBehavior(move(quackBehavior))
{
	assert(m_flyBehavior);
	assert(m_quackBehavior);
}

void CDuck::Quack() const
{
	m_quackBehavior->Quack();
}

void CDuck::Swim()
{
	std::cout << "I'm swimming" << std::endl;
}

void CDuck::Fly()
{
	m_flyBehavior->Fly();
}

void CDuck::Dance()
{
	std::cout << "I'm Dancing" << std::endl;
}

void CDuck::SetFlyBehavior(std::unique_ptr<IFlyBehavior>&& flyBehavior)
{
	assert(flyBehavior);
	m_flyBehavior = move(flyBehavior);
}
