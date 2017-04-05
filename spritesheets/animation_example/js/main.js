var game = new Phaser.Game(300, 300, Phaser.AUTO, '', { preload: preload, create: create, update: update });

function preload() {

    game.load.spritesheet('cola', 'assets/items/consumables/cola_8x18x14.png', 8, 18);
    game.load.spritesheet('super_cola', 'assets/items/consumables/super_cola_6x18x12.png', 6, 18);
    game.load.spritesheet('pizza', 'assets/items/consumables/smelly_pizza_15x18x6.png', 15, 18);

    game.load.spritesheet('pink_chest', 'assets/items/chests/pink_chest_39x40x2.png', 39, 40);
    game.load.spritesheet('circus_chest', 'assets/items/chests/circus_chest_37x41x2.png', 37, 41);

    game.load.spritesheet('player', 'assets/characters/player/kid_cotton_24x48.png', 24, 48);

    game.load.spritesheet('fat_clown', 'assets/characters/enemy/fat_clown_24x48.png', 24, 48);
    game.load.spritesheet('skinny_clown', 'assets/characters/enemy/skinny_clown_24x48.png', 24, 48);
    game.load.spritesheet('strong_clown', 'assets/characters/enemy/strong_clown_28x49.png', 28, 49);
    game.load.spritesheet('monster_clown', 'assets/characters/enemy/monster_clown_48x87.png', 48, 87);

}

var player;
var platforms;
var cursors;

var stars;
var score = 0;
var scoreText;

var lastAnimation = 'down';

var COLA_ANIM_SPEED = 5;
var SUPER_COLA_ANIM_SPEED = 10;
var PIZZA_ANIM_SPEED = 10;
var WALK_ANIM_SPEED = 10;
var WALK_SPEED = 150;

function create() {
    game.physics.startSystem(Phaser.Physics.ARCADE);

    cola = game.add.sprite(0, 50, 'cola');
    super_cola = game.add.sprite(50, 50, 'super_cola');
    pizza = game.add.sprite(100, 50, 'pizza');

    pink_chest = game.add.sprite(0, 0, 'pink_chest');
    circus_chest = game.add.sprite(100, 0, 'circus_chest');

    player = game.add.sprite(48, game.world.height/2, 'player');
    fat_clown = game.add.sprite(0, 100, 'fat_clown');
    skinny_clown = game.add.sprite(100, 100, 'skinny_clown');
    strong_clown = game.add.sprite(0, 200, 'strong_clown');
    monster_clown = game.add.sprite(100, 200, 'monster_clown');

    game.physics.arcade.enable(player);
    player.body.collideWorldBounds = true;
    game.physics.arcade.enable(fat_clown);
    fat_clown.body.collideWorldBounds = true;
    game.physics.arcade.enable(skinny_clown);
    skinny_clown.body.collideWorldBounds = true;
    game.physics.arcade.enable(strong_clown);
    strong_clown.body.collideWorldBounds = true;
    game.physics.arcade.enable(monster_clown);
    monster_clown.body.collideWorldBounds = true;

    cola.animations.add('rotate', [0,1,2,3,4,5,6,7,8,9,10,11,12,13], COLA_ANIM_SPEED, true);
    super_cola.animations.add('rotate', [0,1,2,3,4,5,6,7,8,9,10,11], SUPER_COLA_ANIM_SPEED, true);
    pizza.animations.add('smell', [0, 1, 2, 3, 4, 5], PIZZA_ANIM_SPEED, true);

    player.animations.add('left', [4, 5, 6, 7], WALK_ANIM_SPEED, true);
    player.animations.add('right', [8, 9, 10, 11], WALK_ANIM_SPEED, true);
    player.animations.add('up', [12, 13, 14, 15], WALK_ANIM_SPEED, true);
    player.animations.add('down', [0, 1, 2, 3], WALK_ANIM_SPEED, true);

    fat_clown.animations.add('left', [4, 5, 6, 7], WALK_ANIM_SPEED, true);
    fat_clown.animations.add('right', [8, 9, 10, 11], WALK_ANIM_SPEED, true);
    fat_clown.animations.add('up', [12, 13, 14, 15], WALK_ANIM_SPEED, true);
    fat_clown.animations.add('down', [0, 1, 2, 3], WALK_ANIM_SPEED, true);

    skinny_clown.animations.add('left', [4, 5, 6, 7], WALK_ANIM_SPEED, true);
    skinny_clown.animations.add('right', [8, 9, 10, 11], WALK_ANIM_SPEED, true);
    skinny_clown.animations.add('up', [12, 13, 14, 15], WALK_ANIM_SPEED, true);
    skinny_clown.animations.add('down', [0, 1, 2, 3], WALK_ANIM_SPEED, true);

    strong_clown.animations.add('left', [4, 5, 6, 7], WALK_ANIM_SPEED, true);
    strong_clown.animations.add('right', [8, 9, 10, 11], WALK_ANIM_SPEED, true);
    strong_clown.animations.add('up', [12, 13, 14, 15], WALK_ANIM_SPEED, true);
    strong_clown.animations.add('down', [0, 1, 2, 3], WALK_ANIM_SPEED, true);

    monster_clown.animations.add('left', [4, 5, 6, 7], WALK_ANIM_SPEED, true);
    monster_clown.animations.add('right', [8, 9, 10, 11], WALK_ANIM_SPEED, true);
    monster_clown.animations.add('up', [12, 13, 14, 15], WALK_ANIM_SPEED, true);
    monster_clown.animations.add('down', [0, 1, 2, 3], WALK_ANIM_SPEED, true);

    pink_chest.animations.add('toggle', [0,1], 1, true);
    circus_chest.animations.add('toggle', [0,1], 1, true);

    cursors = game.input.keyboard.createCursorKeys();
}

function update() {
        cola.animations.play('rotate');
        super_cola.animations.play('rotate');
        pizza.animations.play('smell');

        pink_chest.animations.play('toggle');
        circus_chest.animations.play('toggle');

        player.body.velocity.x = 0;
        player.body.velocity.y = 0;

        fat_clown.body.velocity.x = 0;
        fat_clown.body.velocity.y = 0;

        skinny_clown.body.velocity.x = 0;
        skinny_clown.body.velocity.y = 0;

        strong_clown.body.velocity.x = 0;
        strong_clown.body.velocity.y = 0;

        monster_clown.body.velocity.x = 0;
        monster_clown.body.velocity.y = 0;

        if (cursors.left.isDown) {

                player.body.velocity.x = -WALK_SPEED;
                player.animations.play('left');
                lastAnimation = 'left';

                fat_clown.body.velocity.x = -WALK_SPEED;
                fat_clown.animations.play('left');

                skinny_clown.body.velocity.x = -WALK_SPEED;
                skinny_clown.animations.play('left');

                strong_clown.body.velocity.x = -WALK_SPEED;
                strong_clown.animations.play('left');

                monster_clown.body.velocity.x = -WALK_SPEED;
                monster_clown.animations.play('left');

        } else if (cursors.right.isDown) {

                player.body.velocity.x = WALK_SPEED;
                player.animations.play('right');
                lastAnimation = 'right';

                fat_clown.body.velocity.x = WALK_SPEED;
                fat_clown.animations.play('right');

                skinny_clown.body.velocity.x = WALK_SPEED;
                skinny_clown.animations.play('right');

                strong_clown.body.velocity.x = WALK_SPEED;
                strong_clown.animations.play('right');

                monster_clown.body.velocity.x = WALK_SPEED;
                monster_clown.animations.play('right');


        } else if (cursors.up.isDown) {

                player.body.velocity.y = -WALK_SPEED;
                player.animations.play('up');
                lastAnimation = 'up';

                fat_clown.body.velocity.y = -WALK_SPEED;
                fat_clown.animations.play('up');

                skinny_clown.body.velocity.y = -WALK_SPEED;
                skinny_clown.animations.play('up');

                strong_clown.body.velocity.y = -WALK_SPEED;
                strong_clown.animations.play('up');

                monster_clown.body.velocity.y = -WALK_SPEED;
                monster_clown.animations.play('up');

        } else if (cursors.down.isDown) {

                player.body.velocity.y = WALK_SPEED;
                player.animations.play('down');
                lastAnimation = 'down';

                fat_clown.body.velocity.y = WALK_SPEED;
                fat_clown.animations.play('down');

                skinny_clown.body.velocity.y = WALK_SPEED;
                skinny_clown.animations.play('down');

                strong_clown.body.velocity.y = WALK_SPEED;
                strong_clown.animations.play('down');

                monster_clown.body.velocity.y = WALK_SPEED;
                monster_clown.animations.play('down');

        } else {
                player.animations.stop();

                if (lastAnimation == 'left') {
                        player.frame = 4;
                        fat_clown.frame = 4;
                        skinny_clown.frame = 4;
                        strong_clown.frame = 4;
                        monster_clown.frame = 4;
                } else if (lastAnimation == 'right') {
                        player.frame = 8;
                        fat_clown.frame = 8;
                        skinny_clown.frame = 8;
                        strong_clown.frame = 8;
                        monster_clown.frame = 8;
                } else if (lastAnimation == 'up') {
                        player.frame = 12;
                        fat_clown.frame = 12;
                        skinny_clown.frame = 12;
                        strong_clown.frame = 12;
                        monster_clown.frame = 12;
                } else if (lastAnimation == 'down') {
                        player.frame = 0;
                        fat_clown.frame = 0;
                        skinny_clown.frame = 0;
                        strong_clown.frame = 0;
                        monster_clown.frame = 0;
                }
        }
}
