import Phaser from 'phaser'
import PF from 'pathfinding'
import { getBlockableMap } from '../utils'
import { combat } from '../combat'

export class Enemy extends Phaser.Sprite {
  constructor (game, asset, tileX, tileY, difficulty, sprite) {
    super(game, tileX * game.tileWidth, tileY * game.tileWidth, sprite)

    game.add.existing(this)
    game.physics.arcade.enable(this)

    this.difficulty = difficulty
    this.health = 100 * difficulty
    this.damage = 5 * difficulty
    this.defense = 10 * difficulty
    this.meleeTime = Math.max(1, (5 - difficulty))
    this.meleeCooldown = 0
    this.attacking = false
    this.setupPathFinding()

    this.animating = false

    this.walkSpeed = 150
    this.walkAnimSpeed = 6    // Frames per second

    this.attackAnimSpeed = 20 // Frames per second
    this.attackDuration = 1000 // Milliseconds

    this.lastAnimation = 'down'
    this.animations.add('upwalk', [12, 13, 14, 15])
    this.animations.add('leftwalk', [4, 5, 6, 7])
    this.animations.add('rightwalk', [8, 9, 10, 11])
    this.animations.add('downwalk', [0, 1, 2, 3])

    this.animations.add('attack', [16,16,17,17,18,18,19,19,   20,21,22,21,20,21,22,   23,23,24,24,25,25,26,26])
  }

  animateWalkingUp () {
    this.animations.play('upwalk', this.walkAnimSpeed, false)
  }
  animateWalkingDown () {
    this.animations.play('downwalk', this.walkAnimSpeed, false)
  }
  animateWalkingLeft () {
    this.animations.play('leftwalk', this.walkAnimSpeed, false)
  }
  animateWalkingRight () {
    this.animations.play('rightwalk', this.walkAnimSpeed, false)
  }

  animateAttacking () {
    this.animations.play('attack', this.attackAnimSpeed, false)
    this.lastAnimation = 'down'
    setTimeout(() => {this.setAnimatingFalse()}, this.attackDuration);
  }

  setAnimatingFalse() {
    this.animating = false
  }

  cooldown (key) {
    this[key]--
    if (this[key] > 0) {
      setTimeout(() => {
        this.cooldown(key)
      }, 1000)
    } else {
      console.log('cooldown complete for attack: ' + key)
    }
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

  followPlayer () {
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

    if(!this.animating) {
      if (path.length > 1) {
        let next = {x: path[1][0], y: path[1][1]}
        let dx = myX - next.x
        let dy = myY - next.y

        if (dx > 0) {
          this.body.velocity.x = -150
          this.animateWalkingLeft()
          this.lastAnimation = 'left'
        }
        if (dx < 0) {
          this.body.velocity.x = 150
          this.animateWalkingRight()
          this.lastAnimation = 'right'
        }
        if (dy > 0) {
          this.body.velocity.y = -150
          this.animateWalkingUp()
          this.lastAnimation = 'up'
        }
        if (dy < 0) {
          this.body.velocity.y = 150
          this.animateWalkingDown()
          this.lastAnimation = 'down'
        }
      } else {
        if (this.lastAnimation == 'up') {
          this.frame = 12
        } else if (this.lastAnimation == 'down') {
          this.frame = 0
        } else if (this.lastAnimation == 'left') {
          this.frame = 4
        } else {
          this.frame = 8
        }
      }
    }
  }

  update () {
    this.followPlayer()
    this.attack()
  }

  closeEnoughToPlayerToMelee () {
    let maxDistance = Math.min(Math.max(10 * this.difficulty, 10), 64) // pixel value
    let dx = Math.abs(this.game.player.x - this.x)
    let dy = Math.abs(this.game.player.y - this.y)
    if ((dy < maxDistance) && (dx < maxDistance)) {
      return true
    } else {
      return false
    }
  }

  // does all attacks from enemy to player
  // sets a cooldown timer for melee or other attack
  attack (direction) {
    if (!this.attacking) {
      this.attacking = true
      if (this.meleeCooldown === 0 && this.closeEnoughToPlayerToMelee()) {
        // do melee attack

        this.animating = true
        this.animateAttacking()

        combat.handleAttackOnPlayer(this.game.player, this)
        this.meleeCooldown = this.meleeTime
        this.cooldown('meleeCooldown')
        setTimeout(() => {
          this.attacking = false
        }, 1000)
      } else {
          // do other attack
        this.otherAttack()
        setTimeout(() => {
          this.attacking = false
        }, 1000)
      }
    }
  }
}
