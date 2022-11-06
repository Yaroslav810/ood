#pragma once
#include <functional>
#include <iostream>
#include <utility>

class CMenu
{
public:
	using Command = std::function<void(std::istream& args)>;

	CMenu();
	void AddItem(const std::string& shortcut, const std::string& description, const Command& command);
	void Run();
	void ShowInstructions() const;
	void Exit();

private:
	bool ExecuteCommand(const std::string& command);

	struct Item
	{
		Item(std::string shortcut, std::string description, Command command)
			: shortcut(std::move(shortcut))
			, description(std::move(description))
			, command(std::move(command))
		{
		}

		std::string shortcut;
		std::string description;
		Command command;
	};

	std::vector<Item> m_items;
	bool m_exit = false;
};
