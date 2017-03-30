const ROOM_COLS = 16;
const ROOM_ROWS = 12;
var levelOne = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 5, 0, 1, 1, 1, 1,
                1, 0, 4, 0, 4, 0, 1, 0, 2, 0, 1, 0, 1, 4, 4, 1,
                1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 5, 1, 5, 1, 1,
                1, 1, 1, 5, 1, 1, 1, 0, 4, 0, 1, 0, 0, 0, 1, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 0, 1, 1,
                1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1,
                1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 4, 0, 1, 1,
                1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1,
                1, 0, 5, 0, 5, 0, 5, 0, 3, 0, 1, 1, 1, 1, 1, 1,
                1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1];
var roomGrid = [];

const TILE_W = 50;
const TILE_H = 50;

const TILE_GROUND = 0;
const TILE_WALL   = 1;
const TILE_PLAYER = 2;
const TILE_GOAL   = 3;
const TILE_KEY    = 4;
const TILE_DOOR   = 5;

function returnTileAtColRow(col,row) {

        if (col >= 0 && col < ROOM_COLS &&
            row >= 0 && row < ROOM_ROWS) {
                var worldIndexUnderCoord = roomTileToIndex(col,row);
                 return roomGrid[worldIndexUnderCoord];
         } else {
                return TILE_WALL;
         }

}

function roomTileToIndex(col,row) {

        return col + ROOM_COLS * row ;

}

function getTileIndexAtPixelCoord(pixelX, pixelY) {

        var tileCol = pixelX / TILE_W;
        var tileRow = pixelY / TILE_H;

        tileCol = Math.floor(tileCol);
        tileRow = Math.floor(tileRow);

        // First check whether the tile coords fall within valid bounds.
        if (tileCol < 0 || tileCol >= ROOM_COLS ||
            tileRow < 0 || tileRow >= ROOM_ROWS) {
                document.getElementById("debugText").innerHTML = "out of bounds:"+pixelX+","+pixelY;
                return undefined;
        }

        var tileIndex = roomTileToIndex(tileCol, tileRow);
        return tileIndex;

}

function tileTypeHasTransparency(checkTileType) {

        return (checkTileType == TILE_GOAL ||
                checkTileType == TILE_KEY  ||
                checkTileType == TILE_DOOR);

}

function drawRoom() {

        var tileIndex = 0;
        var tileLeftEdgeX = 0;
        var tileTopEdgeY = 0

        for (var eachRow = 0; eachRow < ROOM_ROWS; eachRow++) { // Deal with one row at a time.

                tileLeftEdgeX = 0; // Resetting horizontal draw position for tiles to left edge.

                for (var eachCol = 0; eachCol < ROOM_COLS; eachCol++) { // Left to right in each row.

                        var tileTypeHere = roomGrid[tileIndex]; // Getting the tile code for this index.

                        if (tileTypeHasTransparency(tileTypeHere)) {
                                ctx.drawImage(tilePics[TILE_GROUND], tileLeftEdgeX, tileTopEdgeY);
                        }

                        ctx.drawImage(tilePics[tileTypeHere], tileLeftEdgeX,  tileTopEdgeY);

                        tileIndex++;
                        tileLeftEdgeX += TILE_W;

                } // end of for each col

                tileTopEdgeY += TILE_H;

        } // end of for each row

} // end of drawRoom().
