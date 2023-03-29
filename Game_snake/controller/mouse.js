// kod zo stranky: https://quick-adviser.com/how-do-you-make-a-button-inside-a-canvas/

function clickCanvas(event) {
    const rect = canvas.getBoundingClientRect();
    const x = event.clientX - rect.left;
    const y = event.clientY - rect.top;

    var checkMenu = btnMenu.isInButton(x,y);
    var checkSettings = btnSettings.isInButton(x,y);
    var checkScore = btnScore.isInButton(x,y);
    var checkHelp = btnHelp.isInButton(x,y);

    if (homeScreen == 1) {

        var checkEasy = btnEasy.isInButton(x,y);
        var checkMedium = btnMedium.isInButton(x,y);
        var checkHard = btnHard.isInButton(x,y);

        if (checkEasy == true) {
            stopSnake = false;
            end = false;
            btnEasy.clearCanvas(canvas);
            countFood = 0;
            pickLevel.play();
            snake.setPosition(0, canvas.height/2);
            snake.setShift(snake.getSpeed(), 0);
            level.setSpeed(7);
            mainLoop();
        } else if (checkMedium == true) {
            stopSnake = false;
            end = false;
            btnMedium.clearCanvas(canvas);
            countFood = 0;
            pickLevel.play();
            snake.setPosition(0, canvas.height/2);
            snake.setShift(snake.getSpeed(), 0);
            level.setSpeed(11);
            mainLoop();
        } else if (checkHard == true) {
            stopSnake = false;
            end = false;
            btnHard.clearCanvas(canvas);
            countFood = 0;
            snake.setPosition(0, canvas.height/2);
            snake.setShift(snake.getSpeed(), 0);
            pickLevel.play();
            level.setSpeed(15);
            mainLoop();
        }

        homeScreen = 0;

    }
    
    if (checkMenu == true) {
        end = true;
        btnMenu.drawMenu(canvas);
        exitScreenMenu = 1;
        exitScreen = 1;
    } else if (checkSettings == true) {
        end = true;
        btnSettings.drawSettings(canvas);
        exitScreenSettings = 1;
        exitScreen = 1;
    } else if (checkScore == true) {
        end = true;
        btnScore.drawScore(canvas);
        exitScreen = 1;
    } else if (checkHelp == true) {
        end = true;
        btnHelp.drawHelp(canvas);
        exitScreen = 1;
    }
    
    if (exitScreenMenu == 1) {

        var checkNewGame = btnNewGame.isInButton(x,y);
        var checkHow = btnHow.isInButton(x,y);

        if (checkNewGame == true) {
            end = false;
            countFood = 0;
            score.innerHTML = countFood;
            pickLevel.play();
            snake.setPosition(0, canvas.height/2);
            snake.setShift(snake.getSpeed(), 0);
            btnTryAgain.clearCanvas(canvas);
            exitScreenMenu = 0;
            mainLoop();
        } else if (checkHow == true) {
            exitScreenMenu = 0;
            btnHow.drawHow();
        }
    }

    if (exitScreenSettings == 1) {

        var checkResetScore = btnResetScore.isInButton(x,y);
        var checkSoundOn = btnSoundOn.isInButton(x,y);
        var checkSoundOff = btnSoundOff.isInButton(x,y);

        if (checkResetScore == true) {
            end = true;
            countFood = 0;
            score.innerHTML = countFood;
        } else if (checkSoundOn == true) {
            turnOn = 1;
            turnOff = 0;
            btnExit.clearCanvas(canvas);
            home.drawHome(canvas);
            btnSettings.drawSettings(canvas);
            btnSoundOn.unmuteSound();
            turnOnSound.play();
        } else if (checkSoundOff == true) {
            turnOff = 1;
            turnOn = 0;
            btnExit.clearCanvas(canvas);
            home.drawHome(canvas);
            btnSettings.drawSettings(canvas);
            btnSoundOff.muteSound();
        }
    }

    if (exitScreen == 1) {

        var checkExit = btnExit.isInButton(x,y);

        if (checkExit == true && exitScreen == 1) {
            end = true;
            btnExit.clearCanvas(canvas);
            exitScreenSettings = 0;
            exitScreenMenu = 0;
            exitScreen = 0;
            load();
        }
    }

    if (exitScreenGameOver == 1) {

        var checkTryAgain = btnTryAgain.isInButton(x,y);
        var checkExitGameOver = btnExitGameOver.isInButton(x,y);

        if (checkExitGameOver == true) {
            end = true;
            btnExitGameOver.clearCanvas(canvas);
            exitScreenGameOver = 0;
            load();
        } else if (checkTryAgain == true) {
            end = false;
            countFood = 0;
            score.innerHTML = countFood;
            snake.setPosition(0, canvas.height/2);
            snake.setShift(snake.getSpeed(), 0);
            btnTryAgain.clearCanvas(canvas);
            exitScreenGameOver = 0;
            score.innerHTML = 0;
            exitScreenGameOver = 1;
            grow = 1;
            mainLoop();
        }
    }
}
