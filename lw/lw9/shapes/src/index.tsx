import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';
import reportWebVitals from './reportWebVitals';
import {Canvas} from "./model/domain/Canvas";
import {Controller} from "./model/application/Controller";
import {Shape} from "./model/domain/Shape";

const root = ReactDOM.createRoot(
  document.getElementById('root') as HTMLElement
);

const canvas = new Canvas()
const controller = new Controller(canvas)

function render(data: Shape[]) {
  root.render(
      <React.StrictMode>
        <App shapes={data} controller={controller} />
      </React.StrictMode>
  );
}

canvas.registerObserver(render)
render([])

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
