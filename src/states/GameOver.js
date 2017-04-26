import Phaser from 'phaser'
import {health} from '../ui/health'

export default class extends Phaser.State {
  init () {}

  preload () {
    this.game.load.image('retry', 'assets/images/menu_retry.png')
  }

  create () {
    // The stuff before here is behind the background, and wont be seen
    this.game.add.tileSprite(0, 0, 800, 600, 'background')
    this.game.add.button(350, 300, 'retry', this.actionOnClick, this, 0, 0, 0)

    this.tileWidth = 64

    this.game_start_sound = this.game.add.audio('gamestart_sound')

    this.soundtrack = this.game.add.audio('gameover_music')
    this.soundtrack.volume = 0.2
    this.soundtrack.loop = true
    this.soundtrack.play()

  }

  actionOnClick () {
    this.soundtrack.stop()
    this.game_start_sound.play()
    health.reset()

    this.game.state.start(this.game.currentLevel)
  }
}
