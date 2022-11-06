#pragma once
#include "../Image/IImage.h"
#include "../Paragraph/IParagraph.h"
#include "CConstDocumentItem.h"
#include <memory>

class CDocumentItem : public CConstDocumentItem
{
public:
	// Возвращает указатель на изображение, либо nullptr, если элемент не является изображением
	std::shared_ptr<IImage> GetImage();

	// Возвращает указатель на параграф, либо nullptr, если элемент не является параграфом
	std::shared_ptr<IParagraph> GetParagraph();
};
