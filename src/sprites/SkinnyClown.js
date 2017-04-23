import { Enemy } from './Enemy'

export class SkinnyClown extends Enemy {

  constructor (game, asset, tileX, tileY) {

    super(game, asset, tileX, tileY, 5, 'skinnyClown')
    this.attackAnimSpeed = 20   // Frames per second
    this.attackDuration = 1000  // Milliseconds

    this.animations.add('leftattack',  [16,17,18,19,20,16,17,18,19,20,16,17,18,19,20,16,17,18,19,20])
    this.animations.add('rightattack', [21,22,23,24,25,21,22,23,24,25,21,22,23,24,25,21,22,23,24,25])
    this.animations.add('downattack',  [32,33,34,35,36,32,33,34,35,36,32,33,34,35,36,32,33,34,35,36])
    this.animations.add('upattack',  [37,38,39,40,41,37,38,39,40,41,37,38,39,40,41,37,38,39,40,41])

  }

  animateAttacking(direction) {
    this.animations.play(direction + 'attack', this.attackAnimSpeed, false)
    setTimeout(() => {this.setAnimatingFalse()}, this.attackDuration);
  }

  otherAttack () {
    console.log('other attack from SkinnyClown!')
  }

}
