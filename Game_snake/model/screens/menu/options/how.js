class How extends Menu {

    imgText = document.createElement("img");
    imgHow = document.createElement("img");


    constructor(Color, Size) {
        super(Color, Size);

        this.imgText.setAttribute("src", "../model/screens/screen_pictures/text.png");
        this.imgHow.setAttribute("src", "../model/screens/screen_pictures/how.png");

        this.position = {
            x: canvas.width/2 - this.imgHow.width/4,
            y: 220
        };

        this.proportions = {
            width: this.imgHow.width/2,
            height: this.imgHow.height/2
        };

    }

    drawHow() {
        ctx.fillStyle = this.color;
        ctx.fillRect(canvas.width/22, canvas.height/7, canvas.width/1.1, canvas.height/1.4); 

        ctx.lineWidth = 3
        ctx.strokeStyle = "#1A1A1A";
        ctx.strokeRect(canvas.width/22, canvas.height/7, canvas.width/1.1, canvas.height/1.4);

        this.drawText();

    }

    drawText() {
        ctx.drawImage(this.imgText, 110, 130,  this.imgText.width/2.5, this.imgText.height/2.5);
    }

    drawHowText() {
        ctx.drawImage(this.imgHow, this.position.x, this.position.y, this.proportions.width, this.proportions.height);
    }

}