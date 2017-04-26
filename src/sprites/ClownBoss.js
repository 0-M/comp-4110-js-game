import { Enemy } from './Enemy'

export class ClownBoss extends Enemy {

  constructor (game, asset, tileX, tileY) {

    super(game, asset, tileX, tileY, 5, 'clownBoss')
    this.attackAnimSpeed = 20   // Frames per second
    this.attackDuration = 1000  // Milliseconds

    this.walkSpeed = 150
    this.walkAnimSpeed = this.walkSpeed / 16.6

    this.deathAnimSpeed = 12
    this.deathDuration = 4416

    this.animations.add('attack', [16,16,16,17,17,17,18,19,20,21,22,23,24,25,16])
    this.animations.add('die', [0,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77])

    this.killedSound = game.add.audio('clownBoss_death_sound')
    this.killedSound.volume = 2.0
    this.attackSound = game.add.audio('claw_slash')
    this.attackSound.volume = 0.1

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
