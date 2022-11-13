#include "CEditor.h"
#include <fstream>

CEditor::CEditor()
	: m_document(std::make_unique<CDocument>())
{
	m_menu.AddItem("InsertParagraph", "Inserts a paragraph. Args: <pos>|end <text>", [this](std::istream& is) { InsertParagraph(is); });
	m_menu.AddItem("InsertImage", "Inserts an image. Args: <pos>|end <width> <height> <path>", [this](std::istream& is) { InsertImage(is); });
	m_menu.AddItem("SetTitle", "Changes title. Args: <new title>", [this](std::istream& is) { SetTitle(is); });
	m_menu.AddItem("List", "Show document", [this](std::istream& is) { List(is); });
	m_menu.AddItem("ReplaceText", "Replace a text. Args: <pos> <text>", [this](std::istream& is) { ReplaceText(is); });
	m_menu.AddItem("DeleteItem", "Delete a item. Args: <pos>", [this](std::istream& is) { DeleteItem(is); });
	m_menu.AddItem("Undo", "Undo command", [this](std::istream& is) { Undo(is); });
	m_menu.AddItem("Redo", "Redo undone command", [this](std::istream& is) { Redo(is); });
	m_menu.AddItem("Save", "Save a document. Args: <path>", [this](std::istream& is) { Save(is); });
	m_menu.AddItem("Help", "Help", [this](std::istream&) { m_menu.ShowInstructions(); });
	m_menu.AddItem("Exit", "Exit", [this](std::istream&) { m_menu.Exit(); });
}

void CEditor::Start()
{
	m_menu.Run();
}

void CEditor::InsertParagraph(std::istream& is)
{
	std::string pos;
	std::string text;

	try
	{
		if (is >> pos && is >> text)
		{
			m_document->InsertParagraph(text, pos == "end" ? std::optional<size_t>() : std::stoi(pos));
		}
		else
		{
			std::cout << "Incorrect args" << std::endl;
		}
	}
	catch (std::exception&)
	{
		std::cout << "Invalid pos" << std::endl;
	}
}

void CEditor::InsertImage(std::istream& is)
{
	std::string pos;
	int width;
	int height;
	std::string path;

	try
	{
		if (is >> pos && is >> width && is >> height && is >> path)
		{
			m_document->InsertImage(path, width, height, pos == "end" ? std::optional<size_t>() : std::stoi(pos));
		} else {
			std::cout << "Invalid args" << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void CEditor::SetTitle(std::istream& is)
{
	std::string head;
	std::string tail;

	if (is >> head)
	{
		getline(is, tail);
	}

	auto title = head + tail;
	m_document->SetTitle(title);
}

void CEditor::List(std::istream&)
{
	std::cout << "-------------" << std::endl;
	std::cout << "Title: " << m_document->GetTitle() << std::endl;
	for (size_t i = 0; i < m_document->GetItemsCount(); ++i)
	{
		std::cout << i << ". ";
		if (m_document->GetItem(i).GetParagraph())
		{
			std::shared_ptr<IParagraph> paragraph = m_document->GetItem(i).GetParagraph();
			std::cout << "Paragraph: " << paragraph->GetText() << std::endl;
		}
		else
		{
			std::shared_ptr<IImage> image = m_document->GetItem(i).GetImage();
			std::cout << "Image: " << image->GetWidth() << " " << image->GetHeight() << " " << image->GetPath() << std::endl;
		}
	}
	std::cout << "-------------" << std::endl;
}

void CEditor::ReplaceText(std::istream& is)
{
	std::string pos;
	std::string text;

	try
	{
		if (is >> pos && is >> text)
		{
			m_document->ReplaceText(text, std::stoi(pos));
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void CEditor::DeleteItem(std::istream& is)
{
	std::string pos;

	try
	{
		if (is >> pos)
		{
			m_document->DeleteItem(std::stoi(pos));
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void CEditor::Undo(std::istream&)
{
	if (m_document->CanUndo())
	{
		m_document->Undo();
	}
	else
	{
		std::cout << "Can't undo" << std::endl;
	}
}

void CEditor::Redo(std::istream&)
{
	if (m_document->CanRedo())
	{
		m_document->Redo();
	}
	else
	{
		std::cout << "Can't redo" << std::endl;
	}
}

void CEditor::Save(std::istream& is)
{
	std::string path;

	try
	{
		if (getline(is, path))
		{
			SaveImpl(path);
			m_menu.Exit();
		}
		else
		{
			std::cout << "File not saved!";
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void CEditor::SaveImpl(const std::string& path)
{
	std::ofstream html(path);
	html << "<html>"
		 << "<head>"
		 << "<title>" << ReplaceCharacters(m_document->GetTitle()) << "</title>"
		 << "</head>"
		 << "<body>";

	for (auto i = 0; i < m_document->GetItemsCount(); i++)
	{
		if (m_document->GetItem(i).GetParagraph())
		{
			auto paragraph = m_document->GetItem(i).GetParagraph();
			html << "<p>" << ReplaceCharacters(paragraph->GetText()) << "</p>";
		}
	}

	html << "</body>"
		 << "</html>" << std::endl;
}

std::string CEditor::ReplaceCharacters(const std::string& str)
{
	std::string result;
	for (const auto ch : str)
	{
		switch (ch)
		{
		case '<':
			result.append("&lt;");
			break;
		case '>':
			result.append("&gt;");
			break;
		case '"':
			result.append("&quot;");
			break;
		case '\'':
			result.append("&apos;");
			break;
		case '&':
			result.append("&amp;");
			break;
		default:
			result += ch;
		}
	}
	return result;
}
