class Base extends Node {
    constructor (Color, Size) {
        super();

        this.color = Color;
        this.size = Size;
        
    }

    randomColor(color){
        this.changeColor(color);
        this.notify("randomColor", color);
    }

    changeColor(color){}

    isInButton(posX,posY) {

        if (posX > this.position.x && posX < this.position.x + this.proportions.width && posY < this.position.y + this.proportions.height && posY > this.position.y) {
            return true;
        }
        else {
            return false;
        }
    }

    clearCanvas(canvas) {
        var ctx = canvas.getContext('2d');
        ctx.clearRect(0, 0, canvas.width, canvas.height);
    }

    getPosition() {
        return this.position;
    }

    setPosition(x, y) {
        this.position.x = x;
        this.position.y = y;
    }

    getSize() {
        return this.size;
    }

    setSize(newSize) {
        this.size = newSize;
    }

}

