import Phaser from 'phaser'

export default class extends Phaser.Sprite {
  constructor ({ game, x, y, asset, tileX, tileY }) {
    super(game, tileX * game.tileWidth, tileY * game.tileWidth, asset)
    this.anchor.setTo(0.5)
    this.cursors = game.input.keyboard.createCursorKeys()
    this.animating = false
    this.tileX = tileX
    this.tileY = tileY
    this.x = tileX * game.tileWidth
    this.y = tileY * game.tileWidth
    game.physics.enable(this, Phaser.Physics.ARCADE)
    game.camera.follow(this)
  }

  update () {
    /* var dx = 0
    var dy = 0 */
    this.body.velocity.x = 0
    this.body.velocity.y = 0

    if (this.cursors.up.isDown) {
      this.body.velocity.y = -100
        // this.animateWalkingDown()
    }
    if (this.cursors.down.isDown) {
      this.body.velocity.y = 100
        // this.animateWalkingDown()
    }
    if (this.cursors.left.isDown) {
      this.body.velocity.x = -100
        // this.animateWalkingLeft()
    }
    if (this.cursors.right.isDown) {
      this.body.velocity.x = 100
        // this.animateWalkingRight()
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
