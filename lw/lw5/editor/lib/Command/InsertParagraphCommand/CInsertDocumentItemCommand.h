#pragma once
#include "../../Document/CDocumentItem.h"
#include "../CAbstractCommand.h"
#include <iostream>
#include <vector>

class CInsertDocumentItemCommand : public CAbstractCommand
{
public:
	CInsertDocumentItemCommand(std::vector<CDocumentItem>& items, CDocumentItem& item, size_t index);
	~CInsertDocumentItemCommand() override;

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::vector<CDocumentItem>& m_items;
	CDocumentItem& m_item;
	size_t m_index;
};
