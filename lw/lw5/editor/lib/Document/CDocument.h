#pragma once
#include "../History/CHistory.h"
#include "IDocument.h"
#include <iostream>
#include <vector>

class CDocument : public IDocument
{
public:
	CDocument() = default;

	std::shared_ptr<IParagraph> InsertParagraph(const std::string& text, std::optional<size_t> position) override;
	std::shared_ptr<IImage> InsertImage(const std::string& path, int width, int height, std::optional<size_t> position) override;
	[[nodiscard]] size_t GetItemsCount() const override;
	[[nodiscard]] CConstDocumentItem GetItem(size_t position) const override;
	CDocumentItem GetItem(size_t position) override;
	void DeleteItem(size_t position) override;
	void SetTitle(const std::string& title) override;
	[[nodiscard]] std::string GetTitle() const override;
	void ReplaceText(const std::string& text, size_t position) override;
	[[nodiscard]] bool CanUndo() const override;
	void Undo() override;
	[[nodiscard]] bool CanRedo() const override;
	void Redo() override;
	void Save(const std::string& path) const override;

private:
	std::string m_title;
	std::vector<CDocumentItem> m_items;
	CHistory m_history;
};