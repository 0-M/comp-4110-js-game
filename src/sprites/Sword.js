import {Item} from '../ui/item'

/**
 *
 *     var sword = new Item({
      game: this.game,
      x: 150,
      y: 150,
      asset: 'basic-sword',
      player: this.player,
      itemId: 666,
      stats_flat: [0, 10000, 0],
      stats_per: [0, 0, 0],
      consumable: false,
      equippable: true
    })
 */

export class Sword extends Item {
  constructor ({game, x, y, player}) {
    super(
      {
        game: game,
        x: x,
        y: y,
        asset: 'basic-sword',
        player: player,
        itemId: 666,
        stats_flat: [0, 50, 0],
        stats_per: [0, 0, 0],
        consumable: false,
        equippable: true
      }
    )
    this.name = 'sword'
    this.type = 'weapon'
  }
}
