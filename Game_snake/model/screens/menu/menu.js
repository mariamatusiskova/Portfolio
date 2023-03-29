class Menu extends Base {

    imgMenu = document.createElement("img");
    imgHow = document.createElement("img");
    imgSound = document.createElement("img");
    imgNewGame = document.createElement("img");
    imgMenuList = document.createElement("img");

    constructor(Color, Size, img) {
        super(Color, Size);

        this.imgMenu.setAttribute("src", "../model/screens/screen_pictures/menu.png");
        this.imgHow.setAttribute("src", "../model/screens/screen_pictures/how.png");
        this.imgSound.setAttribute("src", "../model/screens/screen_pictures/sound.png");
        this.imgNewGame.setAttribute("src", "../model/screens/screen_pictures/new_game.png");
        this.imgMenuList.setAttribute("src", "../model/screens/screen_pictures/list.png");
        this.img = img;

        this.position = {
            x: canvas.width - 75,
            y: 20
        };

        this.proportions = {
            width: this.imgMenuList.width/11,
            height: this.imgMenuList.height/11
        };

    }

    drawMenu(canvas) {
        ctx.fillStyle = this.color;
        ctx.fillRect(canvas.width/22, canvas.height/7, canvas.width/1.1, canvas.height/1.4); 

        ctx.lineWidth = 3
        ctx.strokeStyle = "#1A1A1A";
        ctx.strokeRect(canvas.width/22, canvas.height/7, canvas.width/1.1, canvas.height/1.4);

        this.drawTextMenu();

        this.drawLine(190);
        btnHow.drawHowText();
        btnNewGame.drawNewGame();
        btnExit.drawExit();
        this.drawLine(470);

    }

    drawTextMenu() {
        ctx.drawImage(this.imgMenu, canvas.width/1.55 - this.imgMenu.width/1.4, canvas.height/5,  this.imgMenu.width/1.4, this.imgMenu.height/1.4);
    }

    drawLine(y) {
        ctx.lineWidth = 3
        ctx.strokeStyle = "#1A1A1A";
        
        ctx.beginPath();
        ctx.moveTo(180, y);
        ctx.lineTo(420, y);
        ctx.stroke();
    }

}