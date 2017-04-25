import Phaser from 'phaser'
import { inventory } from '../ui/inventory'
import {combat} from '../combat'

export default class extends Phaser.Sprite {
  constructor ({game, x, y, asset}) {
    super(game, x, y, asset)
    this.anchor.setTo(0.5)
    this.cursors = game.input.keyboard.addKeys({ 'up': Phaser.KeyCode.W,
      'down': Phaser.KeyCode.S,
      'left': Phaser.KeyCode.A,
      'right': Phaser.KeyCode.D,
      'attack': Phaser.KeyCode.SPACEBAR,
      'sword_attack': Phaser.KeyCode.C,
      'dodge': Phaser.KeyCode.Q,
      'raise_shield': Phaser.KeyCode.X })
    // this.cursors = game.input.keyboard.createCursorKeys()
    this.moving = false
    this.animating = false
    this.dodging = false
    this.dead = false
    this.shieldIsUp = false

    game.physics.arcade.enable(this)
    game.camera.follow(this)
    this.inv = inventory
    /** * Some ideas
      - When switching from inventory to active swap the x's and y's of the two items
      - Items might need an is visible -> talk to dan about how pause menu works
    ***/
    // var worn_weapon = new Weapon(game, x, y, asset, player, itemId, stats_flat, stats_per, is_worn, two_handed)
    // var worn_shield = new Shieldgame, x, y, asset, player, itemId, stats_flat, stats_per, is_worn, range)
    this.defense = 0
    this.meleeAttack = 25

    this.walkSpeed = 150
    this.walkAnimSpeed = 6    // Frames per second

    this.attackAnimSpeed = 12 // Frames per second
    this.attackDuration = 700 // Milliseconds

    this.dodgeSpeed = 400
    this.dodgeAnimSpeed = 20  // Frames per second
    this.dodgeDuration = 500  // Milliseconds

    this.dieAnimSpeed = 12    // Frames per second
    this.deathDuration = 5000 // Milliseconds

    this.lastAnimation = 'down'
    this.animations.add('upwalk', [12, 13, 14, 15])
    this.animations.add('leftwalk', [4, 5, 6, 7])
    this.animations.add('rightwalk', [8, 9, 10, 11])
    this.animations.add('downwalk', [0, 1, 2, 3])
    this.animations.add('upattack', [28, 29, 29, 30, 31, 31, 28])
    this.animations.add('leftattack', [24, 25, 25, 26, 27, 27, 24])
    this.animations.add('rightattack', [20, 21, 21, 22, 23, 23, 20])
    this.animations.add('downattack', [16, 17, 17, 18, 19, 19, 16])
    this.animations.add('updodge', [87, 88, 89, 90, 91, 89, 88, 13])
    this.animations.add('leftdodge', [82, 83, 84, 85, 86, 84, 83, 5])
    this.animations.add('rightdodge', [77, 78, 79, 80, 81, 79, 78, 9])
    this.animations.add('downdodge', [72, 73, 74, 75, 76, 74, 73, 1])
    this.animations.add('die', [0, 32, 32, 32, 33, 33, 33, 34, 34, 34, 35, 35, 35, 36, 36, 36, 37, 37, 37, 38, 38, 38, 39, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71])
    this.animations.add('swordattack', [94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104])

    this.dodgeSound = game.add.audio('swoosh')
    this.attackSound = game.add.audio('pillow_swing')
    this.shieldSound = game.add.audio('pillow_thud')
    this.deathSound = game.add.audio('death_sound')
    this.swordAttackSound = game.add.audio('sword_slash')
    this.swordAttackSound.volume = 0.5
  }

  update () {
    if (!this.moving) {
      this.body.velocity.x = 0
      this.body.velocity.y = 0
    }

    if (this.cursors.raise_shield.isUp) {
      this.shieldIsUp = false
    }

    if (!this.animating && !this.dead) {
      if (this.cursors.raise_shield.isDown) {
        this.frame = 92
        if (!this.shieldIsUp) {
          this.shieldSound.play()
          this.shieldIsUp = true
        }
      } else if (this.cursors.attack.isDown) {
        if (inventory.equippedWeapon) {
          if (inventory.equippedWeapon.name === 'sword') {
            this.animating = true
            this.swordAttackSound.play()
            this.handleSwordAttack()
          }
        } else {
          this.animating = true
          this.attackSound.play()
          this.handleAttacking()
        }
      } else if (this.cursors.dodge.isDown) {
        this.moving = true
        this.animating = true
        this.dodging = true
        this.dodgeSound.play()
        this.animateDodging()
      } else {
        if (this.cursors.up.isDown && this.cursors.right.isDown) {
          this.body.velocity.y = -this.getDiagVect()
          this.body.velocity.x = this.getDiagVect()
          this.animateWalkingUp()
          this.lastAnimation = 'up'
        } else if (this.cursors.up.isDown && this.cursors.left.isDown) {
          this.body.velocity.y = -this.getDiagVect()
          this.body.velocity.x = -this.getDiagVect()
          this.animateWalkingUp()
          this.lastAnimation = 'up'
        } else if (this.cursors.down.isDown && this.cursors.right.isDown) {
          this.body.velocity.y = this.getDiagVect()
          this.body.velocity.x = this.getDiagVect()
          this.animateWalkingDown()
          this.lastAnimation = 'down'
        } else if (this.cursors.down.isDown && this.cursors.left.isDown) {
          this.body.velocity.y = this.getDiagVect()
          this.body.velocity.x = -this.getDiagVect()
          this.animateWalkingDown()
          this.lastAnimation = 'down'
        } else if (this.cursors.up.isDown) {
          this.body.velocity.y = -this.walkSpeed
          this.animateWalkingUp()
          this.lastAnimation = 'up'
        } else if (this.cursors.down.isDown) {
          this.body.velocity.y = this.walkSpeed
          this.animateWalkingDown()
          this.lastAnimation = 'down'
        } else if (this.cursors.left.isDown) {
          this.body.velocity.x = -this.walkSpeed
          this.animateWalkingLeft()
          this.lastAnimation = 'left'
        } else if (this.cursors.right.isDown) {
          this.body.velocity.x = this.walkSpeed
          this.animateWalkingRight()
          this.lastAnimation = 'right'
        } else {
          if (this.lastAnimation === 'up') {
            this.frame = 12
          } else if (this.lastAnimation === 'down') {
            this.frame = 0
          } else if (this.lastAnimation === 'left') {
            this.frame = 4
          } else {
            this.frame = 8
          }
        }
      }
    }
  }

  getDiagVect () {
    return Math.sqrt(Math.pow(this.walkSpeed / 2, 2) * 2)
  }

/*******************************************************************************
        Animations.
*******************************************************************************/

  //
  // Walking
  //
  animateWalkingUp () {
    this.animations.play('upwalk', this.walkAnimSpeed, false)
  }
  animateWalkingDown () {
    this.animations.play('downwalk', this.walkAnimSpeed, false)
  }
  animateWalkingLeft () {
    this.animations.play('leftwalk', this.walkAnimSpeed, false)
  }
  animateWalkingRight () {
    this.animations.play('rightwalk', this.walkAnimSpeed, false)
  }

  //
  // Attacking
  //
  animateAttackingUp () {
    this.animations.play('upattack', this.attackAnimSpeed, false)
    setTimeout(() => { this.setAnimatingFalse() }, this.attackDuration)
  }
  animateAttackingDown () {
    this.animations.play('downattack', this.attackAnimSpeed, false)
    setTimeout(() => { this.setAnimatingFalse() }, this.attackDuration)
  }
  animateAttackingLeft () {
    this.animations.play('leftattack', this.attackAnimSpeed, false)
    setTimeout(() => { this.setAnimatingFalse() }, this.attackDuration)
  }
  animateAttackingRight () {
    this.animations.play('rightattack', this.attackAnimSpeed, false)
    setTimeout(() => { this.setAnimatingFalse() }, this.attackDuration)
  }
  handleAttacking () {
    if (this.lastAnimation === 'up') {
      combat.attackUp(this)
      this.animateAttackingUp()
    } else if (this.lastAnimation === 'down') {
      combat.attackDown(this)
      this.animateAttackingDown()
    } else if (this.lastAnimation === 'left') {
      combat.attackLeft(this)
      this.animateAttackingLeft()
    } else {
      combat.attackRight(this)
      this.animateAttackingRight()
    }
  }

  animateSwordAttack () {
    this.animations.play('swordattack', 16, false)
    combat.attackAround(this)
    setTimeout(() => { this.setAnimatingFalse() }, this.attackDuration)
  }
  handleSwordAttack () {
    this.animateSwordAttack()
  }

  //
  // Dodging
  //
  animateDodgingUp () {
    this.animations.play('updodge', this.dodgeAnimSpeed, false)
    setTimeout(() => { this.setFalse() }, this.dodgeDuration)
  }
  animateDodgingDown () {
    this.animations.play('downdodge', this.dodgeAnimSpeed, false)
    setTimeout(() => { this.setFalse() }, this.dodgeDuration)
  }
  animateDodgingLeft () {
    this.animations.play('leftdodge', this.dodgeAnimSpeed, false)
    setTimeout(() => { this.setFalse() }, this.dodgeDuration)
  }
  animateDodgingRight () {
    this.animations.play('rightdodge', this.dodgeAnimSpeed, false)
    setTimeout(() => { this.setFalse() }, this.dodgeDuration)
  }
  animateDodging () {
    if (this.lastAnimation === 'up') {
      this.body.velocity.y = -this.dodgeSpeed
      this.animateDodgingUp()
    } else if (this.lastAnimation === 'down') {
      this.body.velocity.y = this.dodgeSpeed
      this.animateDodgingDown()
    } else if (this.lastAnimation === 'left') {
      this.body.velocity.x = -this.dodgeSpeed
      this.animateDodgingLeft()
    } else {
      this.body.velocity.x = this.dodgeSpeed
      this.animateDodgingRight()
    }
  }

  //
  // Dying
  //
  animateDeath (callback) {
    if (this.animations.currentAnim) {
      this.animations.currentAnim.stop()
    }
    var currentState = this.game.state.current
    this.game.state.states[currentState].soundtrack.stop()
    this.deathSound.play()
    this.animations.play('die', this.dieAnimSpeed, false)
    setTimeout(() => {
      this.setAnimatingFalse()
      callback()
    }, this.deathDuration)
  }

  setAnimatingFalse () {
    this.animating = false
  }
  setMovingFalse () {
    this.moving = false
  }
  setFalse () {
    this.animating = false
    this.moving = false
    this.dodging = false
  }
}
