import React, {RefObject} from "react"
import {useBaseDragAndDrop} from "./useBaseDragAndDrop"
import {Rect} from "../../../common/rect/rect";
import {getDefaultCanvasData} from "../../../common/defaultValues";

function useMovingDragAndDrop(
    ref: RefObject<Element>,
    frame: Rect,
    changeMove: (dx: number, dy: number) => void,
    scale: number,
    moveItem: (deltaX: number, deltaY: number) => void,
    isSelected: boolean,
) {
    const canvas = getDefaultCanvasData()
    let startPosition: {x: number, y: number} = {x: 0, y: 0}

    const deltaCounting = (event: MouseEvent) => {
        const delta = {
            dx: (event.pageX - startPosition.x) / scale,
            dy: (event.pageY - startPosition.y) / scale
        }
        calculateOverflow(delta)
        return delta
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
        startPosition = {
            x: event.pageX,
            y: event.pageY
        }
    }

    const handleMouseMove = (event: MouseEvent) => {
        const d = deltaCounting(event)
        changeMove(d.dx, d.dy)
    }

    const handleMouseUp = (event: MouseEvent) => {
        const d = deltaCounting(event)
        if (d.dx !== 0 || d.dy !== 0) {
            moveItem && moveItem(d.dx, d.dy)
        }
        changeMove(0, 0)
    }

    useBaseDragAndDrop(ref, isSelected, handleMouseDown, handleMouseMove, handleMouseUp)
}

export {
  useMovingDragAndDrop,
}
