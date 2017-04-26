import Phaser from 'phaser'

export default class extends Phaser.State {
  init () {
    this.continue = false
  }

  preload () {
    this.load.image('dark_story_bg', 'assets/images/story_background.jpg')
  }

  create () {
    this.game.currentLevel = 'Story1'
    this.soundtrack = this.game.add.audio('circus_melody')
    this.soundtrack.loop = true
    this.soundtrack.volume = 0.3
    this.soundtrack.play()

    this.game.add.tileSprite(0, 0, 800, 600, 'dark_story_bg')
    this.counter = 0
    this.currentText = ''
    this.storyText =
    [
      'Happy Birthda',
      '.',
      '.',
      '.',
      ' ',
      'oh dear. \n',
      'Your parents are gone. \n',
      'The clowns at your party have kidnapped your parents.\n',
      '\nFight the clowns to\n',
      'get your parents back!'
    ]

    var style = { font: '24px Rock Salt',
      fill: '#fff',
      align: 'center', // the alignment of the text is independent of the bounds, try changing to 'center' or 'right'
      wordWrap: true,
      wordWrapWidth: 566
    }

    this.typedText = this.game.add.text(100, 100, this.storyText, style)
    this.write()
  }

  write () {
    this.currentText = this.currentText += this.storyText[this.counter]
    this.typedText.text = this.currentText
    this.counter += 1
    if (this.counter < this.storyText.length) {
      setTimeout(() => {
        this.write()
      }, 2000)
    } else {
      setTimeout(() => {
        this.continue = true
      }, 3000)
    }
  }

  update () {
    if (this.continue) {
      this.soundtrack.stop()
      this.game.state.start('Level1')
    }
  }
}
