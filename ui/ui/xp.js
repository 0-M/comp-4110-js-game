import config from '../config'

class XP {
  constructor () {
    this.XP = 5
    this.XPToNextLevel = 20
    this.level = 0
  }

  addXPToLevel (game) {
    var style = { font: '16px Arial',
      fill: '#fff',
      align: 'center', // the alignment of the text is independent of the bounds, try changing to 'center' or 'right'
      boundsAlignH: 'right',
      boundsAlignV: 'bottom',
      wordWrap: true,
      wordWrapWidth: 300
    }

    this.text = game.add.text(200, 400, 'XP: ' + this.XP + ' / ' + this.XPToNextLevel + '\nLevel ' + this.level, style)
    this.text.boundsAlignH = 'right'
    this.text.boundsAlignV = 'bottom'

    this.text.setTextBounds(config.padding, config.padding, game.width - config.padding, game.height - config.padding)
  }

  increaseBy (inxp) {
    this.XP += inxp
    this.text.text = 'XP: ' + this.XP + ' / ' + this.XPToNextLevel + '\nLevel ' + this.level
  }
}

export let xp = new XP() // singleton
