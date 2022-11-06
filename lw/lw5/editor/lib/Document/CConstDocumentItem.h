#pragma once
#include "../Image/IImage.h"
#include "../Paragraph/IParagraph.h"
#include <memory>

class CConstDocumentItem
{
public:
	// Возвращает указатель на константное изображение, либо nullptr,
	// если элемент не является изображением
	[[nodiscard]] std::shared_ptr<const IImage> GetImage() const;

	// Возвращает указатель на константный параграф, либо nullptr, если элемент не является параграфом
	[[nodiscard]] std::shared_ptr<const IParagraph> GetParagraph() const;

	virtual ~CConstDocumentItem() = default;
};
