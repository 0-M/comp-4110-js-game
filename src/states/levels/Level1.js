import Phaser from 'phaser'
import Player from '../../sprites/Player'
import { health } from '../../ui/health'
import { xp } from '../../ui/XP'
import { ClownBoss } from '../../sprites/ClownBoss'

export default class extends Phaser.State {
  init () {
  }
  preload () {
    this.load.tilemap('level1map', 'assets/maps/entry_pretty.json', null, Phaser.Tilemap.TILED_JSON)
    // this.load.image('pizza', 'assets/images/pizza-1.png')
    // this.load.image('columns_set', 'assets/maps/tilesets/columns.png')
    this.load.image('tiles', 'assets/maps/tilesets/pretty.png')
  }
  create () {
    this.game.tileWidth = this.tileWidth = 48
    this.setupTileMap()
    health.addHealthToLevel(this)
    xp.addXPToLevel(this)
    this.game.physics.startSystem(Phaser.Physics.ARCADE)
  }

  setupTileMap () {
      //  The 'tavern' key here is the Loader key given in game.load.tilemap
    let map = this.game.add.tilemap('level1map')
  // store a reference so we can access it elsewhere on this class
    this.map = map

  // The first parameter is the tileset name, as specified in the Tiled map editor (and in the tilemap json file)
  // The second parameter maps this name to the Phaser.Cache key 'tiles'
  // map.addTilesetImage('columns_combined', 'columns_set')
  //  map.addTilesetImage('util_tiles', 'util_set')
    map.addTilesetImage('pretty', 'tiles')

  // create the base layer, these are the floors, walls
  // and anything else we want behind any sprites
    map.createLayer('Grass')
    map.createLayer('Collision_tiles')

    // map.createLayer('Collision_tiles')
    // map.createLayer('Columns')

  // next create the collision layer
    this.collisionLayer = map.createLayer('Collision')
    this.game.collisionLayer = this.collisionLayer

  // we don't want the collision layer to be visible
    this.collisionLayer.visible = false

  // inform phaser that our collision layer is our collision tiles
  // in our case, since we separated out the collision tiles into its own layer
  // we pass an empty array and passing in true to enable collision
    map.setCollisionByExclusion([], true, this.collisionLayer)

  //  This resizes the game world to match the layer dimensions
    this.collisionLayer.resizeWorld()

  // we will have to initialize our player here
  // so it's sprite will show between the base and foreground tiles
    this.initPlayer()

  // initialize enemy
    this.initEnemy()

  // creating the foreground layer last after all moving sprites
  // ensures that this layer will stay above during depth sorting
    // map.createLayer('Foreground')

  // pull the exit area from the object layer
  // we will be using this one during update to check if our player has moved into the exit area
    let exit_1 = this.map.objects.metadata.find(o => o.name === 'exit_1')
    this.exitRect_1 = new Phaser.Rectangle(exit_1.x, exit_1.y, exit_1.width, exit_1.height)

    let exit_2 = this.map.objects.metadata.find(o => o.name === 'exit_2')
    this.exitRect_2 = new Phaser.Rectangle(exit_2.x, exit_2.y, exit_2.width, exit_2.height)

    let fence_1 = this.map.objects.metadata.find(o => o.name === 'fence_1')
    this.fenceRect_1 = new Phaser.Rectangle(fence_1.x, fence_1.y, fence_1.width, fence_1.height)

    let fence_2 = this.map.objects.metadata.find(o => o.name === 'fence_2')
    this.fenceRect_2 = new Phaser.Rectangle(fence_2.x, fence_2.y, fence_2.width, fence_2.height)

    let fence_3 = this.map.objects.metadata.find(o => o.name === 'fence_3')
    this.fenceRect_3 = new Phaser.Rectangle(fence_3.x, fence_3.y, fence_3.width, fence_3.height)

    let fence_4 = this.map.objects.metadata.find(o => o.name === 'fence_4')
    this.fenceRect_4 = new Phaser.Rectangle(fence_4.x, fence_4.y, fence_4.width, fence_4.height)

    // let exit_2 = this.map.objects.metadata.find(o => o.name === 'exit_2')
  //  this.exitRect = new Phaser.Rectangle(exit.x, exit.y, exit.width, exit.height)

//  let exit = this.map.objects.metadata.find(o => o.name === 'exit')
// this.exitRect = new Phaser.Rectangle(exit.x, exit.y, exit.width, exit.height)
  }

  initPlayer () {
    this.game.player = this.player = new Player({
      game: this.game,
      x: this.world.centerX,
      y: this.world.centerY,
      asset: 'player_sprite',
      tileX: 2,
      tileY: 4
    })
    this.game.add.existing(this.player)
  }

  render () {
    // useless time-waster right here... physics MUST be called in update ()
  }

  update () {
    this.game.physics.arcade.collide(this.player, this.collisionLayer)

    if (Phaser.Rectangle.containsPoint(this.exitRect_1, this.player.position)) {
      this.resetPlayer()
    }

    if (Phaser.Rectangle.containsPoint(this.exitRect_2, this.player.position)) {
      this.resetPlayer()
    }

    if (Phaser.Rectangle.containsPoint(this.fenceRect_1, this.player.position)) {
      this.player.can_move = false
    }
  }

  initEnemy () {
    var enemies = []

    var e = new ClownBoss(this.game, 5, 5, 5)
    enemies.push(e)

    this.enemies = enemies
  }

  resetPlayer () {
    xp.increaseBy(1)
    this.player.tileX = 8
    this.player.tileY = 4.5
    this.player.position.set(this.player.tileX * this.tileWidth, this.player.tileY * this.tileWidth)
  }
  stopPlayer () {
    this.player.velocity.x = 0
    this.player.velocity.y = 0
  }
}
