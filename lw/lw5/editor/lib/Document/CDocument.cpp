#include "CDocument.h"
#include "../Command/ChangeStringCommand/CChangeStringCommand.h"
#include "../Command/DeleteItemCommand/CDeleteItemCommand.h"
#include "../Command/InsertParagraphCommand/CInsertDocumentItemCommand.h"
#include "../Paragraph/CParagraph.h"

std::shared_ptr<IParagraph> CDocument::InsertParagraph(const std::string& text, std::optional<size_t> position)
{
	if (position > GetItemsCount())
	{
		throw std::invalid_argument("Invalid pos");
	}

	auto paragraph = std::make_shared<CParagraph>(text, m_history);
	auto item = CDocumentItem(paragraph);
	m_history.AddAndExecuteCommand(
		std::make_unique<CInsertDocumentItemCommand>(m_items, item, position.has_value() ? position.value() : GetItemsCount()));
	return paragraph;
}

std::shared_ptr<IImage> CDocument::InsertImage(const std::string& path, int width, int height, std::optional<size_t> position)
{
	return std::shared_ptr<IImage>();
}

size_t CDocument::GetItemsCount() const
{
	return m_items.size();
}

CConstDocumentItem CDocument::GetItem(size_t position) const
{
	return m_items.at(position);
}

CDocumentItem CDocument::GetItem(size_t position)
{
	return m_items.at(position);
}

void CDocument::DeleteItem(size_t position)
{
	if (position >= GetItemsCount())
	{
		throw std::invalid_argument("Invalid pos");
	}
	m_history.AddAndExecuteCommand(std::make_unique<CDeleteItemCommand>(m_items, position));
}

void CDocument::SetTitle(const std::string& title)
{
	m_history.AddAndExecuteCommand(std::make_unique<CChangeStringCommand>(m_title, title));
}

std::string CDocument::GetTitle() const
{
	return m_title;
}

void CDocument::ReplaceText(const std::string& text, size_t position)
{
	if (position >= GetItemsCount())
	{
		throw std::invalid_argument("Invalid pos");
	}

	auto item = GetItem(position);
	if (!item.GetParagraph())
	{
		throw std::invalid_argument("Invalid item type");
	}

	item.GetParagraph()->SetText(text);
}
bool CDocument::CanUndo() const
{
	return m_history.CanUndo();
}

void CDocument::Undo()
{
	m_history.Undo();
}

bool CDocument::CanRedo() const
{
	return m_history.CanRedo();
}

void CDocument::Redo()
{
	m_history.Redo();
}

void CDocument::Save(const std::string& path) const
{
}
