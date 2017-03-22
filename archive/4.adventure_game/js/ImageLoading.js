var playerPic = document.createElement("img");
var tilePics = [];

var picsToLoad = 0;     // Set automatically based on imageList in loadImages().

function countLoadedImagesAndLaunchIfReady() {

        picsToLoad--;
        // console.log(picsToLoad);
        if (picsToLoad == 0) {
                imageLoadingDoneSoStartGame();
        }

}

function beginLoadingImage(imgVar, fileName) {

        imgVar.onload = countLoadedImagesAndLaunchIfReady;
        imgVar.src = "images/"+fileName;

}

function loadImageForWorldCode(worldCode, fileName) {

        tilePics[worldCode] = document.createElement("img");
        beginLoadingImage(tilePics[worldCode], fileName);

}

function loadImages() {

        var imageList = [
                {varName: playerPic, fileName: "warrior.png"},

                {tileType: TILE_GROUND, fileName: "world_ground.png"},
                {tileType: TILE_WALL, fileName: "world_wall.png"},
                {tileType: TILE_GOAL, fileName: "world_goal.png"},
                {tileType: TILE_KEY, fileName: "world_key.png"},
                {tileType: TILE_DOOR, fileName: "world_door.png"}
        ];

        picsToLoad = imageList.length;

        for (var i = 0; i < imageList.length; i++) {
                if(imageList[i].varName != undefined) {
                        beginLoadingImage(imageList[i].varName, imageList[i].fileName);
                } else {
                        loadImageForWorldCode(imageList[i].tileType, imageList[i].fileName);
                }
        }

}
