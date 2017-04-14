import { health } from './ui/health'

class Combat {
  handleAttackOnPlayer (player, attacker) {
        // these variable names need work
    var delta = attacker.damage - player.defense
    if (delta < 0) {
      delta = 0 // we don't want to add health
    }
    var newHealthVal = health.value - (delta)
    health.updateHealth(newHealthVal)
  }

  handleAttackOnNPC (player, npc) {
        // these variable names need work
    var newHealthVal = npc.health - (player.damage - npc.defense)
    npc.health = newHealthVal
  }
}

export let combat = new Combat()
