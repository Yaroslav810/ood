import {ShapeType} from "./ShapeType";
import {Rect} from "../../common/rect/rect";
import {generateUuid, UUID} from "../../common/uuid/uuid";
import {getDefaultValues} from "../../common/defaultValues";

interface IShape {
  getUuid(): UUID
  getFrame(): Rect
  getType(): ShapeType
}

class Shape implements IShape {
  private readonly uuid: UUID
  private readonly type: ShapeType
  private frame: Rect

  constructor(type: ShapeType) {
    this.uuid = generateUuid()
    this.type = type
    this.frame = getDefaultValues().shape
  }

  getUuid(): UUID {
    return this.uuid
  }

  getFrame(): Rect {
    return this.frame
  }

  getType(): ShapeType {
    return this.type
  }

  setFrame(frame: Rect): void {
    this.frame = frame
  }
}

export {
  type IShape,
  Shape,
}
