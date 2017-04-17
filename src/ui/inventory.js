import Phaser from 'phaser'
import Consumable from './item'
import Weapon from './item'
import Shield from './item'
import Item from './item'

export class Inventory {
  constructor ({inven_size}) {
    var inven_size
    var inventory // array of Items
    this.inven_size = inven_size // amount of inventory spaces
  }

  equip (in_inven, equipped) { // removes equipped and puts in inventory, put in_inven onto the player

  }

  remove (item_to_rem) {

  }
}
