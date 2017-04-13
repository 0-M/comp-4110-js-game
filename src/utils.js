export const centerGameObjects = (objects) => {
  objects.forEach(function (object) {
    object.anchor.setTo(0.5)
  })
}

export const getBlockableMap = function (map) {
  var output = []
  for (var i = 0; i < map.length; i++) {
    let tiles = map[i]
    let out = tiles.map((value, index) => {
      if (value.collides) {
        return 1
      } else {
        return 0
      }
    })
    output.push(out)
  }
  return output
}
