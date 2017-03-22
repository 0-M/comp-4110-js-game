const PLAYER_MOVE_SPEED = 10;

function warriorClass() {

        this.name = "Untitled Warrior";
        this.playerPic;
        this.x = 75;
        this.y = 75;
        this.keysHeld = 0;

        this.keyHeld_North = false;
        this.keyHeld_East = false;
        this.keyHeld_South = false;
        this.keyHeld_West = false;

        this.controlKeyForNorth;
        this.controlKeyForEast;
        this.controlKeyForSouth;
        this.controlKeyForWest;

        this.setupInput = function(northKey,eastKey,southKey,westKey) {
                this.controlKeyForNorth = northKey;
                this.controlKeyForEast  = eastKey;
                this.controlKeyForSouth = southKey;
                this.controlKeyForWest  = westKey;
        }

        this.reset = function(whichImage, whichWarriorName) {

                this.name = whichWarriorName;
                this.playerPic = whichImage;

                for (var eachRow=0; eachRow<ROOM_ROWS; eachRow++) {
                        for (var eachCol=0; eachCol<ROOM_COLS; eachCol++) {
                                var arrayIndex = roomTileToIndex(eachCol,eachRow);
                                if (roomGrid[arrayIndex] == TILE_PLAYER) {
                                        roomGrid[arrayIndex] = TILE_GROUND;
                                        this.x = eachCol * TILE_W + TILE_W/2;
                                        this.y = eachRow * TILE_H + TILE_H/2;
                                        return;
                                } // end of player start if
                        } // end of col for
                } // end of row for
                console.log("NO PLAYER START FOUND!");
        } // end of warriorReset func

        this.move = function() {

                var nextX = this.x;
                var nextY = this.y;

                var paddingX = 0;
                var paddingY = 0;

                if (this.keyHeld_North) {
                        nextY -= PLAYER_MOVE_SPEED;
                }
                if (this.keyHeld_East) {
                        nextX += PLAYER_MOVE_SPEED;
                        paddingX += 40;
                }
                if (this.keyHeld_South) {
                        nextY += PLAYER_MOVE_SPEED;
                        paddingY += 45;
                }
                if (this.keyHeld_West) {
                        nextX -= PLAYER_MOVE_SPEED;
                }

                var walkIntoTileIndex = getTileIndexAtPixelCoord(nextX+paddingX,nextY+paddingY);
                var walkIntoTileType = TILE_WALL;

                if (walkIntoTileIndex != undefined) {
                        walkIntoTileType = roomGrid[walkIntoTileIndex];
                }

                switch (walkIntoTileType) {
                        case TILE_GROUND:
                                this.x = nextX;
                                this.y = nextY;
                                break;
                        case TILE_GOAL:
                                document.getElementById("debugText").innerHTML = this.name+" won";
                                // this.reset(playerPic, "Blue Knight");
                                loadLevel(levelOne);
                                break;
                        case TILE_DOOR:
                                if (this.keysHeld > 0) {
                                        this.keysHeld--;
                                        document.getElementById("debugText").innerHTML = "Keys "+this.keysHeld;
                                        roomGrid[walkIntoTileIndex] = TILE_GROUND; // Remove door.
                                }
                                break;
                        case TILE_KEY:
                                this.keysHeld++;
                                document.getElementById("debugText").innerHTML = "Keys "+this.keysHeld;
                                roomGrid[walkIntoTileIndex] = TILE_GROUND; // Remove key.
                                break;
                        case TILE_WALL:
                        default:
                                break;
                }

        }

        this.draw = function() {

                ctx.drawImage(this.playerPic, this.x,this.y);

        }
}