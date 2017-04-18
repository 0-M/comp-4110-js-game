import Phaser from 'phaser'
import { Inventory } from '../ui/inventory'
import { Weapon } from '../ui/item'

var lastAnimation = 'down'

export default class extends Phaser.Sprite {
  constructor ({game, x, y, asset}) {
    super(game, x, y, asset)
    this.anchor.setTo(0.5)
    this.cursors = game.input.keyboard.addKeys({ 'up': Phaser.KeyCode.W, 'down': Phaser.KeyCode.S, 'left': Phaser.KeyCode.A, 'right': Phaser.KeyCode.D })
    // this.cursors = game.input.keyboard.createCursorKeys()
    this.animating = false
    game.physics.arcade.enable(this)
    game.camera.follow(this)
    var inv = new Inventory(5)
    /*** Some ioeas
      - When switching from inventory to active swap the x's and y's of the two items
      - Items might need an is visible -> talk to dan about how pause menu works
    ***/
    //var worn_weapon = new Weapon(game, x, y, asset, player, itemId, stats_flat, stats_per, is_worn, two_handed)
    //var worn_shield = new Shieldgame, x, y, asset, player, itemId, stats_flat, stats_per, is_worn, range)
    this.inv = inv
    this.animations.add('upwalk', [12, 13, 14, 15])
    this.animations.add('leftwalk', [4, 5, 6, 7])
    this.animations.add('rightwalk', [8, 9, 10, 11])
    this.animations.add('downwalk', [0, 1, 2, 3])
    this.defense = 0
  }

  animateWalkingUp () {
    this.animations.play('upwalk', 12, false)
  }
  animateWalkingDown () {
    this.animations.play('downwalk', 12, false)
  }
  animateWalkingLeft () {
    this.animations.play('leftwalk', 12, false)
  }
  animateWalkingRight () {
    this.animations.play('rightwalk', 12, false)
  }

  update () {
    this.body.velocity.x = 0
    this.body.velocity.y = 0

    if (this.cursors.up.isDown && this.cursors.right.isDown) {
      this.body.velocity.y = -106
      this.body.velocity.x = 106
      this.animateWalkingUp()
      lastAnimation = 'up'
    }    else if (this.cursors.up.isDown && this.cursors.left.isDown) {
      this.body.velocity.y = -106
      this.body.velocity.x = -106
      this.animateWalkingUp()
      lastAnimation = 'up'
    }    else if (this.cursors.down.isDown && this.cursors.right.isDown) {
      this.body.velocity.y = 106
      this.body.velocity.x = 106
      this.animateWalkingDown()
      lastAnimation = 'down'
    }    else if (this.cursors.down.isDown && this.cursors.left.isDown) {
      this.body.velocity.y = 106
      this.body.velocity.x = -106
      this.animateWalkingDown()
      lastAnimation = 'down'
    }    else if (this.cursors.up.isDown) {
      this.body.velocity.y = -150
      this.animateWalkingUp()
      lastAnimation = 'up'
    }    else if (this.cursors.down.isDown) {
      this.body.velocity.y = 150
      this.animateWalkingDown()
      lastAnimation = 'down'
    }    else if (this.cursors.left.isDown) {
      this.body.velocity.x = -150
      this.animateWalkingLeft()
      lastAnimation = 'left'
    }    else if (this.cursors.right.isDown) {
      this.body.velocity.x = 150
      this.animateWalkingRight()
      lastAnimation = 'right'
    }    else {
      if (lastAnimation == 'up') {
        this.frame = 12
      }      else if (lastAnimation == 'down') {
        this.frame = 0
      }      else if (lastAnimation == 'left') {
        this.frame = 4
      }      else if (lastAnimation == 'right') {
        this.frame = 8
      }
    }
  }
}
