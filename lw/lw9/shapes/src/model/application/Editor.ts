class Editor {
  private observers: Function[];

  constructor() {
    this.observers = []
  }

  registerObserver(fn: Function) {
    this.observers.push(fn)
  }

  notifyObservers() {
    this.observers.forEach(fn => fn())
  }

  removeObserver() {}
}

export {
  Editor,
}
