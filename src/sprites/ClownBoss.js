import Phaser from 'phaser'
import PF from 'pathfinding'

export default class extends Phaser.Sprite {
  constructor ({game, x, y, asset, tileX, tileY, player, difficulty}) {
    super(game, tileX * game.tileWidth, tileY * game.tileWidth, 'clownBoss')
    this.tileX = tileX
    this.tileY = tileY
    this.setupPathFinding()
  }

  setupPathFinding () {
    var coll = this.game.collisionLayer
    var grid = new PF.Grid(coll.tiles)
    this.grid = grid.clone()
    this.finder = new PF.AStarFinder()
    console.log('path to player: ' + this.finder.findPath(this.tileX, this.tileY, this.player.tileX, this.player.tileY, grid))
  }

  findPath () {
    var grid = this.grid
    this.grid = grid.clone()
    console.log('path to player: ' + this.finder.findPath(this.tileX, this.tileY, this.player.tileX, this.player.tileY, grid))
  }
}
