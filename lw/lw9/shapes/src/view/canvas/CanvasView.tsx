import styles from './CanvasView.module.css'
import {useMemo, useRef, useState} from "react";
import {getDefaultValues} from "../../common/defaultValues";
import {Item} from "./item/Item";
import {useScaleCanvas} from "../hooks/useScaleCanvas";
import {ViewData} from "../viewData";

function CanvasView({shapes, controller, selectedUuid, setSelectedUuid}: ViewData) {
  const ref = useRef<SVGSVGElement>(null)
  const [scale, setScale] = useState(1)
  useScaleCanvas(ref, setScale)
  const {canvas} = useMemo(() => getDefaultValues(), [])

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
                moveItem={(frame) => controller.moveShape(uuid, frame)}
                selectItem={setSelectedUuid}
                changeSize={() => {}}
            />
          })
        }
      </svg>
  )
}

export {
  CanvasView,
}
