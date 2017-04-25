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
    this.load.image('selectionBox', 'assets/images/inv_sel_box.png')
    this.load.image('pizza', 'assets/images/pizza-1.png')
    this.load.spritesheet('knight', 'assets/images/knighter.png', 32, 48) // What is this still doing here?

    // Characters
    this.load.spritesheet('clownBoss', 'assets/spritesheets/characters/enemy/monster_clown_48x87.png', 48, 87)
    this.load.spritesheet('fatClown', 'assets/spritesheets/characters/enemy/fat_clown_24x48.png', 24, 48)
    this.load.spritesheet('strongClown', 'assets/spritesheets/characters/enemy/strong_clown_28x49.png', 28, 49)
    this.load.spritesheet('skinnyClown', 'assets/spritesheets/characters/enemy/skinny_clown_24x48.png', 24, 48)
    this.load.spritesheet('player_sprite', 'assets/spritesheets/characters/player/kid_cotton_24x48.png', 24, 48)

    // Items
    this.load.spritesheet('smelly_pizza', 'assets/spritesheets/items/consumables/smelly_pizza_15x18x6.png', 15, 18)
    this.load.spritesheet('cola', 'assets/spritesheets/items/consumables/cola_8x18x14.png', 8, 18)
    this.load.spritesheet('super_cola', 'assets/spritesheets/items/consumables/super_cola_6x18x12.png', 6, 18)

    // Audio

    // Sounds
    this.load.audio('swoosh', 'assets/audio/swoosh.wav')
    this.load.audio('pillow_swing', 'assets/audio/pillow_swing.wav')
    this.load.audio('pillow_thud', 'assets/audio/pillow_thud.wav')
    this.load.audio('water_hose', 'assets/audio/gardern_hose.wav')
    this.load.audio('punch_flurry', 'assets/audio/punch_flurry.wav')
    this.load.audio('monster_roar_bite', 'assets/audio/monster_roar_bite.wav')
    this.load.audio('claw_slash', 'assets/audio/claw_slash.wav')
    this.load.audio('sword_slash', 'assets/audio/sword_slash.wav')

    this.load.audio('gamestart_sound', '/assets/audio/gamestart_sound.wav')
    this.load.audio('death_sound', 'assets/audio/death_sound.wav')

    // Soundtracks
    this.load.audio('intro_music', '/assets/audio/intro_music.wav')
    this.load.audio('circus_melody', 'assets/audio/circus_melody.wav')
    this.load.audio('gameover_music', 'assets/audio/gameover_music.wav')
  }

  create () {
    this.state.start('Game')
  }
}
