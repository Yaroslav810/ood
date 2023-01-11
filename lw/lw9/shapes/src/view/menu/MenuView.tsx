import styles from './MenuView.module.css'
import React, {useCallback} from "react";
import {ShapeType} from "../../model/domain/ShapeType";
import {Controller} from "../../model/application/Controller";

interface MenuViewProps {
  controller: Controller,
}

function MenuView({controller}: MenuViewProps) {
  const handler = useCallback((e: React.MouseEvent, fn: Function) => {
    e.stopPropagation()
    fn()
  }, [])

  return (
      <div className={styles.menu}>
        <button className={styles.button} onClick={(e) => handler(e, () => controller.addShape(ShapeType.RECTANGLE))}>Прямоугольник</button>
        <button className={styles.button} onClick={(e) => handler(e, () => controller.addShape(ShapeType.ELLIPSE))}>Эллипс</button>
        <button className={styles.button} onClick={(e) => handler(e, () => controller.addShape(ShapeType.TRIANGLE))}>Треугольник</button>
        <button className={styles.button} onClick={(e) => handler(e, () => controller.undo())}>Отменить</button>
        <button className={styles.button} onClick={(e) => handler(e, () => controller.redo())}>Вернуть</button>
      </div>
  )
}

export {
  MenuView,
}
