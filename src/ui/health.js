import config from '../config'

class Health {
  constructor () {
    this.value = 100
    this.maxHealth = 100
    this.armor = 0
  }

  addHealthToLevel (game) {
    var style = { font: '16px Arial',
      fill: '#fff',
      align: 'center', // the alignment of the text is independent of the bounds, try changing to 'center' or 'right'
      boundsAlignH: 'right',
      boundsAlignV: 'bottom',
      wordWrap: true,
      wordWrapWidth: 300
    }

    this.text = game.add.text(600, 400, 'health: ' + this.value + ' / ' + this.maxHealth, style)
    this.text.boundsAlignH = 'right'
    this.text.boundsAlignV = 'bottom'

    this.text.setTextBounds(config.padding, config.padding, game.width - config.padding, game.height - config.padding)
  }
}

export let health = new Health() // singleton
