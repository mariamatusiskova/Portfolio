class Food extends Base {
    constructor(Color, Size) {
        super(Color, Size);

        this.order = 0;

        this.position = {
            // pixel
            x: Math.floor(Math.random() * (canvas.width/this.size)) * this.size,
            y: Math.floor(Math.random() * (canvas.height/this.size)) * this.size
        };
    }

    drawFood(canvas) {
        var ctx = canvas.getContext("2d");

        if (color == 0) {

            ctx.beginPath();
            ctx.fillStyle = this.color;
            ctx.fillRect(this.position.x, this.position.y, this.size, this.size);
            ctx.stroke();
            ctx.closePath();
        }
        else {
            this.color = this.colorsDark[Math.floor(Math.random() * this.colorsDark.length)];
            if (this.color == snake.getColor()) {
                while (this.color == snake.getColor()) {
                    if (this.color == snake.getColor()) {
                        this.color = this.colorsDark[Math.floor(Math.random() * this.colorsDark.length)];
                    }
                }
            }
            var found = false;
            for (var i = 0; i < this.colorsDark.length && !found; i++) {
                if (this.colorsDark[i] === this.color) {
                    this.order = i;
                    found = true;
                    break;
                }
            }
            ctx.beginPath();
            ctx.fillStyle = this.color;
            ctx.fillRect(this.position.x, this.position.y, this.size, this.size);
            ctx.stroke();
            ctx.closePath();
            node.addObserver(snake);
            node.notifyObservers();
            color = 0;
        }
    }

    randomFood() {
        this.position.x = Math.floor(Math.random() * (canvas.width/this.size)) * this.size;
        this.position.y = Math.floor(Math.random() * (canvas.height/this.size)) * this.size;

        // check if food is not in the body of the snake
        if (this.position.x == snake.getPosition().x && this.position.y == snake.getPosition().y) {
            this.randomFood();
        }

        if (snake.getTail().some(snakeBody => snakeBody.x == this.position.x && snakeBody.y == this.position.y)) {
            this.randomFood();
        }
    }

}