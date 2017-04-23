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
    this.load.spritesheet('fatClown', 'spritesheets/characters/enemy/fat_clown_24x48.png', 24, 48)
    this.load.spritesheet('strongClown', 'spritesheets/characters/enemy/strong_clown_28x49.png', 28, 49)
    this.load.spritesheet('skinnyClown', 'spritesheets/characters/enemy/skinny_clown_24x48.png', 24, 48)

    this.load.spritesheet('player_sprite', 'spritesheets/characters/player/kid_cotton_24x48.png', 24, 48)

    this.load.image('pizza', 'assets/images/pizza-1.png')
  }

  create () {
    this.state.start('Game')
  }
}
