import {History} from "./History";
import {AbstractCommand} from "../command/Command";

const NOT_EXECUTE = 'not execute'
const EXECUTE = 'execute'
const UNEXECUTE = 'unexecute'

class TestData {
    public data = NOT_EXECUTE
}

class TestCommand extends AbstractCommand {
    private readonly testData: TestData

    constructor(testData: TestData) {
        super();
        this.testData = testData
    }

    doExecute() {
        this.testData.data = EXECUTE
    }

    doUnexecute() {
        this.testData.data = UNEXECUTE
    }
}

describe('Testing the shape', () => {
    it('Creating a History', () => {
        const history = new History()

        expect(history.canUndo()).toBe(false)
        expect(history.canRedo()).toBe(false)
    })

    it('With undo and redo, nothing happens in the empty history', () => {
        const history = new History()

        expect(() => history.undo()).not.toThrow()
        expect(history.canUndo()).toBe(false)
        expect(history.canRedo()).toBe(false)
        expect(() => history.redo).not.toThrow()
        expect(history.canUndo()).toBe(false)
        expect(history.canRedo()).toBe(false)
    })

    it('Event execution', () => {
        const history = new History()
        const testData = new TestData()
        const command = new TestCommand(testData)

        expect(() => history.addAndExecuteCommand(command)).not.toThrow()
        expect(history.canUndo()).toBe(true)
        expect(history.canRedo()).toBe(false)
        expect(testData.data).toBe(EXECUTE)
    })

    it('Canceling a command', () => {
        const history = new History()
        const testData = new TestData()
        const command = new TestCommand(testData)
        history.addAndExecuteCommand(command)

        expect(() => history.undo()).not.toThrow()
        expect(history.canUndo()).toBe(false)
        expect(history.canRedo()).toBe(true)
        expect(testData.data).toBe(UNEXECUTE)
    })

    it('Executing a canceled command', () => {
        const history = new History()
        const testData = new TestData()
        const command = new TestCommand(testData)
        history.addAndExecuteCommand(command)
        history.undo()

        expect(() => history.redo()).not.toThrow()
        expect(history.canUndo()).toBe(true)
        expect(history.canRedo()).toBe(false)
        expect(testData.data).toBe(EXECUTE)
    })

    it('Overwritten commands', () => {
        const history = new History()
        const testData1 = new TestData()
        const testData2 = new TestData()
        const testData3 = new TestData()
        const command1 = new TestCommand(testData1)
        const command2 = new TestCommand(testData2)
        const command3 = new TestCommand(testData3)

        history.addAndExecuteCommand(command1)
        history.addAndExecuteCommand(command2)
        history.undo()
        history.addAndExecuteCommand(command3)
        history.undo()
        history.undo()
        history.redo()
        history.redo()

        expect(testData1.data).toBe(EXECUTE)
        expect(testData2.data).toBe(UNEXECUTE)
        expect(testData3.data).toBe(EXECUTE)
    })
})
