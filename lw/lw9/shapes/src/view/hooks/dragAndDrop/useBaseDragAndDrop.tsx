import React, {useCallback, useEffect} from "react"

function useBaseDragAndDrop(
    ref: React.RefObject<Element>,
    onDownCallback?: (e: MouseEvent) => void,
    onMovementCallback?: (e: MouseEvent) => void,
    onUpCallback?: (e: MouseEvent) => void
) {
    const handleMouseMove = useCallback((event: MouseEvent) => {
        onMovementCallback && onMovementCallback(event)
    }, [onMovementCallback])

    const handleMouseUp = useCallback((event: MouseEvent) => {
        onUpCallback && onUpCallback(event)
        document.removeEventListener("mouseup", handleMouseUp)
        document.removeEventListener("mousemove", handleMouseMove)
    }, [handleMouseMove, onUpCallback])

    const handleMouseDown = useCallback((event: Event) => {
        onDownCallback && onDownCallback(event as MouseEvent)
        document.addEventListener("mousemove", handleMouseMove)
        document.addEventListener("mouseup", handleMouseUp)
    }, [handleMouseMove, handleMouseUp, onDownCallback])

    useEffect(() => {
        if (!ref.current) {
            return
        }
        const item = ref.current
        item.addEventListener("mousedown", handleMouseDown)
        return () => item.removeEventListener("mousedown", handleMouseDown)
    }, [ref, handleMouseDown])
}

export {
  useBaseDragAndDrop,
}
