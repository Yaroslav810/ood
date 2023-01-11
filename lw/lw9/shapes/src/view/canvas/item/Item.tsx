import {ShapeType} from "../../../model/domain/ShapeType";
import {IShape} from "../../../model/domain/Shape";
import {createRef, ForwardedRef, RefObject, useState} from "react";
import {useMovingDragAndDrop} from "../../hooks/dragAndDrop/useMovingDragAndDrop";
import Selected from "../selected/Selected";
import {Rect} from "../../../common/rect/rect";

interface ItemProps {
  shape: IShape
  isSelected: boolean
  scale: number
  selectItem?: (uuid: string) => void
  moveItem?: (frame: Rect) => void
  changeSize?: (deltaX: number, deltaY: number) => void
}

function Item(props: ItemProps) {
  const ref: RefObject<SVGForeignObjectElement | SVGImageElement> = createRef()
  const frame = props.shape.getFrame()

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

  const [deltaPosition, setDeltaPosition] = useState({dx: 0, dy: 0})
  useMovingDragAndDrop(ref, setDeltaPosition, props.scale, onMoveItem, onSelectItem)

  const refResize: RefObject<SVGRectElement> = createRef()
  const [deltaSize, setDeltaSize] = useState({width: 0, height: 0})

  let content = null
  switch (props.shape.getType()) {
    case ShapeType.RECTANGLE:
      content = <rect
          ref={ref as ForwardedRef<SVGRectElement>}
          x={props.shape.getFrame().leftTop.x + deltaPosition.dx}
          y={props.shape.getFrame().leftTop.y + deltaPosition.dy}
          width={props.shape.getFrame().width}
          height={props.shape.getFrame().height}
          fill={'red'}
          strokeWidth={2}
          onClick={(e) => {}}
      />
      break;
    case ShapeType.ELLIPSE:
      content = <ellipse
          ref={ref as ForwardedRef<SVGEllipseElement>}
          cx={props.shape.getFrame().leftTop.x + props.shape.getFrame().width / 2 + deltaPosition.dx}
          cy={props.shape.getFrame().leftTop.y + props.shape.getFrame().height / 2 + deltaPosition.dy}
          rx={props.shape.getFrame().width / 2}
          ry={props.shape.getFrame().height / 2}
          fill={'red'}
          strokeWidth={2}
          onClick={(e) => {}}
      />
      break;
    case ShapeType.TRIANGLE:
      content = <polygon
          ref={ref as ForwardedRef<SVGPolygonElement>}
          points={`${props.shape.getFrame().leftTop.x + deltaPosition.dx} ${props.shape.getFrame().leftTop.y + deltaPosition.dy + props.shape.getFrame().height}, 
                        ${props.shape.getFrame().leftTop.x + deltaPosition.dx + props.shape.getFrame().width / 2} ${props.shape.getFrame().leftTop.y + deltaPosition.dy}, 
                        ${props.shape.getFrame().leftTop.x + deltaPosition.dx + props.shape.getFrame().width} ${props.shape.getFrame().leftTop.y + deltaPosition.dy + props.shape.getFrame().height}`}
          fill={'red'}
          strokeWidth={2}
          onClick={(e) => {}}
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
            changeSize={props.changeSize}
          />
        }
      </>
  )
}

export {
  Item,
}
