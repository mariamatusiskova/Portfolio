class Settings extends Base {

    imgSettingsText = document.createElement("img");
    imgSound = document.createElement("img");
    imgResetScore = document.createElement("img");
    imgSettingsIcon = document.createElement("img");

    constructor(Color, Size) {
        super(Color, Size);

        this.imgSettingsText.setAttribute("src", "../model/screens/screen_pictures/settings_text.png");
        this.imgSound.setAttribute("src", "../model/screens/screen_pictures/sound.png");
        this.imgResetScore.setAttribute("src", "../model/screens/screen_pictures/reset.png");
        this.imgSettingsIcon.setAttribute("src", "../model/screens/screen_pictures/setting.png");

        this.position = {
            x: 20,
            y: 20
        };

        this.proportions = {
            width: this.imgSettingsIcon.width/10,
            height: this.imgSettingsIcon.height/10
        };

    }

    drawSettings(canvas) {
        ctx.fillStyle = this.color;
        ctx.fillRect(canvas.width/22, canvas.height/7, canvas.width/1.1, canvas.height/1.4); 

        ctx.lineWidth = 3
        ctx.strokeStyle = "#1A1A1A";
        ctx.strokeRect(canvas.width/22, canvas.height/7, canvas.width/1.1, canvas.height/1.4);

        this.drawTextSettings();

        this.drawLine(190);
        btnSoundOn.drawSound();
        btnSoundOff.drawSound();
        if (turnOn == 1) {
            btnSoundOn.drawLine(390);
        } else if (turnOff == 1) {
            btnSoundOff.drawLine(480);
        }
        btnExit.drawExit();
        btnResetScore.drawReset();
        this.drawSettingsIcon(canvas.width/2 - this.imgSettingsIcon.width/2.7, canvas.height/5.3, this.imgSettingsIcon.width/13,this.imgSettingsIcon.height/13);
        this.drawSettingsIcon(canvas.width/2 - this.imgSettingsIcon.width/2.5, canvas.height/4, this.imgSettingsIcon.width/16,this.imgSettingsIcon.height/16);
        this.drawSettingsIcon(canvas.width/2 + 150, canvas.height/5.3, this.imgSettingsIcon.width/13,this.imgSettingsIcon.height/13);
        this.drawSettingsIcon(canvas.width/2 + 172, canvas.height/4, this.imgSettingsIcon.width/16,this.imgSettingsIcon.height/16);
        this.drawLine(485);

    }

    drawTextSettings() {
        ctx.drawImage(this.imgSettingsText, canvas.width/2 - this.imgSettingsText.width/3, canvas.height/5, this.imgSettingsText.width/1.5,this.imgSettingsText.height/1.5);
    }

    drawLine(y) {
        ctx.lineWidth = 3
        ctx.strokeStyle = "#1A1A1A";
        
        ctx.beginPath();
        ctx.moveTo(180, y);
        ctx.lineTo(420, y);
        ctx.stroke();
    }

    drawSettingsIcon(x, y, width, height) {
        ctx.drawImage(this.imgSettingsIcon, x, y, width, height);
    }
}