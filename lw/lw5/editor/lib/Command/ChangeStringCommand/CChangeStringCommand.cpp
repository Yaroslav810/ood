#include "CChangeStringCommand.h"
#include <utility>

CChangeStringCommand::CChangeStringCommand(std::string& target, std::string newValue)
	: m_target(target)
	, m_newValue(std::move(newValue))
{
}

void CChangeStringCommand::DoExecute()
{
	m_newValue.swap(m_target);
}

void CChangeStringCommand::DoUnexecute()
{
	m_newValue.swap(m_target);
}
