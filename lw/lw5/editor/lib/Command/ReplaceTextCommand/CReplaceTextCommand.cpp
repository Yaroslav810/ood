#include "CReplaceTextCommand.h"

CReplaceTextCommand::CReplaceTextCommand(std::string& target, std::string newValue)
	: m_target(target)
	, m_newValue(std::move(newValue))
{
}

void CReplaceTextCommand::DoExecute()
{
	m_newValue.swap(m_target);
}

void CReplaceTextCommand::DoUnexecute()
{
	m_newValue.swap(m_target);
}
