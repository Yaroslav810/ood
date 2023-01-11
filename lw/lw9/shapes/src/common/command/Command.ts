interface ICommand {
    execute(): void
    unexecute(): void
}

abstract class AbstractCommand implements ICommand {
    private executed: boolean = false

    execute() {
        if (!this.executed) {
            this.doExecute()
            this.executed = true
        }
    }

    unexecute() {
        if (this.executed) {
            this.doUnexecute()
            this.executed = false
        }
    }

    abstract doExecute(): void
    abstract doUnexecute(): void
}

export {
    type ICommand,
}
