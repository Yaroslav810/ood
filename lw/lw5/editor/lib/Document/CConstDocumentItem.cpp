#include "CConstDocumentItem.h"

CConstDocumentItem::CConstDocumentItem(std::variant<std::shared_ptr<IImage>, std::shared_ptr<IParagraph>>&& item)
	: m_item(item)
{
}

std::shared_ptr<const IImage> CConstDocumentItem::GetImage() const
{
	return std::holds_alternative<std::shared_ptr<IImage>>(m_item)
		? std::get<std::shared_ptr<IImage>>(m_item)
		: nullptr;
}

std::shared_ptr<const IParagraph> CConstDocumentItem::GetParagraph() const
{
	return std::holds_alternative<std::shared_ptr<IParagraph>>(m_item)
		? std::get<std::shared_ptr<IParagraph>>(m_item)
		: nullptr;
}
