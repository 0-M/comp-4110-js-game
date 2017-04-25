import Phaser from 'phaser'

export class Item extends Phaser.Sprite {
  // stats_flat is an array to set stat_arr equivalent to - I hope that's how passing arrays works
  constructor ({game, x, y, asset, player, itemId, stats_flat, stats_per, consumable, equippable}) {
    super(game, x, y, asset)
    var item_id // may not be needed - just thought i'd put it in here
    var stat_arr_flat = [0, 0, 0] // [0] = health [1] = damage [2] = armor
    var stat_arr_per = [0, 0, 0]  // [0] = health [1] = damage [2] = armor - if we wanna do % increases

    // We'll use stat_arr for flat increases, we may want to use both because then we can have consumables with flat and percent increase
    // In SRS we said consume will be handled by inventory, may be changed later
    this.item_id = itemId
    this.stat_arr_flat = stats_flat
    this.stat_arr_per = stats_per
    this.consumable = consumable
    this.equippable = equippable

    // this.body.onCollide = new Phaser.Signal()
    // this.body.onCollide.add(this.collected, this)
  }

  collected () {
    console.log('Collected the swawrad!')
  }
}

export class Consumable extends Item {
  constructor ({game, x, y, asset, player, itemId, stats_flat, stats_per, dur}) {
    super(game, x, y, asset, player, itemId, stats_flat, stats_per)
    var duration
    this.duration = dur
  }
}

class Wearable extends Item {
  constructor ({game, x, y, asset, player, itemId, stats_flat, stats_per}) {
    super(game, x, y, asset, player, itemId, stats_flat, stats_per)
    var is_worn = false
    this.is_worn = is_worn
  }
}

export class Weapon extends Wearable {
  constructor ({game, x, y, asset, player, itemId, stats_flat, stats_per, is_worn, two_handed}) {
    super(game, x, y, asset, player, itemId, stats_flat, stats_per, is_worn)
    var two_handed
    this.two_handed = two_handed
  }
}

export class Shield extends Wearable {
  constructor ({game, x, y, asset, player, itemId, stats_flat, stats_per, is_worn, range}) {
    super(game, x, y, asset, player, itemId, stats_flat, stats_per, is_worn)
    var range
    this.range = range
  }
}
