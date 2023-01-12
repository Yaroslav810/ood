import {ShapeType} from "../../../model/domain/ShapeType";
import {IShape} from "../../../model/domain/Shape";
import {createRef, ForwardedRef, RefObject, useMemo, useState} from "react";
import {useMovingDragAndDrop} from "../../hooks/dragAndDrop/useMovingDragAndDrop";
import {useResizeDragAndDrop} from "../../hooks/dragAndDrop/useResizeDragAndDrop";
import {getDefaultShapeData} from "../../../common/defaultValues";

interface ItemProps {
  shape: IShape
  isSelected: boolean
  scale: number
  refResize: RefObject<SVGRectElement>
  selectItem: (uuid: string) => void
  moveItem: (deltaX: number, deltaY: number) => void
  changeSize: (deltaX: number, deltaY: number) => void
  onMove?: (deltaX: number, deltaY: number) => void
  onResize?: (deltaX: number, deltaY: number) => void
}

function Item(props: ItemProps) {
  const {isSelected, refResize, moveItem, changeSize, onMove, onResize} = props
  const ref: RefObject<SVGImageElement> = createRef()
  const frame = props.shape.getFrame()
  const {fill, stroke} = useMemo(() => getDefaultShapeData(), [getDefaultShapeData])

  const onSelectItem = (e: React.MouseEvent<SVGGElement> | MouseEvent) => {
    e.stopPropagation()
    props.selectItem(props.shape.getUuid())
  }

  const changeMove = (dx: number, dy: number) => {
    setDeltaPosition({dx, dy})
    onMove && onMove(dx, dy)
  }

  const changeSizeItem = (width: number, height: number) => {
    setDeltaSize({width, height})
    onResize && onResize(width, height)
  }

  const [deltaPosition, setDeltaPosition] = useState({dx: 0, dy: 0})
  useMovingDragAndDrop(ref, frame, changeMove, props.scale, moveItem, isSelected)

  const [deltaSize, setDeltaSize] = useState({width: 0, height: 0})
  useResizeDragAndDrop(refResize, frame, changeSizeItem, props.scale, {width: frame.width, height: frame.height}, changeSize, isSelected)

  let content = null
  switch (props.shape.getType()) {
    case ShapeType.RECTANGLE:
      content = <rect
          ref={ref as ForwardedRef<SVGRectElement>}
          x={frame.leftTop.x + deltaPosition.dx}
          y={frame.leftTop.y + deltaPosition.dy}
          width={frame.width + deltaSize.width}
          height={frame.height + deltaSize.height}
          fill={fill}
          stroke={stroke}
      />
      break;
    case ShapeType.ELLIPSE:
      content = <ellipse
          ref={ref as ForwardedRef<SVGEllipseElement>}
          cx={frame.leftTop.x + (frame.width + deltaSize.width) / 2 + deltaPosition.dx}
          cy={frame.leftTop.y + (frame.height + deltaSize.height) / 2 + deltaPosition.dy}
          rx={(frame.width + deltaSize.width) / 2}
          ry={(frame.height + deltaSize.height) / 2}
          fill={fill}
          stroke={stroke}
      />
      break;
    case ShapeType.TRIANGLE:
      content = <polygon
          ref={ref as ForwardedRef<SVGPolygonElement>}
          points={`${frame.leftTop.x + deltaPosition.dx} ${frame.leftTop.y + deltaPosition.dy + frame.height + deltaSize.height}, 
                        ${frame.leftTop.x + deltaPosition.dx + (frame.width + deltaSize.width) / 2} ${frame.leftTop.y + deltaPosition.dy}, 
                        ${frame.leftTop.x + deltaPosition.dx + (frame.width + deltaSize.width)} ${frame.leftTop.y + deltaPosition.dy + frame.height + deltaSize.height}`}
          fill={fill}
          stroke={stroke}
      />
  }

  return (
      <g onClick={e => onSelectItem(e)}>
        {content}
      </g>
  )
}

export {
  Item,
}
