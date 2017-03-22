/* globals __DEV__ */
import Phaser from 'phaser'
import Player from '../sprites/Player'
import Pizza from '../sprites/Pizza'

export default class extends Phaser.State {
  init () {}
  preload () {}

  generateItems () {
    var locations = [1, 2, 3, 4, 5]
    var self = this
    locations.forEach(function (i) {
      var pizza = new Pizza({
        game: self,
        x: self.world.centerX,
        y: self.world.centerY,
        asset: 'pizza',
        tileX: i,
        tileY: i,
        player: self.player
      })
      self.add.existing(pizza)
    })
  }

  create () {
    const bannerText = 'Prototype 87 Game'
    let banner = this.add.text(this.world.centerX, this.game.height - 80, bannerText)
    banner.font = 'Bangers'
    banner.padding.set(10, 16)
    banner.fontSize = 40
    banner.fill = '#555555'
    banner.smoothed = false
    banner.anchor.setTo(0.5)
    this.banner = banner
    this.points = 0

    this.tileWidth = 64
    // this.world.setBounds(0, 0, 4800, 4800)

    this.physics.startSystem(Phaser.Physics.ARCADE)

    this.player = new Player({
      game: this,
      x: this.world.centerX,
      y: this.world.centerY,
      asset: 'player_sprite',
      tileX: 6,
      tileY: 4
    })

    this.game.add.existing(this.player)

    this.generateItems()
  }

  render () {
    if (__DEV__) {
      this.game.debug.spriteInfo(this.player, 32, 32)
    }
  }
}
