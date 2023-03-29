class Background extends Base {

    constructor(Color, Size) {
        super(Color, Size);

    }

    drawBackground(canvas) {
        ctx.fillStyle = "grey";
        ctx.fillRect(0, 0, canvas.width, canvas.height);

        for (let x = 0; x < canvas.width/this.size; x++) {
            for (let y = 0; y < canvas.height/this.size; y++) {
                ctx.fillStyle = this.color;
                ctx.fillRect(this.size * x, this.size * y, this.size - 1, this.size - 1);
            }
        }

    }
    
}
