const getDefaultValues = () => ({
  canvas: {
    width: 640,
    height: 480,
  },
  shape: {
    leftTop: {
      x: 50,
      y: 50,
    },
    width: 50,
    height: 50,
  }
})

function getDefaultColor() {
  return {
    fill: '#00FFFF',
    stroke: '#000000',
  }
}

export {
  getDefaultValues,
  getDefaultColor,
}
