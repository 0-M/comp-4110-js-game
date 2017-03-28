import Phaser from 'phaser'

export default class extends Phaser.Sprite {
  constructor ({ game, x, y, asset}) {
    super(game, x, y, asset)
    this.anchor.setTo(0.5)
    this.cursors = game.input.keyboard.createCursorKeys()
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
    /* var dx = 0
    var dy = 0 */
    this.body.velocity.x = 0
    this.body.velocity.y = 0

    if (this.cursors.up.isDown) {
      this.body.velocity.y = -100
      this.animateWalkingUp()
    }
    if (this.cursors.down.isDown) {
      this.body.velocity.y = 100
      this.animateWalkingDown()
    }
    if (this.cursors.left.isDown) {
      this.body.velocity.x = -100
      this.animateWalkingLeft()
    }
    if (this.cursors.right.isDown) {
      this.body.velocity.x = 100
      this.animateWalkingRight()
    } /*
      if ((dx !== 0) || (dy !== 0)) {
        this.animating = true
        this.tileX += dx
        this.tileY += dy
        this.currentTween = this.game.add.tween(this).to(
          {
            x: this.tileX * this.game.tileWidth,
            y: this.tileY * this.game.tileWidth
          },
          300, // ms
          Phaser.Easing.Linear.None,
          true
        )
        this.currentTween.onComplete.addOnce(this.finishAnimating, this)
      }
    } */
  }
}
