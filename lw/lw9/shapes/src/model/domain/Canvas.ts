import {IShape, Shape} from "./Shape";
import {Observable} from "../common/Observer";

interface ICanvas {
  getShapes(): IShape[]
  getShapesCount(): number
  changeShape(shape: IShape, index: number): void
  addShape(shape: IShape, index: number): void
  deleteShape(index: number): void
  getCanvas(): ICanvas
}

class Canvas extends Observable implements ICanvas {
  private readonly shapes: IShape[]

  constructor() {
    super()
    this.shapes = []
  }

  getShapes(): IShape[] {
    return this.shapes
  }

  getShapesCount(): number {
    return this.shapes.length
  }

  changeShape(shape: IShape, index: number) {
    this.shapes[index] = shape
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
