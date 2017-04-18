import Phaser from 'phaser'
import { Inventory } from '../ui/inventory'

export default class extends Phaser.Sprite {
  constructor ({game, x, y, asset}) {
    super(game, x, y, asset)
    this.anchor.setTo(0.5)
    this.cursors = game.input.keyboard.addKeys({ 'up': Phaser.KeyCode.W, 'down': Phaser.KeyCode.S, 'left': Phaser.KeyCode.A, 'right': Phaser.KeyCode.D, 'attack': Phaser.KeyCode.SPACEBAR })
    // this.cursors = game.input.keyboard.createCursorKeys()
    this.animating = false
    game.physics.arcade.enable(this)
    game.camera.follow(this)
    var inv = new Inventory(5)
    this.inv = inv
    this.lastAnimation = 'down'
    this.animations.add('upwalk', [12, 13, 14, 15])
    this.animations.add('leftwalk', [4, 5, 6, 7])
    this.animations.add('rightwalk', [8, 9, 10, 11])
    this.animations.add('downwalk', [0, 1, 2, 3])
    this.animations.add('upattack', [28,29,30,31])
    this.animations.add('leftattack', [24,25,26,27])
    this.animations.add('rightattack', [20,21,22,23])
    this.animations.add('downattack', [16,17,18,19])
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
  animateAttackingUp () {
    this.animations.play('upattack', 12, false)
  }
  animateAttackingDown () {
    this.animations.play('downattack', 12, false)
  }
  animateAttackingLeft () {
    this.animations.play('leftattack', 12, false)
  }
  animateAttackingRight () {
    this.animations.play('rightattack', 12, false)
  }

  update () {
    this.body.velocity.x = 0
    this.body.velocity.y = 0

    if (this.cursors.up.isDown && this.cursors.right.isDown) {
      this.body.velocity.y = -106
      this.body.velocity.x = 106
      this.animateWalkingUp()
      this.lastAnimation = 'up'
    } else if (this.cursors.up.isDown && this.cursors.left.isDown) {
      this.body.velocity.y = -106
      this.body.velocity.x = -106
      this.animateWalkingUp()
      this.lastAnimation = 'up'
    } else if (this.cursors.down.isDown && this.cursors.right.isDown) {
      this.body.velocity.y = 106
      this.body.velocity.x = 106
      this.animateWalkingDown()
      this.lastAnimation = 'down'
    } else if (this.cursors.down.isDown && this.cursors.left.isDown) {
      this.body.velocity.y = 106
      this.body.velocity.x = -106
      this.animateWalkingDown()
      this.lastAnimation = 'down'
    } else if (this.cursors.up.isDown) {
      this.body.velocity.y = -150
      this.animateWalkingUp()
      this.lastAnimation = 'up'
    } else if (this.cursors.down.isDown) {
      this.body.velocity.y = 150
      this.animateWalkingDown()
      this.lastAnimation = 'down'
    } else if (this.cursors.left.isDown) {
      this.body.velocity.x = -150
      this.animateWalkingLeft()
      this.lastAnimation = 'left'
    } else if (this.cursors.right.isDown) {
      this.body.velocity.x = 150
      this.animateWalkingRight()
      this.lastAnimation = 'right'
    } else if (this.lastAnimation == 'up' && this.cursors.attack.isDown) {
      this.animateAttackingUp()
    } else if (this.lastAnimation == 'down' && this.cursors.attack.isDown) {
      this.animateAttackingDown()
    } else if (this.lastAnimation == 'left' && this.cursors.attack.isDown) {
      this.animateAttackingLeft()
    } else if (this.lastAnimation == 'right' && this.cursors.attack.isDown) {
      this.animateAttackingRight()
    } else {
      if (this.lastAnimation == 'up') {
        this.frame = 12
      }      else if (this.lastAnimation == 'down') {
        this.frame = 0
      }      else if (this.lastAnimation == 'left') {
        this.frame = 4
      }      else if (this.lastAnimation == 'right') {
        this.frame = 8
      }
    }


  }
}
