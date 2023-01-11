import {Canvas} from "../domain/Canvas";
import {Shape} from "../domain/Shape";
import {ShapeType} from "../domain/ShapeType";
import {UUID} from "../../common/uuid/uuid";
import {Rect} from "../../common/rect/rect";
import {IHistory} from "../../common/history/History";
import {InsertShapeCommand} from "../../common/command/InsertShapeCommand";
import {ChangeFrameCommand} from "../../common/command/ChangeFrameCommand";
import {DeleteShapeCommand} from "../../common/command/DeleteShapeCommand";

class Controller {
  private readonly canvas: Canvas
  private readonly history: IHistory

  constructor(canvas: Canvas, history: IHistory) {
    this.canvas = canvas
    this.history = history
  }

  addShape(type: ShapeType): void {
    const shape = new Shape(type)
    const index = this.canvas.getShapesCount()
    this.history.addAndExecuteCommand(new InsertShapeCommand(shape, index, this.canvas))
  }

  deleteShape(uuid: UUID): void {
    const shape = this.canvas.getShapes().find(shape => shape.getUuid() === uuid)
    if (shape) {
      const index = this.canvas.getShapes().findIndex(shape => shape.getUuid() === uuid)
      this.history.addAndExecuteCommand(new DeleteShapeCommand(shape, index, this.canvas))
    }
  }

  changeFrameShape(uuid: UUID, frame: Rect): void {
    const shape = this.canvas.getShapes().find(shape => shape.getUuid() === uuid)
    if (shape) {
      this.history.addAndExecuteCommand(new ChangeFrameCommand(shape, frame, this.canvas))
    }
  }

  undo() {
    this.history.undo()
  }

  redo() {
    this.history.redo()
  }
}

export {
  Controller,
}
