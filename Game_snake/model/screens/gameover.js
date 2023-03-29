class Gameover extends Base {

    imgGameOver = document.createElement("img");
    imgTryAgain = document.createElement("img");
    imgExit = document.createElement("img");
    imgDot = document.createElement("img");
    imgPlus = document.createElement("img");
    imgZero = document.createElement("img");

    constructor(Color, Size) {
        super(Color, Size);

        this.imgGameOver.setAttribute("src", "../model/screens/screen_pictures/game_over.png");
        this.imgTryAgain.setAttribute("src", "../model/screens/screen_pictures/again.png");
        this.imgExit.setAttribute("src", "../model/screens/screen_pictures/exit.png");
        this.imgDot.setAttribute("src", "../model/screens/screen_pictures/draw_dot.png");
        this.imgPlus.setAttribute("src", "../model/screens/screen_pictures/draw_plus.png");
        this.imgZero.setAttribute("src", "../model/screens/screen_pictures/draw_o.png");
    }

    drawGameOver(canvas) {
        ctx.fillStyle = this.color;
        ctx.fillRect(canvas.width/22, canvas.height/7, canvas.width/1.1, canvas.height/1.4); 

        ctx.lineWidth = 3
        ctx.strokeStyle = "#1A1A1A";
        ctx.strokeRect(canvas.width/22, canvas.height/7, canvas.width/1.1, canvas.height/1.4);

        this.drawGameOverText();

        this.drawLine(320);

        btnTryAgain.drawTryAgain();
        btnExitGameOver.drawExit();
        this.drawSigns(this.imgDot, 380, 70, this.imgDot.width, this.imgDot.height);
        this.drawSigns(this.imgDot, 150, 120, this.imgDot.width/1.5, this.imgDot.height/1.5);
        this.drawSigns(this.imgDot, 70, 400, this.imgDot.width/1.5, this.imgDot.height/1.5);
        this.drawSigns(this.imgDot, 350, 390, this.imgDot.width/2, this.imgDot.height/2);
        this.drawSigns(this.imgPlus, 420, 440, this.imgPlus.width/2, this.imgPlus.height/2);
        this.drawSigns(this.imgPlus, 300, 140, this.imgPlus.width/3, this.imgPlus.height/3);
        this.drawSigns(this.imgPlus, 60, 270, this.imgPlus.width/2.5, this.imgPlus.height/2.5);
        this.drawSigns(this.imgPlus, 520, 170, this.imgPlus.width/2.5, this.imgPlus.height/2.5);
        this.drawSigns(this.imgZero, 70, 120, this.imgZero.width/2.5, this.imgZero.height/3);
        this.drawSigns(this.imgZero, 210, 450, this.imgZero.width/2.5, this.imgZero.height/3);
        this.drawSigns(this.imgZero, 530, 300, this.imgZero.width/2.5, this.imgZero.height/3);
    }

    drawLine(y) {
        ctx.lineWidth = 3
        ctx.strokeStyle = "#1A1A1A";
        
        ctx.beginPath();
        ctx.moveTo(500, y);
        ctx.lineTo(100, y);
        ctx.stroke();
    }

    drawGameOverText() {
        ctx.drawImage(this.imgGameOver, (canvas.width - this.imgGameOver.width)/1.5, canvas.height/3, this.imgGameOver.width/1.1, this.imgGameOver.height/1.1);
    }

    drawSigns(img, x, y, width, height) {
        ctx.drawImage(img, x, y, width, height);
    }

}