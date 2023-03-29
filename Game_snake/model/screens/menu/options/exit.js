class Exit extends Menu {
    constructor(Color, Size, img, x, y, width, height) {
        super(Color, Size, img);

        this.position = {
            x: x,
            y: y
        };

        this.proportions = {
            width: width,
            height: height
        };
    }

    drawExit() {
        ctx.drawImage(this.img, this.position.x, this.position.y, this.proportions.width, this.proportions.height);
    }
}