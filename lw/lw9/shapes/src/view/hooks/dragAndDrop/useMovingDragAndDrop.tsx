import React, {Dispatch, RefObject, SetStateAction} from "react"
import {useBaseDragAndDrop} from "./useBaseDragAndDrop"

function useMovingDragAndDrop(
    ref: RefObject<Element>,
    setDelta: Dispatch<SetStateAction<{dx: number, dy: number}>>,
    scale: number,
    moveItem?: (deltaX: number, deltaY: number) => void,
    selectItem?: (e: MouseEvent) => void
) {
    let startPosition: {x: number, y: number} = {x: 0, y: 0}

    const deltaCounting = (event: MouseEvent) => {
        return {
            dx: (event.pageX - startPosition.x) / scale,
            dy: (event.pageY - startPosition.y) / scale
        }
    }

    const handleMouseDown = (event: MouseEvent) => {
        selectItem && selectItem(event)
        startPosition = {
            x: event.pageX,
            y: event.pageY
        }
    }

    const handleMouseMove = (event: MouseEvent) => {
        const d = deltaCounting(event)
        setDelta({
            dx: d.dx,
            dy: d.dy
        })
    }

    const handleMouseUp = (event: MouseEvent) => {
        const d = deltaCounting(event)
        if (d.dx !== 0 || d.dy !== 0) {
            moveItem && moveItem(d.dx, d.dy)
        }
        setDelta({
            dx: 0,
            dy: 0
        })
    }

    useBaseDragAndDrop(ref, handleMouseDown, handleMouseMove, handleMouseUp)
}

export {
  useMovingDragAndDrop,
}
