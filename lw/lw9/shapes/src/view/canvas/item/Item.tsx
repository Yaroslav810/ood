import {ShapeType} from "../../../model/domain/ShapeType";
import {Shape} from "../../../model/domain/Shape";
import {createRef, ForwardedRef, RefObject, useState} from "react";
import {useMovingDragAndDrop} from "../../hooks/dragAndDrop/useMovingDragAndDrop";
import Selected from "../selected/Selected";

interface ItemProps {
  shape: Shape
  isSelected: boolean
  scale: number
  selectItem?: (id: string) => void
  moveItem?: (deltaX: number, deltaY: number) => void
  changeSize?: (deltaX: number, deltaY: number) => void
}

function Item(props: ItemProps) {
  const ref: RefObject<SVGForeignObjectElement | SVGImageElement> = createRef()

  const onSelectItem = (e: MouseEvent) => {
    // TODO: Реализовать
  }

  const [deltaPosition, setDeltaPosition] = useState({dx: 0, dy: 0})
  useMovingDragAndDrop(ref, setDeltaPosition, props.scale, props.moveItem, onSelectItem)

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
        {content}
        {props.isSelected &&
          <Selected
            ref={refResize}
            coordinates={{
              x: props.shape.getFrame().leftTop.x + deltaPosition.dx,
              y: props.shape.getFrame().leftTop.y + deltaPosition.dy
            }}
            size={{
              width: props.shape.getFrame().width + deltaSize.width,
              height: props.shape.getFrame().height + deltaSize.height
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
