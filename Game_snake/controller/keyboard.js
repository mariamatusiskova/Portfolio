var keys = {};
var stopSnake = false;
var stopHelp = false;
var stopMenu = false;

// push 
function keyControls(event) {

    if(event.keyCode == 68) {
        rightPressed = true;
        end = false;
        right.play();
        snake.directionX(1);
    }
    else if(event.keyCode == 65) {
        leftPressed = true;
        end = false;
        left.play();
        snake.directionX(0);
    }

    if(event.keyCode == 83) {
        downPressed = true;
        end = false;
        down.play();
        snake.directionY(1);
        }
    else if(event.keyCode == 87) {
        upPressed = true;
        end = false;
        up.play();
        snake.directionY(0);
    }

    if (event.keyCode == 13) {
        upPressed = true;
        end = true;
        homeScreen = 1;
        snake.resetTail();
        score.innerHTML = 0;
        countFood = 0;
        load();
    }

    if (event.keyCode == 72) {
        if (!stopHelp) {
            stopHelp = true;
            end = true;
            btnHelp.drawHelp(canvas);
            exitScreen = 1;
        } else if (stopHelp) {
            stopHelp = false;
            end = true;
            btnExit.clearCanvas(canvas);
            exitScreenSettings = 0;
            exitScreenMenu = 0;
            exitScreen = 0;
            load();
        }
    }

    if (event.keyCode == 77) {
        if (!stopMenu) {
            stopMenu = true;
            end = true;
            btnMenu.drawMenu(canvas);
            exitScreenMenu = 1;
            exitScreen = 1;
        } else if (stopMenu) {
            stopMenu = false;
            end = true;
            btnExit.clearCanvas(canvas);
            exitScreenSettings = 0;
            exitScreenMenu = 0;
            exitScreen = 0;
            load();
        }
    }
    
    if (event.keyCode == 80) { 
        if (!stopSnake) {
            stopSnake = true;
          } else if (stopSnake) {
            stopSnake = false;
            mainLoop();
          }
    }

}

window.onkeyup = function(event) {
    keys[event.keyCode] = false;
};