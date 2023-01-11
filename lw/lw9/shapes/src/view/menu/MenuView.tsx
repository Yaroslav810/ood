import styles from './MenuView.module.css'
import {ShapeType} from "../../model/domain/ShapeType";
import {Controller} from "../../model/application/Controller";

interface MenuViewProps {
  controller: Controller,
}

function MenuView({controller}: MenuViewProps) {
  return (
      <div className={styles.menu}>
        <button className={styles.button} onClick={() => controller.insertShape(ShapeType.RECTANGLE)}>Прямоугольник</button>
        <button className={styles.button} onClick={() => controller.insertShape(ShapeType.ELLIPSE)}>Эллипс</button>
        <button className={styles.button} onClick={() => controller.insertShape(ShapeType.TRIANGLE)}>Треугольник</button>
        <button className={styles.button}>Отменить</button>
        <button className={styles.button}>Вернуть</button>
      </div>
  )
}

export {
  MenuView,
}
