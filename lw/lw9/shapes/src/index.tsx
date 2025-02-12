import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';
import reportWebVitals from './reportWebVitals';
import {Canvas, ICanvas} from "./model/domain/Canvas";
import {Controller} from "./model/application/Controller";
import {History} from "./common/history/History";

const root = ReactDOM.createRoot(
  document.getElementById('root') as HTMLElement
);

const canvas = new Canvas() // new History() внутри
const history = new History()
const controller = new Controller(canvas, history)

function render(data: ICanvas) {
  root.render(
      <React.StrictMode>
        <App shapes={data.getShapes()} controller={controller} />
      </React.StrictMode>
  );
}

canvas.registerObserver(render)
render(canvas)

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
