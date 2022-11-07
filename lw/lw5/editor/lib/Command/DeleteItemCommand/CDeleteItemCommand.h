#pragma once
#include "../../Document/CDocumentItem.h"
#include "../CAbstractCommand.h"
#include <vector>

class CDeleteItemCommand : public CAbstractCommand
{
public:
	CDeleteItemCommand(std::vector<CDocumentItem>& items, size_t index);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::vector<CDocumentItem>& m_items;
	std::shared_ptr<CDocumentItem> m_item;
	size_t m_index;
};
