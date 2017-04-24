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

    this.load.spritesheet('knight', 'assets/images/knighter.png', 32, 48) // What is this still doing here?
    this.load.spritesheet('clownBoss', 'assets/spritesheets/characters/enemy/monster_clown_48x87.png', 48, 87)
    this.load.spritesheet('fatClown', 'assets/spritesheets/characters/enemy/fat_clown_24x48.png', 24, 48)
    this.load.spritesheet('strongClown', 'assets/spritesheets/characters/enemy/strong_clown_28x49.png', 28, 49)
    this.load.spritesheet('skinnyClown', 'assets/spritesheets/characters/enemy/skinny_clown_24x48.png', 24, 48)
    this.load.spritesheet('player_sprite', 'assets/spritesheets/characters/player/kid_cotton_24x48.png', 24, 48)

    this.load.spritesheet('smelly_pizza', 'assets/spritesheets/items/consumables/smelly_pizza_15x18x6', 15, 18)
    this.load.image('pizza', 'assets/images/pizza-1.png')

    this.load.audio('swoosh', 'assets/audio/swoosh.wav')
    this.load.audio('pillow_thud', 'assets/audio/pillow_thud.wav')

    this.load.audio('water_hose', 'assets/audio/gardern_hose.wav')
    this.load.audio('punch_flurry', 'assets/audio/punch_flurry.wav')
    this.load.audio('monster_roar_bite', 'assets/audio/monster_roar_bite.wav')
    this.load.audio('claw_slash', 'assets/audio/claw_slash.wav')

    this.load.audio('game_over', 'assets/audio/game_over.wav')

  }

  create () {
    this.state.start('Game')
  }
}
