#pragma once
#include "../Image/IImage.h"
#include "../Paragraph/IParagraph.h"
#include <memory>
#include <variant>

class CConstDocumentItem
{
public:
	explicit CConstDocumentItem(std::variant<std::shared_ptr<IImage>, std::shared_ptr<IParagraph>>&& item);

	// Возвращает указатель на константное изображение, либо nullptr,
	// если элемент не является изображением
	[[nodiscard]] std::shared_ptr<const IImage> GetImage() const;

	// Возвращает указатель на константный параграф, либо nullptr, если элемент не является параграфом
	[[nodiscard]] std::shared_ptr<const IParagraph> GetParagraph() const;

	virtual ~CConstDocumentItem() = default;

protected:
	std::variant<std::shared_ptr<IImage>, std::shared_ptr<IParagraph>> m_item;
};
