var canvas, ctx;
var p1 = new warriorClass();

window.onload = function() {

        canvas = document.getElementById('gameCanvas'); // Get canvas; its width and height.
        ctx = canvas.getContext('2d');                  // Get the graphics buffer. Where we can draw graphics.

        colorRect(0,0, canvas.width,canvas.height, 'black');
        colorText("LOADING IMAGES", canvas.width/2,canvas.height/2, 'white');

        loadImages();
}

function imageLoadingDoneSoStartGame() {

        var framesPerSecond = 30;
        setInterval(updateAll, 1000/framesPerSecond);

        setupControls();
        loadLevel(levelOne);

}

function loadLevel(whichLevel) {

        roomGrid = whichLevel.slice();
        p1.reset(playerPic, "Blue Knight");

}

function updateAll() {

        moveAll();
        drawAll();

}


function moveAll() {

        p1.move();

}

function drawAll() {

        drawRoom();
        p1.draw();

}
