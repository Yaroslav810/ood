import {IShape, Shape} from "./Shape";
import {Observable} from "../common/Observer";

interface ICanvas {
  getShapes(): IShape[]
  getShapesCount(): number
  addShape(shape: IShape, index: number): void
  deleteShape(index: number): void
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

  addShape(shape: Shape, index: number): void {
    this.shapes.splice(index, 0, shape)
    this.notifyObservers()
  }

  deleteShape(index: number): void {
    this.shapes.splice(index, 1)
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
