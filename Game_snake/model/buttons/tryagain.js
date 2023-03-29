class Again extends Gameover {
    
    constructor(Color, Size) {
        super(Color, Size);

        this.position = {
            x: (canvas.width - this.imgTryAgain.width)/1.2,
            y: canvas.height/1.6
        };

        this.proportions = {
            width: this.imgTryAgain.width/2.2,
            height: this.imgTryAgain.height/2.2
        };
    }

    drawTryAgain() {
        ctx.drawImage(this.imgTryAgain, this.position.x, this.position.y, this.proportions.width, this.proportions.height);
    }
}