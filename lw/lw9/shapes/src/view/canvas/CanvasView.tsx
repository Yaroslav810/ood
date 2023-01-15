import styles from './CanvasView.module.css'
import {useMemo, useRef} from "react";
import {getDefaultCanvasData} from "../../common/defaultValues";
import {Item} from "./item/Item";
import {useScaleCanvas} from "../hooks/useScaleCanvas";
import {ViewData} from "../viewData";
import {useItemFunctions} from "../hooks/useItemFunctions";

function CanvasView({shapes, controller, selectedUuid, setSelectedUuid}: ViewData) {
  const ref = useRef<SVGSVGElement>(null)
  const scale = useScaleCanvas(ref)
  const canvas = useMemo(() => getDefaultCanvasData(), [])
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
            return <Item
                key={uuid}
                shape={shape}
                isSelected={uuid === selectedUuid}
                scale={scale}
                moveItem={(dx: number, dy: number) => moveItem(shape, dx, dy)}
                changeSize={(dx: number, dy: number) => changeSize(shape, dx, dy)}
                selectItem={setSelectedUuid}
            />
          })
        }
      </svg>
  )
}

export {
  CanvasView,
}
