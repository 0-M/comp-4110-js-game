import { health } from './ui/health'
import { inventory } from './ui/inventory'
import { xp } from './ui/xp'

class Combat {
  handleAttackOnPlayer (player, attacker) {
        // these variable names need work
    var delta = attacker.damage - player.defense
    if (delta < 0) {
      delta = 0 // we don't want to add health
    }
    if (player.shieldIsUp) {
      delta = Math.round(delta * 0.3) // 30% damage if shielding
    }
    var newHealthVal = health.value - (delta)
    health.updateHealth(newHealthVal)
  }

  handleAttackOnNPC (player, npc) {
    // these variable names need work
    var weaponMult = 1
    var weaponDmg = player.meleeAttack
    if (inventory.equippedWeapon) {
      weaponMult = 1 + inventory.equippedWeapon.stat_arr_per[1]
      weaponDmg = inventory.equippedWeapon.stat_arr_flat[1]
    }
    var newHealthVal = npc.health - ((weaponDmg * weaponMult) - npc.defense)
    newHealthVal = Math.max(newHealthVal, 0)
    npc.health = newHealthVal
    if (npc.health === 0) {
      xp.increaseBy(npc.difficulty)
      npc.playKilledSound()
      npc.destroy()
    }
  }

  attackLeft (player) {
    var currentState = player.game.state.current
    var enemies = player.game.state.states[currentState].enemies
    enemies.forEach((enemy) => {
      var dx = player.x - enemy.x
      var dy = Math.abs(enemy.y - player.y)
      if ((dy < 50) && (dx >= 0) && (dx < 50)) {
        this.handleAttackOnNPC(player, enemy)
      }
    })
  }

  attackRight (player) {
    var currentState = player.game.state.current
    var enemies = player.game.state.states[currentState].enemies
    enemies.forEach((enemy) => {
      var dx = enemy.x - player.x
      var dy = Math.abs(enemy.y - player.y)
      if ((dy < 50) && (dx >= 0) && (dx < 50)) {
        this.handleAttackOnNPC(player, enemy)
      }
    })
  }

  attackUp (player) {
    var currentState = player.game.state.current
    var enemies = player.game.state.states[currentState].enemies
    enemies.forEach((enemy) => {
      var dx = Math.abs(player.x - enemy.x)
      var dy = player.y - enemy.y
      if ((dx < 50) && (dy >= 0) && (dy < 50)) {
        this.handleAttackOnNPC(player, enemy)
      }
    })
  }

  attackDown (player) {
    var currentState = player.game.state.current
    var enemies = player.game.state.states[currentState].enemies
    enemies.forEach((enemy) => {
      var dx = Math.abs(player.x - enemy.x)
      var dy = enemy.y - player.y
      if ((dx < 50) && (dy >= 0) && (dy < 50)) {
        this.handleAttackOnNPC(player, enemy)
      }
    })
  }

  attackAround (player) {
    var currentState = player.game.state.current
    var enemies = player.game.state.states[currentState].enemies
    enemies.forEach((enemy) => {
      var dx = Math.abs(player.x - enemy.x)
      var dy = Math.abs(enemy.y - player.y)
      if ((dx < 50) && (dy < 50)) {
        this.handleAttackOnNPC(player, enemy)
      }
    })
  }
}

export let combat = new Combat()
