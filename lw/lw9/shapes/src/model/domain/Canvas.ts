import {Shape} from "./Shape";
import {Observable} from "../common/Observer";

interface ICanvas {
  getShapes(): Shape[]
  getShapesCount(): number
  insertShape(shape: Shape, index: number): void
  deleteShape(index: number): void
}

class Canvas extends Observable implements ICanvas {
  private readonly shapes: Shape[]

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

  insertShape(shape: Shape, index: number): void {
    this.shapes.splice(index, 0, shape)
    this.notifyObservers()
  }

  deleteShape(index: number): void {
    this.shapes.splice(index, 1)
    this.notifyObservers()
  }
}

export {
  type ICanvas,
  Canvas,
}
