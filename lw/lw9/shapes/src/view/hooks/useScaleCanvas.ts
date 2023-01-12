import React, {useCallback, useEffect, useState} from "react";
import {getDefaultCanvasData} from "../../common/defaultValues";

function useScaleCanvas(
    ref: React.RefObject<SVGSVGElement>,
) {
    const [scale, setScale] = useState(1)

    const handleResize = useCallback(() => {
      setScale(ref.current ? ref.current.getBoundingClientRect().width / getDefaultCanvasData().width : 1)
    }, [setScale])

    useEffect(handleResize)
    useEffect(() => {
        if (!ref.current) {
            return
        }
        window.addEventListener("resize", handleResize)
        return () => window.removeEventListener("resize", handleResize)
    })

    return scale
}

export {
  useScaleCanvas,
}
