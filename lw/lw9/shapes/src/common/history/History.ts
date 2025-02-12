import {ICommand} from "../command/Command";

interface IHistory {
    undo(): void
    redo(): void
    canUndo(): boolean
    canRedo(): boolean
    addAndExecuteCommand(command: ICommand): void
}

class History implements IHistory {
    private commands: ICommand[] = []
    private index: number = 0

    undo() {
        if (this.canUndo()) {
            this.commands[this.index - 1].unexecute()
            --this.index
        }
    }

    redo() {
        if (this.canRedo()) {
            this.commands[this.index].execute()
            ++this.index
        }
    }

    canUndo() {
        return this.index !== 0
    }

    canRedo() {
        return this.index !== this.commands.length
    }

    addAndExecuteCommand(command: ICommand) {
        if (this.index < this.commands.length) {
            this.commands = this.commands.slice(0, this.index)
        }

        command.execute()
        ++this.index
        this.commands.push(command)
    }
}

export {
    type IHistory,
    History,
}
