import React, {useEffect} from "react"
import {getDefaultValues} from "../../common/defaultValues";

export function useScaleCanvas(
    ref: React.RefObject<SVGSVGElement>,
    setScale: React.Dispatch<React.SetStateAction<number>>
) {
    const handleResize = () => {
        setScale(ref.current ? ref.current.getBoundingClientRect().width / getDefaultValues().canvas.width : 1)
    }

    useEffect(handleResize)

    useEffect(() => {
        if (!ref.current) {
            return
        }

        window.addEventListener("resize", handleResize)

        return () => window.removeEventListener("resize", handleResize)
    })
}
