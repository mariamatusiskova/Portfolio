class Snake extends Base {

    constructor(Color, Size, Speed) {
        super(Color, Size);

        this.speed = Speed;

        this.direction = {
            x: 0,
            y: 0
        };

        this.shift = {
            // snake will run immediately
            x: this.speed,
            y: 0
        };
        
        this.position = {
            x: 0,
            y: canvas.height/2
        };

        this.tail = [];
    }

    // drawing snake
    drawSnake(canvas) {
        var ctx = canvas.getContext("2d");

        if (grow == 0) {
            for (var j = 0; j < this.tail.length; j++) {
                if (this.tail[j] == null) {
                    return;
                }    
                ctx.fillStyle = this.colorsBright[this.order];
                ctx.fillRect(this.tail[j].x, this.tail[j].y, this.size, this.size);
            }
        }
        else {
            snakeLength = 3;
            grow = 0;
        }
       // grow(this.position.x, this.position.y); 

       ctx.beginPath();
       ctx.fillStyle = this.color;
       // canvas.height/2 is center of canvas
       ctx.fillRect(this.position.x, this.position.y, this.size, this.size);
       ctx.stroke();
       ctx.closePath();
    }

    // idk
    clearCanvas(canvas) {
        var ctx = canvas.getContext('2d');
        ctx.clearRect(0, 0, canvas.width, canvas.height);
    }

    // keyboard
    directionX(dir) {

        this.direction.x = dir;

        // right
        // if the snake is going to the left then it can't go to the right
        if (dir == 1 && this.shift.x != -this.speed) {
            this.shift.x = this.speed;
            this.shift.y = 0;
        }
        // left
        // if the snake is going to the right then it can't go to the left
        else if (this.shift.x != this.speed) {
            this.shift.x = -this.speed;
            this.shift.y = 0;
        }
    }

    directionY(dir) {

       this.direction.y = dir;

        // down
        // if the snake is going tp then it can't go down
        if (dir == 1 && this.shift.y != -this.speed) {
            this.shift.x = 0;
            this.shift.y = this.speed;
        }
        // up
        // if the snake is going down then it can't go up
        else if (this.shift.y != this.speed) {
            this.shift.x = 0;
            this.shift.y = -this.speed;
        }

    }

    moveSnake() {
        this.position.x += this.shift.x;
        this.position.y += this.shift.y;
    
        this.tail.push({ x: this.position.x, y: this.position.y});
        this.tail = this.tail.slice(-1 * snakeLength);
    }

    // check snake length, growing
    grow() {
        this.tail.forEach( snakeBody => 
            this.drawSnake()
        )
    }

    update(node) {

        this.color = node.color;
        this.order = node.order;
    }

    // check if snake didn't hit the wall
    //collisions
    checkBorder() {

        var stopSnake = false;

        if (this.position.x > (canvas.width - this.size)) {
            return stopSnake = true;
        } 

        if (this.position.x < 0) {
            return stopSnake = true;
        } 

        if (this.position.y > (canvas.height - this.size)) {
            return stopSnake = true;
        }

        if (this.position.y < 0) {
            return stopSnake = true;
        } 
        
        return stopSnake = false;
    }

    // check if snake didn't hit his body
     //collisions
    checkBody() {

        var stopSnakeBody = false;

        for(var i = 0; i < this.tail.length - 1; i++){

            if (this.tail[i] == null) {
                return false;
            }

            if(this.position.x == this.tail[i].x && this.position.y == this.tail[i].y){
                this.resetTail();
                return stopSnakeBody = true; 
            }
        }
    }

    resetTail() {
        for(var j = 0; j < this.tail.length; j++) {
            this.tail[j] = null;
        }
    }

    getShift() {
        return this.shift;
    }

    setShift(x, y) {
        this.shift.x = x;
        this.shift.y = y;
    }

    getSpeed() {
        return this.speed;
    }

    setSpeed(newSpeed) {
        this.speed = newSpeed;
    }

    getTail() {
        return this.tail;
    }

    setTail(newTail) {
        this.tail = newTail;
    }

    getColor() {
        return this.color;
    }

    setColor(newColor) {
        this.color = newColor;
    }

}