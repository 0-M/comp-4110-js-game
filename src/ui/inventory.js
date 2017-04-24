import Phaser from 'phaser'
import Consumable from './item'
import Weapon from './item'
import Shield from './item'
import Item from './item'

export class Inventory {
  constructor ({inven_size}) {
    var space
    var inventory // array of Items
    this.space = 5 // amount of EMPTY inventory spaces
    this.inventory = []
  }

  pickupItem (itemObj) {
    if(this.space > 0){
      this.inventory.push(itemObj)
      this.space -= 1
      console.log("added an item!!! "+this.space)
      itemObj.x = 100*(this.inventory.length)
      itemObj.y = 500
      itemObj.body.velocity.x = 0
      itemObj.body.velocity.y = 0
    }else{
      console.log("couldn't add an item! :(")
      itemObj.body.velocity.x = 0
      itemObj.body.velocity.y = 0
    }
  }
  
  useItem (itemObj) {
    var i = this.inventory.indexOf(itemObj)
    // if this is consume class, perform consume method here
    this.inventory.splice(i, 1)
    itemObj.destroy()
    this.space += 1
    this.inventory.forEach(moveItem)
    console.log("used an item!!! "+itemObj.item_id)
  }
  
  removeItem (itemObj) {
    var i = this.inventory.indexOf(itemObj)
    this.inventory.splice(i, 1)
    itemObj.destroy()
    this.space += 1
    this.inventory.forEach(moveItem)
    console.log("removed an item!!! "+itemObj.item_id)
  }
  
  moveItem (itemObj, index) {
    itemObj.x = 100*(index)
  }
}
