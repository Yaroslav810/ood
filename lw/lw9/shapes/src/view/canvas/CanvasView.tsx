import styles from './CanvasView.module.css'
import {useMemo} from "react";
import {getDefaultValues} from "../../common/defaultValues";

function CanvasView() {
  const {canvas} = useMemo(() => getDefaultValues(), [])

  return (
      <svg
          className={styles.canvas}
          xmlns="http://www.w3.org/2000/svg"
          viewBox={`0 0 ${canvas.width} ${canvas.height}`}
      >

      </svg>
  )
}

export {
  CanvasView,
}
