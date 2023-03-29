class Home extends Base {

    imgMenuList = document.createElement("img");
    imgSettingsIcon = document.createElement("img");
    imgScoreIcon = document.createElement("img");
    imgHelpIcon = document.createElement("img");
    imgHeading = document.createElement("img");
    imgSerpent = document.createElement("img");

    constructor(Color, Size) {
        super(Color, Size);

        this.imgMenuList.setAttribute("src", "../model/screens/screen_pictures/list.png");
        this.imgSettingsIcon.setAttribute("src", "../model/screens/screen_pictures/setting.png");
        this.imgScoreIcon.setAttribute("src", "../model/screens/screen_pictures/score.png");
        this.imgHelpIcon.setAttribute("src", "../model/screens/screen_pictures/help.png");
        this.imgHeading.setAttribute("src", "../model/screens/screen_pictures/heading.png");
        this.imgSerpent.setAttribute("src", "../model/screens/screen_pictures/serpent.png");

        this.position = {
            x: canvas.width - 75,
            y: 20
        };

        this.proportions = {
            width: this.imgMenuList.width/11,
            height: this.imgMenuList.height/11
        };
        console.log(this.position.x);
        console.log(this.position.y);
        console.log(this.proportions.width);
        console.log(this.proportions.height);
        console.log(this.imgMenuList);
        console.log("constructor");

    }

    drawHome(canvas) {
        console.log("home");

        ctx.fillStyle = this.color;
        ctx.fillRect(0, 0, canvas.width, canvas.height);

        this.drawDiagonal();

        ctx.lineWidth = 8;
        ctx.strokeStyle = "#A6F1A6";
        ctx.strokeRect(0, 0, canvas.width, canvas.height);

        this.drawHeading();
        this.drawSerpent();
        this.drawMenuList();
        this.drawSettingsIcon();
        this.drawScoreIcon();
        this.drawHelpIcon();

        btnEasy.drawEasy();
        btnMedium.drawMedium();
        btnHard.drawHard();
    }

    drawDiagonal(){

        var step = 8;

        ctx.lineWidth = 0.8;
        ctx.strokeStyle = "lightgreen";

        for (let x = 0; x < canvas.width; x += step) {
            for (let y = 0; y < canvas.height; y += step) {

                ctx.beginPath();
                ctx.moveTo(x, y);
                ctx.lineTo(x + this.size, y + this.size);
                ctx.stroke();
            }
        }
    }

    drawHeading() {
        ctx.drawImage(this.imgHeading, 50, canvas.height/3, this.imgHeading.width/1.2, this.imgHeading.height/1.2);
    }

    drawSerpent() {
        ctx.drawImage(this.imgSerpent, 360, canvas.height/4.3, this.imgSerpent.width/2.8, this.imgSerpent.height/2.8);
    }

    clearCanvas(canvas) {
        ctx.clearRect(0, 0, canvas.width, canvas.height);
    }
    
    drawMenuList() {
        ctx.drawImage(this.imgMenuList, this.position.x, this.position.y, this.proportions.width, this.proportions.height);
    }

    drawSettingsIcon() {
        ctx.drawImage(this.imgSettingsIcon, 20, 20, this.imgSettingsIcon.width/10, this.imgSettingsIcon.height/10);
    }

    drawScoreIcon() {
        ctx.drawImage(this.imgScoreIcon, canvas.width - 75, canvas.height - 70, this.imgScoreIcon.width/10, this.imgScoreIcon.height/10);
    }

    drawHelpIcon() {
        ctx.drawImage(this.imgHelpIcon, 20, canvas.height - 50, this.imgHelpIcon.width/2.5, this.imgHelpIcon.height/2.5);
    }
}