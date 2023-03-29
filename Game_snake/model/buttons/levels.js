class Level {
    
    constructor() {
        this.speed = 7;  
    }

    isInButton(posX,posY) {

        if (posX > this.position.x && posX < (this.position.x + this.proportions.width) && posY < (this.position.y + this.proportions.height) && posY > this.position.y) {
            return true;
        }
        else {
            return false;
        }
    }

    clearCanvas(canvas) {
        ctx.clearRect(0, 0, canvas.width, canvas.height);
    }

    getSpeed() {
        return this.speed;
    }

    setSpeed(newSpeed) {
        this.speed = newSpeed;
    }
}