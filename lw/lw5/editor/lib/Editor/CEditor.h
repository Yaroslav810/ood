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
	void InsertParagraph(std::istream& in);

	void InsertImage(std::istream& in);

	void SetTitle(std::istream& is);

	void List(std::istream&);

	void ReplaceText(std::istream& in);

	void DeleteItem(std::istream& in);

	void Undo(std::istream&);

	void Redo(std::istream&);

	CMenu m_menu;
	std::unique_ptr<IDocument> m_document;
};
