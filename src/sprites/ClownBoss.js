import { Enemy } from './Enemy'

export class ClownBoss extends Enemy {

  constructor (game, asset, tileX, tileY) {

    super(game, asset, tileX, tileY, 5, 'clownBoss')
    this.attackAnimSpeed = 20   // Frames per second
    this.attackDuration = 1000  // Milliseconds

    this.walkSpeed = 150
    this.walkAnimSpeed = this.walkSpeed / 16.6

    this.animations.add('attack', [16,16,16,17,17,17,18,19,20,21,22,23,24,25,16])

  }

  animateAttacking () {
    this.animations.play('attack', this.attackAnimSpeed, false)
    this.lastAnimation = 'down'
    setTimeout(() => {this.setAnimatingFalse()}, this.attackDuration);
  }

  otherAttack () {
    console.log('other attack from ClownBoss!!!!!')
  }

}
