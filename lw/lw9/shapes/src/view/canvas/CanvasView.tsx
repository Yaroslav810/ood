import styles from './CanvasView.module.css'
import {createRef, RefObject, useCallback, useMemo, useRef, useState} from "react";
import {getDefaultCanvasData} from "../../common/defaultValues";
import {Item} from "./item/Item";
import {useScaleCanvas} from "../hooks/useScaleCanvas";
import {ViewData} from "../viewData";
import {IShape} from "../../model/domain/Shape";
import {UUID} from "../../common/uuid/uuid";
import {useItemFunctions} from "../hooks/useItemFunctions";
import Selected from "./selected/Selected";
import {Rect} from "../../common/rect/rect";

function getSelectedFrame(shapes: IShape[], selectedUuid: UUID | null): Rect | null {
  if (!selectedUuid) {
    return null
  }

  const shape = shapes.find(shape => shape.getUuid() === selectedUuid)
  if (!shape) {
    return null
  }

  return shape.getFrame()
}

function CanvasView({
  shapes,
  controller,
  selectedUuid,
  setSelectedUuid,
}: ViewData) {
  const ref = useRef<SVGSVGElement>(null)
  const refResize: RefObject<SVGRectElement> = createRef()
  const scale = useScaleCanvas(ref)
  const canvas = useMemo(() => getDefaultCanvasData(), [])
  const selectedFrame = getSelectedFrame(shapes, selectedUuid)
  const [deltaMove, setDeltaMove] = useState({dx: 0, dy: 0})
  const [deltaResize, setDeltaResize] = useState({dx: 0, dy: 0})
  const {moveItem, changeSize} = useItemFunctions({controller, setSelectedUuid})

  return (
      <svg
          className={styles.canvas}
          ref={ref}
          xmlns="http://www.w3.org/2000/svg"
          viewBox={`0 0 ${canvas.width} ${canvas.height}`}
      >
        {
          shapes.map(shape => {
            const uuid = shape.getUuid()
            const isSelected = uuid === selectedUuid
            return <Item
                key={uuid}
                shape={shape}
                isSelected={isSelected}
                scale={scale}
                refResize={refResize}
                moveItem={(dx: number, dy: number) => moveItem(shape, dx, dy)}
                changeSize={(dx: number, dy: number) => changeSize(shape, dx, dy)}
                onMove={isSelected ? (dx: number, dy: number) => setDeltaMove({dx, dy}) : undefined}
                onResize={isSelected ? (dx: number, dy: number) => setDeltaResize({dx, dy}) : undefined}
                selectItem={setSelectedUuid}
            />
          })
        }
        {
          selectedFrame &&
            <Selected
              ref={refResize}
              coordinates={{
                x: selectedFrame.leftTop.x + deltaMove.dx,
                y: selectedFrame.leftTop.y + deltaMove.dy
              }}
              size={{
                width: selectedFrame.width + deltaResize.dx,
                height: selectedFrame.height + deltaResize.dy
              }}
          />
        }
      </svg>
  )
}

export {
  CanvasView,
}
