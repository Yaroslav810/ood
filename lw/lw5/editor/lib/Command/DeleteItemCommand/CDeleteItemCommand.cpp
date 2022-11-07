#include "CDeleteItemCommand.h"
#include <utility>

CDeleteItemCommand::CDeleteItemCommand(std::vector<CDocumentItem>& items, size_t index)
	: m_items(items)
	, m_index(index)
{
	m_item = std::make_shared<CDocumentItem>(m_items.at(index));
}

void CDeleteItemCommand::DoExecute()
{
	m_items.erase(m_items.begin() + m_index);
}

void CDeleteItemCommand::DoUnexecute()
{
	m_items.emplace(m_items.begin() + m_index, *m_item);
}
