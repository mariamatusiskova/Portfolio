class Medium extends Level {

    imgMedium = document.createElement("img");

    constructor() {
        super();

        this.imgMedium.setAttribute("src", "../model/buttons/pictures/level_medium.png");

        this.position = {
            x: (canvas.width - this.imgMedium.width/2)/2,
            y: canvas.height/1.65
        };

        this.proportions = {
            width: this.imgMedium.width/2,
            height: this.imgMedium.height/2
        };
    }

    drawMedium() {
        ctx.drawImage(this.imgMedium, this.position.x, this.position.y, this.proportions.width, this.proportions.height);
    }
}