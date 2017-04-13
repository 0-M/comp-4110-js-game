const KEY_LEFT_ARROW = 37;
const KEY_UP_ARROW = 38;
const KEY_RIGHT_ARROW = 39;
const KEY_DOWN_ARROW = 40;

const KEY_W = 87;
const KEY_A = 65;
const KEY_S = 83;
const KEY_D = 68;

var mouseX = 0;
var mouseY = 0;

function setupControls() {

        canvas.addEventListener('mousemove', updateMousePos)

        document.addEventListener('keydown', keyPressed);
        document.addEventListener('keyup', keyReleased);

        p1.setupInput(KEY_W, KEY_D, KEY_S, KEY_A);

}

function updateMousePos(evt) {

        var rect = canvas.getBoundingClientRect();
        var root = document.documentElement;

        mouseX = evt.clientX - rect.left - root.scrollLeft;
        mouseY = evt.clientY - rect.top - root.scrollTop;

}

function setKeyHoldState(thisKey, thisPlayer, setTo) {

        // if(setTo) {
        //         console.log("Key " + thisKey.keyCode + " pressed");
        // } else {
        //         console.log("Key " + thisKey.keyCode + " released");
        // }

        if (thisKey.keyCode == thisPlayer.controlKeyForWest) {
                thisPlayer.keyHeld_West = setTo;
        }
        if (thisKey.keyCode == thisPlayer.controlKeyForEast) {
                thisPlayer.keyHeld_East = setTo;
        }
        if (thisKey.keyCode == thisPlayer.controlKeyForNorth) {
                thisPlayer.keyHeld_North = setTo;
        }
        if (thisKey.keyCode == thisPlayer.controlKeyForSouth) {
                thisPlayer.keyHeld_South = setTo;
        }

}

function keyPressed(evt) {

        setKeyHoldState(evt, p1, true);

}

function keyReleased(evt) {

        setKeyHoldState(evt, p1, false);

}
