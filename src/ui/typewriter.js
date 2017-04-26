// ADAPTED FROM https://github.com/netgfx/Phaser-typewriter

import Phaser from 'phaser'

export class Typewriter {
  init (gameInstance, options) {
    this.game = gameInstance
    this.time = options.time || Phaser.Timer.SECOND / 10
    this.sound = options.sound || null
    this.soundMarker = options.soundMarker || null
    this.writerFn = options.writerFn || null
    this.endFn = options.endFn || null
    this.times = options.times || 10
    this.text = options.text || ''
    this.x = options.x || 100
    this.y = options.y || 100
    this.maxWidth = options.maxWidth || 200
    this.fontFamily = options.fontFamily || 'blackFont'
    this.fontSize = options.fontSize || 28
    this.writerObj = options.writerObj || null
  }

  start () {
    this.stop()
    this.enableTypingSpecificMessage(this.text, this.x, this.y)
  }

  stop () {
    if (this.timer !== undefined) {
      this.timer.stop()
      this.game.time.events.remove(this.timer)
    }
    if (this.sound !== null) {
      this.sound.stop()
    }
        // if(this.typedText !== undefined){ // This can cause problems if you repeatedly type to a text object. ~Tilde
        //    this.typedText.destroy();
        // }
  }

  enableTypingSpecificMessage (text, x, y) {
    if (this.writerObj === null) {
      var style = { font: '16px Rock Salt',
        fill: '#fff',
        align: 'left', // the alignment of the text is independent of the bounds, try changing to 'center' or 'right'
        wordWrap: true,
        wordWrapWidth: 300
      }
      this.typedText = this.game.add.text(x, y, text, style)
    } else {
      this.typedText = this.writerObj
    }
    this.typedText.maxWidth = this.maxWidth
    this.currentLetter = 0
    var length = this.typedText.children.length

    for (var i = 0; i < length; i++) {
      var letter = this.typedText.getChildAt(i)
      letter.alpha = 0
    }

    if (this.sound !== null) { // Made some alterations for sound markers here. ~Tilde
      if (this.soundMarker !== null) { this.sound.play(this.soundMarker, null, 1, true, true) } else { this.sound.play('', null, 1, true, true) }
    }

    this.typedText.x = x
    this.typedText.y = y
    if (this.endFn !== null) {
      this.countdown(this.typeWriter, length, this.endFn)
    } else {
      this.countdown(this.typeWriter, length)
    }
  }

    /**
     * [countDown description]
     * @param  {Function} fn    [description]
     * @param  {[type]}   endFn [description]
     * @return {[type]}         [description]
     */
  countdown (fn, times, endFn) {
    var _timer = this.game.time.create(false)
    _timer.start()
    endFn = endFn || function () {
      this.game.time.events.remove(_timer)
      if (this.sound !== null) {
        this.sound.stop()
      }
    }
    _timer.onComplete.add(endFn)
    _timer.repeat(this.time, times, fn, this)
    this.timer = _timer
  }

  typeWriter (text) {
    if (this.sound !== null) {
      if (this.sound.isPlaying === false) {
        this.sound.play()
      }
    }
    var letter = this.typedText.getChildAt(this.currentLetter)
    letter.alpha = 1
    this.currentLetter++
  }

  destroy () {
    this.typedText.destroy()
  }
  hideText () {
    this.typedText.visible = false
  }
  showText () {
    this.typedText.visible = true
  }
  moveToTop () {
    this.game.bringToTop(this.typedText)
  }
}
