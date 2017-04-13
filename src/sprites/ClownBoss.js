import Phaser from 'phaser'
import PF from 'pathfinding'
import { getBlockableMap } from '../utils'

export class ClownBoss extends Phaser.Sprite {
  constructor (game, asset, tileX, tileY, difficulty) {
    super(game, tileX * game.tileWidth, tileY * game.tileWidth, 'clownBoss')
    game.add.existing(this)
    this.tileX = tileX
    this.tileY = tileY

    this.difficulty = difficulty
    this.health = 100 * difficulty

    this.setupPathFinding()
  }

  setupPathFinding () {
    var coll = this.game.collisionLayer.layer.data
    var binaryMap = getBlockableMap(coll)
    var grid = new PF.Grid(binaryMap)
    this.grid = grid.clone()
    this.finder = new PF.AStarFinder()
    var playerTileX = Math.round(this.game.player.x / this.game.tileWidth)
    var playerTileY = Math.round(this.game.player.y / this.game.tileWidth)
    console.log('path to player: ' + this.finder.findPath(this.tileX, this.tileY, playerTileX, playerTileY, grid))
  }

  findPath () {
    var grid = this.grid
    this.grid = grid.clone()
    var playerTileX = Math.round(this.game.player.x / this.game.tileWidth)
    var playerTileY = Math.round(this.game.player.y / this.game.tileWidth)
    var path = this.finder.findPath(this.tileX, this.tileY, playerTileX, playerTileY, grid)
    console.log('path to player: ' + path)
  }

  moveUsingPath (path) {

  }

  update () {
    this.findPath()
  }
}
