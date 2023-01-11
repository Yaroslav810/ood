import React from 'react';
import {Shape} from "./model/domain/Shape";
import {Controller} from "./model/application/Controller";
import {MenuView} from "./view/menu/MenuView";
import {CanvasView} from "./view/canvas/CanvasView";
import styles from './App.module.css';

interface AppProps {
  shapes: Shape[],
  controller: Controller,
}

function App({shapes, controller}: AppProps) {

  return (
    <div className={styles.content}>
      <MenuView controller={controller} />
      <CanvasView shapes={shapes} />
    </div>
  );
}

export default App;
