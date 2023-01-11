import {ICanvas} from "../domain/Canvas";
import {Shape} from "../domain/Shape";
import {ShapeType} from "../domain/ShapeType";
import {UUID} from "../../common/uuid/uuid";
import {Rect} from "../../common/rect/rect";
import {IHistory} from "../../common/history/History";
import {InsertShapeCommand} from "../../common/command/InsertShapeCommand";

class Controller {
  private readonly canvas: ICanvas
  private readonly history: IHistory

  constructor(canvas: ICanvas, history: IHistory) {
    this.canvas = canvas
    this.history = history
  }

  insertShape(type: ShapeType): void {
    const shape = new Shape(type)
    const count = this.canvas.getShapesCount()
    this.history.addAndExecuteCommand(new InsertShapeCommand(shape, count, this.canvas))
  }

  deleteShape(index: number): void {
    this.canvas.deleteShape(index)
  }

  changeFrameShape(uuid: UUID, frame: Rect): void {
    // this.canvas.changeShape()
    // this.canvas.getShapes().filter(shape => {
    //   if (shape.getUuid() === uuid) {
    //     shape.setFrame(frame)
    //   }
    // })
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
