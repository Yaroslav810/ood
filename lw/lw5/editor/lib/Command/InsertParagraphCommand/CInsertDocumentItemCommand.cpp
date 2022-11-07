#include "CInsertDocumentItemCommand.h"
#include <utility>

CInsertDocumentItemCommand::CInsertDocumentItemCommand(std::vector<CDocumentItem>& items, CDocumentItem& item, size_t index)
	: m_items(items)
	, m_item(item)
	, m_index(index)
{
}

void CInsertDocumentItemCommand::DoExecute()
{
	m_items.emplace(m_items.begin() + m_index, m_item);
}

void CInsertDocumentItemCommand::DoUnexecute()
{
	m_items.erase(m_items.begin() + m_index);
}

CInsertDocumentItemCommand::~CInsertDocumentItemCommand()
{
}
