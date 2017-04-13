import Phaser from 'phaser'

export default class extends Phaser.Sprite {
  constructor ({game, x, y, asset}) {
    super(game, x, y, asset)
    this.anchor.setTo(0.5)
    this.cursors = game.input.keyboard.addKeys( { 'up': Phaser.KeyCode.W, 'down': Phaser.KeyCode.S, 'left': Phaser.KeyCode.A, 'right': Phaser.KeyCode.D } );
    //this.cursors = game.input.keyboard.createCursorKeys()
    this.animating = false
    game.physics.arcade.enable(this)
    game.camera.follow(this)
    this.animations.add('upwalk', [12, 13, 14, 15])
    this.animations.add('leftwalk', [4, 5, 6, 7])
    this.animations.add('rightwalk', [8, 9, 10, 11])
    this.animations.add('downwalk', [0, 1, 2, 3])
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

    if (this.cursors.up.isDown) {
      this.body.velocity.y = -150
      this.animateWalkingUp()
    }
    if (this.cursors.down.isDown) {
      this.body.velocity.y = 150
      this.animateWalkingDown()
    }
    if (this.cursors.left.isDown) {
      this.body.velocity.x = -150
      this.animateWalkingLeft()
    }
    if (this.cursors.right.isDown) {
      this.body.velocity.x = 150
      this.animateWalkingRight()
    }
  }
}
