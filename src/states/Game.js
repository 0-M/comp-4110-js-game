/* globals __DEV__ */
import Phaser from 'phaser'
import Player from '../sprites/Player'
import Pizza from '../sprites/Pizza'

export default class extends Phaser.State {
  init () {}

  preload () {
    this.game.load.image('background', '/assets/images/menu_bg.png')
    this.game.load.image('newgame', '/assets/images/menu_new.png')
  }

  generateItems () {
    var locations = [1, 2, 3, 4, 5]
    var self = this
    locations.forEach(function (i) {
      var pizza = new Pizza({
        game: self.game,
        x: i * self.tileWidth,
        y: i * self.tileWidth,
        asset: 'pizza',
        player: self.player
      })
      self.add.existing(pizza)
    })
  }

  create () {
    /*
    const bannerText = 'Prototype 87 Game'
    let banner = this.add.text(this.world.centerX, this.game.height - 80, bannerText)
    banner.font = 'Bangers'
    banner.padding.set(10, 16)
    banner.fontSize = 40
    banner.fill = '#555555'
    banner.smoothed = false
    banner.anchor.setTo(0.5)
    this.game.banner = banner
    this.game.points = 0
    */

    // The stuff before here is behind the background, and wont be seen
    this.game.add.tileSprite(0, 0, 800, 600, 'background')
    var newgame = this.game.add.button(350, 300, 'newgame', this.actionOnClick, this, 0, 0, 0)

    this.tileWidth = 64
    // this.world.setBounds(0, 0, 4800, 4800)

    this.game.physics.startSystem(Phaser.Physics.ARCADE)

    this.game.player = new Player({
      game: this.game,
      x: this.game.world.centerX + 200,
      y: this.game.world.centerY,
      asset: 'player_sprite'
    })

    this.game.add.existing(this.game.player)
    this.soundtrack = game.add.audio('dungeon')
    this.soundtrack.volume = 0.3
    this.soundtrack.loop = true
    this.soundtrack.play()
    this.game_start_sound = game.add.audio('gamestart_sound')

    // uncomment to show pizza
    // this.generateItems()
  }

  render () {
    /*
    if (__DEV__) {
      this.game.debug.spriteInfo(this.game.player, 32, 32)
    }
    */
  }
  actionOnClick () {
    this.soundtrack.stop()
    this.game_start_sound.play()
    this.game.state.start('Level1')
  }
}
