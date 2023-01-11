import React, {useState} from 'react';
import {IShape} from "./model/domain/Shape";
import {Controller} from "./model/application/Controller";
import {MenuView} from "./view/menu/MenuView";
import {CanvasView} from "./view/canvas/CanvasView";
import styles from './App.module.css';
import {UUID} from "./common/uuid/uuid";

interface AppProps {
  shapes: IShape[],
  controller: Controller,
}

function App({shapes, controller}: AppProps) {
  const [selectedUuid, setSelectedUuid] = useState<UUID | null>(null)

  return (
    <div className={styles.content}>
      <MenuView controller={controller} />
      <CanvasView
          shapes={shapes}
          controller={controller}
          selectedUuid={selectedUuid}
          setSelectedUuid={setSelectedUuid}
      />
    </div>
  );
}

export default App;