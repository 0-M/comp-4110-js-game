import { Enemy } from './Enemy'

export class ClownBoss extends Enemy {
  constructor (game, asset, tileX, tileY) {
    super(game, asset, tileX, tileY, 5, 'clownBoss')
  }

  otherAttack () {
    console.log('other attack from ClownBoss!!!!!')
  }
}
