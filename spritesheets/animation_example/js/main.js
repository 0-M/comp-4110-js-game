var game = new Phaser.Game(200, 100, Phaser.AUTO, '', { preload: preload, create: create, update: update });

function preload() {

    game.load.spritesheet('cola', 'assets/cola_8x18x14.png', 8, 18);
    game.load.spritesheet('pizza', 'assets/smelly_pizza_15x18x6.png', 15, 18);
    game.load.spritesheet('player', 'assets/strong_clown_28x49.png', 28, 49);

}

var player;
var platforms;
var cursors;

var stars;
var score = 0;
var scoreText;

var lastAnimation = 'down';

var COLA_ANIM_SPEED = 10;
var PIZZA_ANIM_SPEED = 10;
var WALK_ANIM_SPEED = 10;
var WALK_SPEED = 150;

function create() {

    game.physics.startSystem(Phaser.Physics.ARCADE);

    // The player and its settings
    player = game.add.sprite(48, game.world.height/2, 'player');
    pizza = game.add.sprite(48, game.world.height/2, 'pizza');
    cola = game.add.sprite(48, (game.world.height/2)+24, 'cola');

    game.physics.arcade.enable(player);
    player.body.collideWorldBounds = true;

    //  Our four animations, walking left, right, up and down.
    player.animations.add('left', [4, 5, 6, 7], WALK_ANIM_SPEED, true);
    player.animations.add('right', [8, 9, 10, 11], WALK_ANIM_SPEED, true);
    player.animations.add('up', [12, 13, 14, 15], WALK_ANIM_SPEED, true);
    player.animations.add('down', [0, 1, 2, 3], WALK_ANIM_SPEED, true);
    pizza.animations.add('smell', [0, 1, 2, 3, 4, 5], PIZZA_ANIM_SPEED, true);
    cola.animations.add('rotate', [0,1,2,3,4,5,6,7,8,9,10,11,12,13], COLA_ANIM_SPEED, true);


    //  Our controls.
    cursors = game.input.keyboard.createCursorKeys();

}

function update() {

        pizza.animations.play('smell');
        cola.animations.play('rotate');

        //  Reset the players velocity (movement)
        player.body.velocity.x = 0;
        player.body.velocity.y = 0;

        if (cursors.left.isDown) {

                player.body.velocity.x = -WALK_SPEED;
                player.animations.play('left');
                lastAnimation = 'left';

        } else if (cursors.right.isDown) {

                player.body.velocity.x = WALK_SPEED;
                player.animations.play('right');
                lastAnimation = 'right';

        } else if (cursors.up.isDown) {

                player.body.velocity.y = -WALK_SPEED;
                player.animations.play('up');
                lastAnimation = 'up';

        } else if (cursors.down.isDown) {

                player.body.velocity.y = WALK_SPEED;
                player.animations.play('down');
                lastAnimation = 'down';

        } else {
                player.animations.stop();

                if (lastAnimation == 'left') {
                        player.frame = 4;
                } else if (lastAnimation == 'right') {
                        player.frame = 8;
                } else if (lastAnimation == 'up') {
                        player.frame = 12;
                } else if (lastAnimation == 'down') {
                        player.frame = 0;
                }
        }
}
