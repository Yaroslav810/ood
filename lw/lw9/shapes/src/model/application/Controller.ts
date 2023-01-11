import {ICanvas} from "../domain/Canvas";
import {Shape} from "../domain/Shape";
import {ShapeType} from "../domain/ShapeType";
import {UUID} from "../../common/uuid/uuid";
import {Rect} from "../../common/rect/rect";
import {IHistory} from "../../common/history/History";

class Controller {
  private readonly canvas: ICanvas
  private readonly history: IHistory

  constructor(canvas: ICanvas, history: IHistory) {
    this.canvas = canvas
    this.history = history
  }

  insertShape(type: ShapeType): void {
    // new Shape(type)
    // history.addAndExecute new InsertShapeCommand(shape, index, canvas)
    this.canvas.addShape(new Shape(type), this.canvas.getShapesCount())
  }

  deleteShape(index: number): void {
    this.canvas.deleteShape(index)
  }

  // TODO: Один метод changeFrameShape
  moveShape(uuid: UUID, frame: Rect): void {
    // this.canvas.changeShape()
    // this.canvas.getShapes().filter(shape => {
    //   if (shape.getUuid() === uuid) {
    //     shape.setFrame(frame)
    //   }
    // })
  }

  resizeShape(uuid: UUID, dx: number, dy: number) {
    this.canvas.getShapes().forEach(shape => {
      if (shape.getUuid() === uuid) {
        const frame = shape.getFrame()
        // shape.setFrame({
        //   leftTop: frame.leftTop,
        //   width: frame.width + dx,
        //   height: frame.height + dy,
        // })
      }
    })
  }
}

export {
  Controller,
}
