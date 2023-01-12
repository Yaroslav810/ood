const getDefaultCanvasData = () => ({
  width: 640,
  height: 480,
})

const getDefaultShapeData = () => ({
  frame: {
    leftTop: {
      x: 50,
      y: 50,
    },
    width: 50,
    height: 50,
  },
  fill: '#00FFFF',
  stroke: '#000000',
})

export {
  getDefaultCanvasData,
  getDefaultShapeData,
}
