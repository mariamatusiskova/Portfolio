class NewGame extends Menu {
    constructor(Color, Size) {
        super(Color, Size);

        this.position = {
            x: canvas.width/2 - this.imgNewGame.width/4, 
            y: 305
        };

        this.proportions = {
            width: this.imgNewGame.width/2,
            height: this.imgNewGame.height/2
        };
    }

    drawNewGame() {
        ctx.drawImage(this.imgNewGame, this.position.x, this.position.y, this.proportions.width, this.proportions.height);
    }
}