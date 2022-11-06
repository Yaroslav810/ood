#include "CDocument.h"
#include "../Command/ChangeStringCommand/CChangeStringCommand.h"

std::shared_ptr<IParagraph> CDocument::InsertParagraph(const std::string& text, std::optional<size_t> position)
{
	return std::shared_ptr<IParagraph>();
}

std::shared_ptr<IImage> CDocument::InsertImage(const std::string& path, int width, int height, std::optional<size_t> position)
{
	return std::shared_ptr<IImage>();
}

size_t CDocument::GetItemsCount() const
{
	return 0;
}

CConstDocumentItem CDocument::GetItem(size_t index) const
{
	return CConstDocumentItem();
}

CDocumentItem CDocument::GetItem(size_t index)
{
	return CDocumentItem();
}

void CDocument::DeleteItem(size_t index)
{
}

void CDocument::SetTitle(const std::string& title)
{
	m_history.AddAndExecuteCommand(std::make_unique<CChangeStringCommand>(m_title, title));
}

std::string CDocument::GetTitle() const
{
	return m_title;
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
