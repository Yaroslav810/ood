import styles from './CanvasView.module.css'
import {useMemo, useRef, useState} from "react";
import {getDefaultValues} from "../../common/defaultValues";
import {Shape} from "../../model/domain/Shape";
import {Item} from "./item/Item";
import {useScaleCanvas} from "../hooks/useScaleCanvas";

interface CanvasViewProps {
  shapes: Shape[]
}

function CanvasView({shapes}: CanvasViewProps) {
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
            return <Item
                key={shape.getUuid()}
                shape={shape}
                isSelected={false}
                scale={scale}
                moveItem={() => {}}
                selectItem={() => {}}
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
