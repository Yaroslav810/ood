import {ShapeType} from "../../../model/domain/ShapeType";
import {IShape} from "../../../model/domain/Shape";
import {createRef, ForwardedRef, RefObject, useMemo, useState} from "react";
import {useMovingDragAndDrop} from "../../hooks/dragAndDrop/useMovingDragAndDrop";
import Selected from "../selected/Selected";
import {Rect} from "../../../common/rect/rect";
import {useResizeDragAndDrop} from "../../hooks/dragAndDrop/useResizeDragAndDrop";
import {getDefaultShapeData} from "../../../common/defaultValues";

interface ItemProps {
  shape: IShape
  isSelected: boolean
  scale: number
  selectItem?: (uuid: string) => void
  moveItem?: (frame: Rect) => void
  changeSize?: (frame: Rect) => void
}

function Item(props: ItemProps) {
  const ref: RefObject<SVGForeignObjectElement | SVGImageElement> = createRef()
  const frame = props.shape.getFrame()
  const {fill, stroke} = useMemo(() => getDefaultShapeData(), [getDefaultShapeData])

  const onSelectItem = (e: React.MouseEvent<SVGGElement> | MouseEvent) => {
    e.stopPropagation()
    props.selectItem && props.selectItem(props.shape.getUuid())
  }

  const onMoveItem = (deltaX: number, deltaY: number) => {
    props.moveItem && props.moveItem({
      leftTop: {
        x: frame.leftTop.x + deltaX,
        y: frame.leftTop.y + deltaY,
      },
      width: frame.width,
      height: frame.height,
    })
  }

  const onChangeSizeItem = (deltaX: number, deltaY: number) => {
    props.changeSize && props.changeSize({
      leftTop: {
        x: frame.leftTop.x,
        y: frame.leftTop.y,
      },
      width: frame.width + deltaX,
      height: frame.height + deltaY,
    })
  }

  const [deltaPosition, setDeltaPosition] = useState({dx: 0, dy: 0})
  useMovingDragAndDrop(ref, frame, setDeltaPosition, props.scale, onMoveItem, onSelectItem)

  const refResize: RefObject<SVGRectElement> = createRef()
  const [deltaSize, setDeltaSize] = useState({width: 0, height: 0})
  useResizeDragAndDrop(refResize, frame, setDeltaSize, props.scale, {width: frame.width, height: frame.height}, onChangeSizeItem)

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
      <>
        <g onClick={e => onSelectItem(e)}>
          {content}
        </g>
        {props.isSelected &&
          <Selected
            ref={refResize}
            coordinates={{
              x: frame.leftTop.x + deltaPosition.dx,
              y: frame.leftTop.y + deltaPosition.dy
            }}
            size={{
              width: frame.width + deltaSize.width,
              height: frame.height + deltaSize.height
            }}
            changeSize={onChangeSizeItem}
          />
        }
      </>
  )
}

export {
  Item,
}
