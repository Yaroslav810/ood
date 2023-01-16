import {ICanvas} from "../domain/Canvas";

// TODO: Вынести логику Observable
abstract class Observable {
  private observers: Function[] = [];

  registerObserver(fn: Function) {
    this.observers.push(fn)
  }

  removeObserver(fn: Function) {
    this.observers.filter(observer => observer !== fn)
  }

  notifyObservers() {
    const data = this.getCanvas()
    this.observers.forEach(fn => fn(data))
  }

  abstract getCanvas(): ICanvas
}

export {
  Observable,
}
