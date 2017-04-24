import Phaser from 'phaser'
import {health} from '../ui/health'

export default class extends Phaser.State {
  init () {}

  preload () {
    this.game.load.image('retry', '/assets/images/menu_retry.png')
  }

  create () {
    // The stuff before here is behind the background, and wont be seen
    this.game.add.tileSprite(0, 0, 800, 600, 'background')
    this.game.add.button(350, 300, 'retry', this.actionOnClick, this, 0, 0, 0)

    this.tileWidth = 64

    this.soundtrack = this.game.add.audio('game_over')
    this.soundtrack.volume = 0.1  // Was a little too loud.
    this.soundtrack.play()

    this.game_start_sound = this.game.add.audio('game_start')
  }

  actionOnClick () {
    this.soundtrack.stop()
    this.game_start_sound.play()
    health.reset()

    this.game.state.start(this.game.currentLevel)
  }
}
