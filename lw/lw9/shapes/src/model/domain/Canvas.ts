import {IShape, Shape} from "./Shape";
import {Observable} from "../common/Observer";
import {UUID} from "../../common/uuid/uuid";

interface ICanvas {
  getShapes(): IShape[]
  getShapesCount(): number
  getCanvas(): ICanvas
}

class Canvas extends Observable implements ICanvas {
  private shapes: Shape[]

  constructor() {
    super()
    this.shapes = []
  }

  getShapes(): Shape[] {
    return this.shapes
  }

  getShapesCount(): number {
    return this.shapes.length
  }

  // TODO: Перенести history в Canvas

  insertShape(shape: Shape, index: number): void {
    this.shapes.splice(index, 0, shape)
    this.notifyObservers()
  }

  deleteShape(uuid: UUID): void {
    this.shapes = this.shapes.filter(shape => shape.getUuid() !== uuid)
    this.notifyObservers()
  }

  // TODO: Command || setShapeFrame
  replaceShape(newShape: Shape): void {
    const uuid = newShape.getUuid()
    this.shapes = this.shapes.map(shape => {
      if (shape.getUuid() === uuid) {
        return newShape
      }
      return shape
    })
    this.notifyObservers()
  }

  getCanvas(): ICanvas {
    return this
  }
}

export {
  type ICanvas,
  Canvas,
}
