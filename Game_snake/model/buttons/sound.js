class Sound extends Settings {

    imgOn = document.createElement("img");
    imgOff = document.createElement("img");

    constructor(Color, Size, img, x, y, width, height) {
        super(Color, Size);

        this.imgOn.setAttribute("src", "../model/screens/screen_pictures/on.png");
        this.imgOff.setAttribute("src", "../model/screens/screen_pictures/off.png");

        this.img = img;

        this.position = {
            x: x,
            y: y
        };

        this.proportions = {
            width: width,
            height: height
        };
    }

    drawSound() {
        ctx.drawImage(this.imgSound, canvas.width/2 - this.imgSound.width/2, 300, this.imgSound.width/2, this.imgSound.height/2);
        ctx.drawImage(this.imgOn, 320, 300, this.imgOn.width/2, this.imgOn.height/2);
        ctx.drawImage(this.imgOff, 400, 300, this.imgOff.width/2, this.imgOff.height/2);
    }

    drawLine(x) {
        ctx.lineWidth = 4
        ctx.strokeStyle = "#1A1A1A";
        
        ctx.beginPath();
        ctx.moveTo(x - 70, 345);
        ctx.lineTo(x, 345);
        ctx.stroke();
    }

    muteSound() {
        pickLevel.muted = true;
        pickLevel.pause();
        right.muted = true;
        right.pause();
        left.muted = true;
        left.pause();
        up.muted = true;
        up.pause();
        down.muted = true;
        down.pause();
        gameOverSound.muted = true;
        gameOverSound.pause();
        foodSound.muted = true;
        foodSound.pause();
        turnOnSound.muted = true;
        turnOnSound.pause();
    }

    unmuteSound() {
        pickLevel.muted = false;
        right.muted = false;
        left.muted = false;
        up.muted = false;
        down.muted = false;
        gameOverSound.muted = false;
        foodSound.muted = false;
        turnOnSound.muted = false;
    }
}