import {AbstractCommand} from "./Command";
import {Shape} from "../../model/domain/Shape";
import {Rect} from "../rect/rect";
import {Canvas} from "../../model/domain/Canvas";

class ChangeFrameCommand extends AbstractCommand {
    private readonly shape: Shape
    private readonly oldFrame: Rect
    private readonly newFrame: Rect
    private canvas: Canvas

    constructor(shape: Shape, newFrame: Rect, canvas: Canvas) {
        super();
        this.shape = shape
        this.oldFrame = shape.getFrame()
        this.newFrame = newFrame
        this.canvas = canvas
    }

    doExecute() {
        this.shape.setFrame(this.newFrame)
        this.canvas.replaceShape(this.shape)
    }

    doUnexecute() {
        this.shape.setFrame(this.oldFrame)
        this.canvas.replaceShape(this.shape)
    }
}

export {
    ChangeFrameCommand,
}