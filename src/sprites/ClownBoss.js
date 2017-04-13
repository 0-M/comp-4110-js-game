import Phaser from 'phaser'
import PF from 'pathfinding'
import { getBlockableMap } from '../utils'

export class ClownBoss extends Phaser.Sprite {
  constructor (game, asset, tileX, tileY, difficulty) {
    super(game, tileX * game.tileWidth, tileY * game.tileWidth, 'clownBoss')

    game.add.existing(this)
    game.physics.arcade.enable(this)

    this.difficulty = difficulty
    this.health = 100 * difficulty

    this.setupPathFinding()
  }

  setupPathFinding () {
    var coll = this.game.collisionLayer.layer.data
    var binaryMap = getBlockableMap(coll)
    var grid = new PF.Grid(binaryMap)
    this.grid = grid.clone()
    this.finder = new PF.AStarFinder({
      allowDiagonal: true,
      dontCrossCorners: true
    })
    var myX = Math.round(this.x / this.game.tileWidth)
    var myY = Math.round(this.y / this.game.tileWidth)
    var playerTileX = Math.round(this.game.player.x / this.game.tileWidth)
    var playerTileY = Math.round(this.game.player.y / this.game.tileWidth)
    console.log('path to player: ' + this.finder.findPath(myX, myY, playerTileX, playerTileY, grid))
  }

  findPath () {
    var grid = this.grid
    this.grid = grid.clone()
    var myX = Math.round(this.x / this.game.tileWidth)
    var myY = Math.round(this.y / this.game.tileWidth)
    var playerTileX = Math.round(this.game.player.x / this.game.tileWidth)
    var playerTileY = Math.round(this.game.player.y / this.game.tileWidth)
    var path = this.finder.findPath(myX, myY, playerTileX, playerTileY, grid)
    console.log('path to player: ' + path)
//    path.pop()
    this.moveUsingPath(myX, myY, path)
  }

  moveUsingPath (myX, myY, path) {
    this.body.velocity.x = 0
    this.body.velocity.y = 0

    if (path.length > 1) {
      let next = {x: path[1][0], y: path[1][1]}
      let dx = myX - next.x
      let dy = myY - next.y

      if (dx > 0) {
        this.body.velocity.x = -150
      }
      if (dx < 0) {
        this.body.velocity.x = 150
      }
      if (dy > 0) {
        this.body.velocity.y = -150
      }
      if (dy < 0) {
        this.body.velocity.y = 150
      }
    }
  }

  update () {
    this.findPath()
  }
}
