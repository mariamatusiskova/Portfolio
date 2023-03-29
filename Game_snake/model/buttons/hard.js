class Hard extends Level {

    imgHard = document.createElement("img");

    constructor() {
        super();

        this.imgHard.setAttribute("src", "../model/buttons/pictures/level_hard.png");

        this.position = {
            x: 400,
            y: canvas.height/1.65
        };

        this.proportions = {
            width: this.imgHard.width/2,
            height: this.imgHard.height/2
        };
    }

    drawHard() {
        ctx.drawImage(this.imgHard, this.position.x, this.position.y, this.proportions.width, this.proportions.height);
    }

}