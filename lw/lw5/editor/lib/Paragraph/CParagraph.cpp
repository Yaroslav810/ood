#include "CParagraph.h"
#include "../Command/ReplaceTextCommand/CReplaceTextCommand.h"
#include <utility>

CParagraph::CParagraph(std::string text, CHistory& history)
	: m_text(std::move(text))
	, m_history(history)
{
}

std::string CParagraph::GetText() const
{
	return m_text;
}

void CParagraph::SetText(const std::string& text)
{
	m_history.AddAndExecuteCommand(std::make_unique<CReplaceTextCommand>(m_text, text));
}
