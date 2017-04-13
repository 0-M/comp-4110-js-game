import Phaser from 'phaser'
import config from '../config'
//import { health } from 'health'
//import { levelXP } from 'levelXP'

class PauseScreen{
    constructor(){
      this.pauseBanner = "Paused"
      this.pauseText
    }
    displayPauseScreen( game ){
      this.pauseText = game.add.text(game.width/2, game.height/2, this.pauseBanner, {font: "24px Bangers", fill: "#fff"})
      //pauseText.font = "24px Bangers"
      //pauseText.fill = "#fff"
    }
    removePauseScreen( game ){
      this.pauseText.destroy()
    }
}
export let pause = new PauseScreen() // singleton