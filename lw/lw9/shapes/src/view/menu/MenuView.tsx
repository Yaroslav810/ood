import styles from './MenuView.module.css'
import {ShapeType} from "../../model/domain/ShapeType";
import {Controller} from "../../model/application/Controller";

interface MenuViewProps {
  controller: Controller,
}

function MenuView({controller}: MenuViewProps) {
  return (
      <div className={styles.menu}>
        <button className={styles.button} onClick={() => controller.addShape(ShapeType.RECTANGLE)}>Прямоугольник</button>
        <button className={styles.button} onClick={() => controller.addShape(ShapeType.ELLIPSE)}>Эллипс</button>
        <button className={styles.button} onClick={() => controller.addShape(ShapeType.TRIANGLE)}>Треугольник</button>
        <button className={styles.button} onClick={() => controller.undo()}>Отменить</button>
        <button className={styles.button} onClick={() => controller.redo()}>Вернуть</button>
      </div>
  )
}

export {
  MenuView,
}
