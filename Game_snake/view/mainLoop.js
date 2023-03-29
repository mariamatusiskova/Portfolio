var speed = 7;
var countFood = 0;
var stopGame = false;
var stopGameBody = false;
var grow = 0;
var snakeLength = 3;
var color = 0;

const colorsDark = ['orange', 'red', 'teal', 'yellow', 'white', 'brown', 'black', 'green'];
const colorsBright = ['coral', 'crimson', '	darkturquoise', 'beige', 'ghostwhite', 'burlywood', 'grey', 'green'];

function mainLoop() {

    if (end) {
        return;
    }

    if (stopSnake) {
        return;
    }
    
    snake.moveSnake();

    console.log(snake.getPosition().x);
    console.log(snake.getPosition().y);

    stopGame = snake.checkBorder();
    stopGameBody = snake.checkBody();

    if (stopGame || stopGameBody) {
        gameOverSound.play();
        setTimeout(function() {gameOver.drawGameOver(canvas)}, 500);
        score.innerHTML = 0;
        exitScreenGameOver = 1;
       // btnScore.setTop(countFood);
        btnScore.setBestScore(Math.max(countFood, btnScore.getBestScore()));
        localStorage.setItem(btnScore.getTop(), btnScore.getBestScore());
        //countFood = 0;
        grow = 1;
        return;
    }

    board.drawBackground(canvas);
    snake.drawSnake(canvas);
    food.drawFood(canvas);

    if (snake.getPosition().x == food.getPosition().x && snake.getPosition().y == food.getPosition().y) {
        foodSound.play();
        countFood += 10;
        score.innerHTML = countFood;
        node.changeColor();
        food.randomFood();
        snakeLength++;
        color = 1;
    }

    setTimeout(mainLoop, 1000/level.getSpeed());
}
