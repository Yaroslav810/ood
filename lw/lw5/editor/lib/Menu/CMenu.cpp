#include "CMenu.h"
#include <sstream>

CMenu::CMenu() = default;

void CMenu::AddItem(const std::string& shortcut, const std::string& description, const Command& command)
{
	m_items.emplace_back(shortcut, description, command);
}

void CMenu::Run()
{
	ShowInstructions();

	std::string command;
	while ((std::cout << "> ")
		&& getline(std::cin, command)
		&& ExecuteCommand(command))
	{
	}
}

void CMenu::ShowInstructions() const
{
	std::cout << "Commands list:\n";
	for (auto& item : m_items)
	{
		std::cout << "  " << item.shortcut << ": " << item.description << std::endl;
	}
}

void CMenu::Exit()
{
	m_exit = true;
}

bool CMenu::ExecuteCommand(const std::string& command)
{
	std::istringstream iss(command);
	std::string name;
	iss >> name;

	auto it = std::find_if(m_items.begin(), m_items.end(), [&](const Item& item) {
		return item.shortcut == name;
	});

	if (it != m_items.end())
	{
		it->command(iss);
	}
	else
	{
		std::cout << "Unknown command\n";
	}

	return !m_exit;
}
