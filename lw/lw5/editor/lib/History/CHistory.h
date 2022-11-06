#pragma once
#include "../Command/ICommand_fwd.h"
#include <deque>

class CHistory
{
public:
	CHistory() = default;
	~CHistory() = default;

	[[nodiscard]] bool CanUndo() const;
	[[nodiscard]] bool CanRedo() const;

	void Undo();
	void Redo();
	void AddAndExecuteCommand(ICommandPtr&& command);

private:
	const size_t MAX_HISTORY_COUNT = 10;

	std::deque<ICommandPtr> m_commands;
	size_t m_nextCommandIndex = 0;
};
