class ResetScore extends Settings {
    
    constructor(Color, Size) {
        super(Color, Size);

        this.position = {
            x: canvas.width/2 - this.imgResetScore.width/4,
            y: 220
        };

        this.proportions = {
            width: this.imgResetScore.width/2,
            height: this.imgResetScore.height/2
        };
    }

    drawReset() {
        ctx.drawImage(this.imgResetScore, this.position.x, this.position.y, this.proportions.width, this.proportions.height);
    }
}