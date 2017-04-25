/*
import Phaser from 'phaser'
import Consumable from './item'
import Weapon from './item'
import Shield from './item'
import Item from './item'
*/

class Inventory {
  constructor () {
    this.space = 5 // amount of EMPTY inventory spaces
    this.inventory = []
    this.equippedWeapon = ''
  }

  pickupItem (itemObj) {
    if (this.space > 0) {
      this.inventory.push(itemObj)
      this.space -= 1
      console.log('added an item!!! ' + this.space)
      itemObj.x = 100 * (this.inventory.length)
      itemObj.y = 510
      itemObj.body.velocity.x = 0
      itemObj.body.velocity.y = 0
      itemObj.inputEnabled = true
      itemObj.events.onInputDown.add((sprite, pointer) => { this.useItem(sprite) }, this)
    } else {
      console.log("couldn't add an item! :(")
      itemObj.body.velocity.x = 0
      itemObj.body.velocity.y = 0
    }
  }

  useItem (itemObj) {
    if (itemObj.equippable) {
      if (itemObj.eqipped) {
        if (itemObj.type === 'weapon') {
          this.equippedWeapon = null
        }
        itemObj.selectionBox.destroy()
        itemObj.eqipped = false
      } else {
        if (itemObj.type === 'weapon') {
          this.equippedWeapon = itemObj
        }
        itemObj.eqipped = true
        itemObj.selectionBox = itemObj.game.add.sprite(
          itemObj.x + (itemObj.width / 2),
          itemObj.y + (itemObj.height / 2),
          'selectionBox'
        )
        itemObj.selectionBox.anchor.x = 0.5
        itemObj.selectionBox.anchor.y = 0.5
      }
    } else if (itemObj.consumable) {
      var i = this.inventory.indexOf(itemObj)
      this.inventory.splice(i, 1)
      if (itemObj.use) {
        itemObj.use()
      } else {
        console.log('object has no use()')
      }
      itemObj.kill()
      this.space += 1
      this.inventory.forEach(this.moveItem)
      console.log('used an item!!! ' + itemObj.item_id)
    } else {
      console.log('CANT USE THIS ITEM: must be equippable or consumable')
    }
  }

  removeItem (itemObj) {
    var i = this.inventory.indexOf(itemObj)
    this.inventory.splice(i, 1)
    itemObj.kill()
    this.space += 1
    this.inventory.forEach(this.moveItem)
    console.log('removed an item!!! ' + itemObj.item_id)
  }

  moveItem (itemObj, index) {
    itemObj.x = 100 * (index)
  }
}

export let inventory = new Inventory() // singleton
