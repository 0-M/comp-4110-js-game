import config from '../config'

class Health {
  constructor () {
    this.maxHealth = 2500
    this.value = this.maxHealth
    this.armor = 0
  }

  addHealthToLevel (game) {
    this.game = game
    game.health = this

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

  updateHealth (newVal) {
    this.value = Math.max(newVal, 0)
    this.text.text = 'health: ' + this.value + ' / ' + this.maxHealth
    if (this.value === 0) {
      this.death()
    }
  }

  death () {
    if (!this.game.player.dead) {
      this.game.player.dead = true
      this.game.player.animateDeath(() => {
        this.game.player.dead = false
        var currentState = this.game.state.current
        this.game.state.states[currentState].soundtrack.stop()
        this.game.state.start('GameOver')
      })
    }
  }

  reset () {
    this.updateHealth(this.maxHealth)
  }
}

export let health = new Health() // singleton
