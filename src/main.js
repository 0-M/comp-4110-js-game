import 'pixi'
import 'p2'
import Phaser from 'phaser'

import BootState from './states/Boot'
import SplashState from './states/Splash'
import GameState from './states/Game'
import Story1 from './states/Story1'
import Level1 from './states/levels/Level1'
import Level3 from './states/levels/Level3'
import GameOver from './states/GameOver'

class Game extends Phaser.Game {
  constructor () {
    // const docElement = document.documentElement
    // const width = docElement.clientWidth > config.gameWidth ? config.gameWidth : docElement.clientWidth
    // const height = docElement.clientHeight > config.gameHeight ? config.gameHeight : docElement.clientHeight
    const width = 800
    const height = 600

    super(width, height, Phaser.CANVAS, 'content', null)

    this.state.add('Boot', BootState, false)
    this.state.add('Splash', SplashState, false)
    this.state.add('Game', GameState, false)
    this.state.add('Story1', Story1, false)
    this.state.add('Level1', Level1, false)
    this.state.add('Level3', Level3, false)
    this.state.add('GameOver', GameOver, false)

    this.state.start('Boot')
  }
}

window.game = new Game()
