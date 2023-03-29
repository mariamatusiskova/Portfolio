class Easy extends Level {

    imgEasy = document.createElement("img");

    constructor() {
        super();
        
        this.imgEasy.setAttribute("src", "../model/buttons/pictures/level_easy.png");

        this.position = {
            x: 50,
            y: canvas.height/1.65
        };

        this.proportions = {
            width: this.imgEasy.width/2,
            height: this.imgEasy.height/2
        };
    }

    drawEasy() {
        ctx.drawImage(this.imgEasy, this.position.x, this.position.y, this.proportions.width, this.proportions.height);
    }
}