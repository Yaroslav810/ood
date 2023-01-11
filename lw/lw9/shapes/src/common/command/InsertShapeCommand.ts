import {AbstractCommand} from "./Command";
import {IShape} from "../../model/domain/Shape";
import {ICanvas} from "../../model/domain/Canvas";

class InsertShapeCommand extends AbstractCommand {
    private shape: IShape
    private index: number
    private canvas: ICanvas

    constructor(shape: IShape, index: number, canvas: ICanvas) {
        super();
        this.shape = shape
        this.index = index
        this.canvas = canvas
    }

    doExecute() {
        this.canvas.addShape(this.shape, this.index)
    }

    doUnexecute() {
        this.canvas.deleteShape(this.index)
    }
}

export {
    InsertShapeCommand,
}