import React, {Dispatch, RefObject, SetStateAction} from "react"
import {useBaseDragAndDrop} from "./useBaseDragAndDrop"
import {Rect} from "../../../common/rect/rect";
import {getDefaultValues} from "../../../common/defaultValues";

function useMovingDragAndDrop(
    ref: RefObject<Element>,
    frame: Rect,
    setDelta: Dispatch<SetStateAction<{dx: number, dy: number}>>,
    scale: number,
    moveItem?: (deltaX: number, deltaY: number) => void,
    selectItem?: (e: MouseEvent) => void
) {
    const {canvas} = getDefaultValues()
    let startPosition: {x: number, y: number} = {x: 0, y: 0}

    const deltaCounting = (event: MouseEvent) => {
        return {
            dx: (event.pageX - startPosition.x) / scale,
            dy: (event.pageY - startPosition.y) / scale
        }
    }

    const calculateOverflow = (d: {dx: number, dy: number}) => {
        if (frame.leftTop.x + d.dx < 0) {
            d.dx = -frame.leftTop.x
        }
        if (frame.leftTop.y + d.dy < 0) {
            d.dy = -frame.leftTop.y
        }
        if (frame.leftTop.x + frame.width + d.dx > canvas.width) {
            d.dx = canvas.width - frame.width - frame.leftTop.x
        }
        if (frame.leftTop.y + frame.height + d.dy > canvas.height) {
            d.dy = canvas.height - frame.height - frame.leftTop.y
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
        calculateOverflow(d)
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
