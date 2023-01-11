import {ICanvas} from "../domain/Canvas";
import {Shape} from "../domain/Shape";
import {ShapeType} from "../domain/ShapeType";

class Controller {
  private readonly canvas: ICanvas

  constructor(canvas: ICanvas) {
    this.canvas = canvas
  }

  insertShape(type: ShapeType): void {
    this.canvas.insertShape(new Shape(type), this.canvas.getShapesCount())
  }

  deleteShape(index: number): void {
    this.canvas.deleteShape(index)
  }

  moveShape(id: string): void {
    // TODO: Реализовать
  }

  resizeShape(id: string) {
    // TODO: Реализовать
  }
}

export {
  Controller,
}
