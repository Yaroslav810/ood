#include "CDocument.h"

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
	if (position > GetItemsCount())
	{
		throw std::invalid_argument("Invalid pos");
	}

	auto image = std::make_shared<CImage>(path, width, height, m_history);
	auto item = CDocumentItem(image);
	m_history.AddAndExecuteCommand(
		std::make_unique<CInsertDocumentItemCommand>(m_items, item, position.has_value() ? position.value() : GetItemsCount()));
	return image;
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

void CDocument::ResizeImage(int width, int height, size_t position)
{
	if (position >= GetItemsCount())
	{
		throw std::invalid_argument("Invalid pos");
	}

	auto item = GetItem(position);
	if (!item.GetImage())
	{
		throw std::invalid_argument("Invalid item type");
	}

	item.GetImage()->Resize(width, height);
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
	std::string parentPath = std::filesystem::path(path).parent_path().string();
	std::string rootDir = parentPath + (parentPath.empty() ? "" : "/");
	std::string imagesDir = rootDir + "images";
	std::cout << imagesDir << std::endl;
	if (!std::filesystem::is_directory(imagesDir))
	{
		if (!rootDir.empty())
		{
			std::filesystem::create_directory(rootDir);
		}
		std::filesystem::create_directory(imagesDir);
	}

	std::ofstream html(path);
	html << "<html>"
		 << "<head>"
		 << "<title>" << ReplaceCharacters(this->GetTitle()) << "</title>"
		 << "</head>"
		 << "<body>";

	for (auto i = 0; i < this->GetItemsCount(); i++)
	{
		if (this->GetItem(i).GetParagraph())
		{
			auto paragraph = this->GetItem(i).GetParagraph();
			html << "<p>" << ReplaceCharacters(paragraph->GetText()) << "</p>";
		}
		else
		{
			auto image = this->GetItem(i).GetImage();
			auto filename = std::filesystem::path(image->GetPath()).filename().string();
			auto src = "images/" + filename;
			auto dir = imagesDir += "/" + filename;
			int width = image->GetWidth();
			int height = image->GetHeight();
			html << "<img src='" + src + "' width=" + std::to_string(width) + " height=" + std::to_string(height) + " />";
			std::filesystem::copy_file(image->GetPath(), dir);
		}
	}

	html << "</body>"
		 << "</html>" << std::endl;
}

std::string CDocument::ReplaceCharacters(const std::string& str)
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
