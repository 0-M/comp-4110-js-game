import { Enemy } from './Enemy'

export class FatClown extends Enemy {

  constructor (game, asset, tileX, tileY) {

    super(game, asset, tileX, tileY, 5, 'fatClown')
    this.attackAnimSpeed = 20   // Frames per second
    this.attackDuration = 1000  // Milliseconds

    this.walkSpeed = 100
    this.walkAnimSpeed = this.walkSpeed / 16.6

    this.animations.add('attack', [16,16,17,17,18,18,19,19,   20,21,22,21,20,21,22,   23,23,24,24,25,25,26,26])
  }

  otherAttack () {
    console.log('other attack from FatClown!')
  }

  animateAttacking () {
    this.animations.play('attack', this.attackAnimSpeed, false)
    this.lastAnimation = 'down'
    setTimeout(() => {this.setAnimatingFalse()}, this.attackDuration);
  }
}
