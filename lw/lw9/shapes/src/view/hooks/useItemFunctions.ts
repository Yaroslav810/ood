import {Dispatch, SetStateAction, useCallback} from "react";
import {IShape} from "../../model/domain/Shape";
import {Controller} from "../../model/application/Controller";
import {UUID} from "../../common/uuid/uuid";

interface Props {
  controller: Controller,
  setSelectedUuid: Dispatch<SetStateAction<UUID | null>>,
}

function useItemFunctions({controller, setSelectedUuid}: Props) {
  const moveItem = useCallback((shape: IShape, deltaX: number, deltaY: number) => {
    const uuid = shape.getUuid()
    const frame = shape.getFrame()
    controller.changeFrameShape(
        uuid,
        {
          leftTop: {
            x: frame.leftTop.x + deltaX,
            y: frame.leftTop.y + deltaY,
          },
          width: frame.width,
          height: frame.height,
        },
        () => setSelectedUuid(uuid))
  }, [])

  const changeSize = useCallback((shape: IShape, deltaX: number, deltaY: number) => {
    const uuid = shape.getUuid()
    const frame = shape.getFrame()
    controller.changeFrameShape(
        uuid,
        {
          leftTop: {
            x: frame.leftTop.x,
            y: frame.leftTop.y,
          },
          width: frame.width + deltaX,
          height: frame.height + deltaY,
        },
        () => setSelectedUuid(uuid))
  }, [])

  return {
    moveItem,
    changeSize,
  }
}

export {
  useItemFunctions,
}
