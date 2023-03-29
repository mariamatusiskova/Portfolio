class Help extends Base {

    imgHelpIcon = document.createElement("img");
    imgQ = document.createElement("img");
    imgControlsText = document.createElement("img");
    imgKeyMov = document.createElement("img");
    imgKeyIns = document.createElement("img");
    imgSnakeIns = document.createElement("img");

    constructor(Color, Size) {
        super(Color, Size);

        this.imgHelpIcon.setAttribute("src", "../model/screens/screen_pictures/help.png");
        this.imgQ.setAttribute("src", "../model/screens/screen_pictures/que.png");
        this.imgControlsText.setAttribute("src", "../model/screens/screen_pictures/controls.png");
        this.imgKeyMov.setAttribute("src", "../model/screens/screen_pictures/movement.png");
        this.imgKeyIns.setAttribute("src", "../model/screens/screen_pictures/instructions.png");
        this.imgSnakeIns.setAttribute("src", "../model/screens/screen_pictures/ins_snake.png");

        this.position = {
            x: 20,
            y: canvas.height - 50 
        };

        this.proportions = {
            width: this.imgHelpIcon.width/2.5,
            height: this.imgHelpIcon.height/2.5
        };

    }

    drawHelp(canvas) {
        ctx.fillStyle = this.color;
        ctx.fillRect(canvas.width/22, canvas.height/7, canvas.width/1.1, canvas.height/1.4); 

        ctx.lineWidth = 3
        ctx.strokeStyle = "#1A1A1A";
        ctx.strokeRect(canvas.width/22, canvas.height/7, canvas.width/1.1, canvas.height/1.4);

        this.drawQ();
        this.drawTextControls();
        this.drawKeyMov();
        this.drawKeyIns();
        this.drawSnakeIns();

        this.drawLine(190);
        btnExit.drawExit();
        this.drawLine(465);

    }

    drawTextControls() {
        ctx.drawImage(this.imgControlsText, canvas.width/2 - this.imgControlsText.width/3.5, canvas.height/5, this.imgControlsText.width/1.7,this.imgControlsText.height/1.7);
    }

    drawLine(y) {
        ctx.lineWidth = 3
        ctx.strokeStyle = "#1A1A1A";
        
        ctx.beginPath();
        ctx.moveTo(180, y);
        //ctx.lineTo(420, y);
        ctx.stroke();
    }

    drawQ() {
        ctx.drawImage(this.imgQ, canvas.width/2 - this.imgQ.width/2.5, 110, this.imgQ.width/8, this.imgQ.height/8);
    }

    drawKeyMov() {
        ctx.drawImage(this.imgKeyMov, canvas.width/2 - this.imgKeyMov.width/2, 220, this.imgKeyMov.width/2.8, this.imgKeyMov.height/2.8);
    }

    drawKeyIns() {
        ctx.drawImage(this.imgKeyIns, canvas.width - this.imgKeyIns.width/2, 220, this.imgKeyIns.width/2.8, this.imgKeyIns.height/2.8);
    }

    drawSnakeIns() {
        ctx.drawImage(this.imgSnakeIns, canvas.width - this.imgSnakeIns.width/2.8, 380, this.imgSnakeIns.width/4.8, this.imgSnakeIns.height/4.8);
    }
}