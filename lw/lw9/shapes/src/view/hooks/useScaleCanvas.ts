import React, {useCallback, useEffect} from "react"
import {getDefaultValues} from "../../common/defaultValues";

function useScaleCanvas(
    ref: React.RefObject<SVGSVGElement>,
    setScale: React.Dispatch<React.SetStateAction<number>>
) {
    const handleResize = useCallback(() => {
      setScale(ref.current ? ref.current.getBoundingClientRect().width / getDefaultValues().canvas.width : 1)
    }, [setScale])
    useEffect(handleResize)
    useEffect(() => {
        if (!ref.current) {
            return
        }
        window.addEventListener("resize", handleResize)
        return () => window.removeEventListener("resize", handleResize)
    })
}

export {
  useScaleCanvas,
}
