import Phaser from 'phaser'
import { centerGameObjects } from '../utils'

export default class extends Phaser.State {
  init () {}

  preload () {
    this.loaderBg = this.add.sprite(this.game.world.centerX, this.game.world.centerY, 'loaderBg')
    this.loaderBar = this.add.sprite(this.game.world.centerX, this.game.world.centerY, 'loaderBar')
    centerGameObjects([this.loaderBg, this.loaderBar])

    this.load.setPreloadSprite(this.loaderBar)
    //
    // load your assets
    //

    this.load.spritesheet('knight', 'assets/images/knighter.png', 32, 48)
    this.load.spritesheet('clownBoss', 'spritesheets/characters/enemy/monster_clown_48x87.png', 48, 87)
    this.load.spritesheet('player_sprite', 'assets/images/kid_cotton_24x48.png', 24, 48)
    this.load.image('pizza', 'assets/images/pizza-1.png')
  }

  create () {
    this.state.start('Game')
  }
}
