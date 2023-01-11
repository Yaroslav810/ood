import React from "react"
import {useBaseDragAndDrop} from "./useBaseDragAndDrop"

function useResizeDragAndDrop(
    ref: React.RefObject<SVGElement>,
    setDeltaSize: React.Dispatch<React.SetStateAction<{width: number, height: number}>>,
    scale: number,
    size: {width: number, height: number},
    changeSize?: (deltaX: number, deltaY: number) => void
) {
    let startPosition: {x: number, y: number} = {x: 0, y: 0}

    const deltaCounting = (event: MouseEvent) => {
        const delta = {
            width: (event.pageX - startPosition.x) / scale,
            height: (event.pageY - startPosition.y) / scale
        }
        if (delta.width < -size.width) {
            delta.width = -size.width
        }
        if (delta.height < -size.height) {
            delta.height = -size.height
        }
        return delta
    }
    const cancelMouseClick = () => {
        const captureClick = (e: MouseEvent) => {
            e.stopPropagation()
            window.removeEventListener('click', captureClick, true)
        }

        window.addEventListener('click', captureClick, true);
    }
    const handleMouseDown = (event: MouseEvent) => {
        startPosition = {
            x: event.pageX,
            y: event.pageY
        }
    }
    const handleMouseMove = (event: MouseEvent) => {
        setDeltaSize(deltaCounting(event))
    }
    const handleMouseUp = (event: MouseEvent) => {
        const d = deltaCounting(event)
        setDeltaSize({
            width: 0,
            height: 0
        })

        if (d.width !== 0 || d.height !== 0) {
            changeSize && changeSize(d.width, d.height)
        }
        cancelMouseClick()
    }
    useBaseDragAndDrop(ref, handleMouseDown, handleMouseMove, handleMouseUp)
}

export {
  useResizeDragAndDrop,
}
