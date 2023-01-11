import React, {ForwardedRef} from "react"

interface SelectedProps {
    coordinates: {x: number, y: number}
    size: {width: number, height: number}
    changeSize?: (deltaX: number, deltaY: number) => void
    setNewSize?: (deltaX: number, deltaY: number) => void
}

const Selected = React.forwardRef((props: SelectedProps, ref: ForwardedRef<SVGRectElement>) => {
    return (
        <>
            <rect
                x={props.coordinates.x - 2}
                y={props.coordinates.y - 2}
                width={props.size.width + 4}
                height={props.size.height + 4}
                fill={'none'}
                stroke={'#000'}
                strokeDasharray={4}
                strokeWidth={1}
            />
            <rect
                ref={ref}
                x={props.coordinates.x + props.size.width - 3}
                y={props.coordinates.y + props.size.height - 2}
                width={8}
                height={8}
                fill={'#fff'}
                stroke={'#000'}
                strokeWidth={1}
                cursor={'nwse-resize'}
            />
        </>
    )
})

export default Selected
