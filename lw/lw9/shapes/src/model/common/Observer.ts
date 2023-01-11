import {Shape} from "../domain/Shape";

abstract class Observer {
  abstract Update(): void;
}

abstract class Observable {
  private observers: Function[] = [];

  registerObserver(fn: Function) {
    this.observers.push(fn)
  }

  removeObserver(fn: Function) {
    this.observers.filter(observer => observer !== fn)
  }

  notifyObservers() {
    const data = this.getShapes()
    this.observers.forEach(fn => fn(data))
  }

  abstract getShapes(): Shape[]
}

export {
  Observer,
  Observable,
}
