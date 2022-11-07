#pragma once
#include "../Document/CDocument.h"
#include "../Menu/CMenu.h"
#include <iostream>
#include <memory>
#include <string>

class CEditor
{
public:
	CEditor();
	void Start();

private:
	void InsertParagraph(std::istream& is);

	void InsertImage(std::istream& is);

	void SetTitle(std::istream& is);

	void List(std::istream&);

	void ReplaceText(std::istream& is);

	void DeleteItem(std::istream& is);

	void Undo(std::istream&);

	void Redo(std::istream&);

	void Save(std::istream& is);

	void SaveImpl(const std::string& path);

	static std::string ReplaceCharacters(const std::string& str);

	CMenu m_menu;
	std::unique_ptr<IDocument> m_document;
};
