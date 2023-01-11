import {AbstractCommand} from "./Command";
import {Shape} from "../../model/domain/Shape";
import {Canvas} from "../../model/domain/Canvas";

class DeleteShapeCommand extends AbstractCommand {
  private shape: Shape
  private index: number
  private canvas: Canvas

  constructor(shape: Shape, index: number, canvas: Canvas) {
    super();
    this.shape = shape
    this.index = index
    this.canvas = canvas
  }

  doExecute() {
    this.canvas.deleteShape(this.shape.getUuid())
  }

  doUnexecute() {
    this.canvas.insertShape(this.shape, this.index)
  }
}

export {
  DeleteShapeCommand,
}
