class Score extends Base {

    imgScoreIcon = document.createElement("img");
    imgScoreText = document.createElement("img");
    imgBestScore = document.createElement("img");
    imgLatestScore = document.createElement("img");

    constructor(Color, Size) {
        super(Color, Size);

        this.imgScoreText.setAttribute("src", "../model/screens/screen_pictures/score_text.png");
        this.imgScoreIcon.setAttribute("src", "../model/screens/screen_pictures/score.png");
        this.imgBestScore.setAttribute("src", "../model/screens/screen_pictures/best_score.png");
        this.imgLatestScore.setAttribute("src", "../model/screens/screen_pictures/latest.png");

        this.position = {
            x: canvas.width - 75,
            y: canvas.height - 70
        };

        this.proportions = {
            width: this.imgScoreIcon.width/10,
            height: this.imgScoreIcon.height/10
        };

        this.bestScore = 0;
        this.top = "highscore";
    }

    drawScore(canvas) {
        ctx.fillStyle = this.color;
        ctx.fillRect(canvas.width/22, canvas.height/7, canvas.width/1.1, canvas.height/1.4); 

        ctx.lineWidth = 3
        ctx.strokeStyle = "#1A1A1A";
        ctx.strokeRect(canvas.width/22, canvas.height/7, canvas.width/1.1, canvas.height/1.4);

        this.drawTextScore();
        this.drawBestScore();
        this.drawLatestScore();

        btnExit.drawExit();
        this.drawLine(190);
        this.drawLine(478);

    }

    drawTextScore() {
        ctx.drawImage(this.imgScoreText, canvas.width/2 - this.imgScoreText.width/3, canvas.height/5, this.imgScoreText.width/1.5,this.imgScoreText.height/1.5);
    }

    drawLine(y) {
        ctx.lineWidth = 3
        ctx.strokeStyle = "#1A1A1A";
        
        ctx.beginPath();
        ctx.moveTo(180, y);
        ctx.lineTo(420, y);
        ctx.stroke();
    }

    drawBestScore() {
        ctx.drawImage(this.imgBestScore, canvas.width/2 - this.imgBestScore.width/3, 220, this.imgBestScore.width/2, this.imgBestScore.height/2);

        this.bestScore = localStorage.getItem(this.top) == null ? 0 : localStorage.getItem(this.top);

        if(localStorage.getItem(this.top) == null) {
            this.bestScore = 0;
        } else {
            this.bestScore = localStorage.getItem(this.top);
        }

        ctx.font = '38px Comic Sans MS';
        ctx.fillStyle = "#1A1A1A";
        ctx.fillText(this.bestScore, canvas.width - this.imgBestScore.width, 255);
    }

    drawLatestScore() {
        ctx.drawImage(this.imgLatestScore, canvas.width/2 - this.imgLatestScore.width/2.5, 300, this.imgLatestScore.width/1.8, this.imgLatestScore.height/1.8);
        ctx.font = '38px Comic Sans MS';
        ctx.fillStyle = "#1A1A1A";
        ctx.fillText(countFood, canvas.width - this.imgBestScore.width, 335);
    }

    getBestScore() {
        return this.bestScore;
    }

    setBestScore(newTop) {
        this.bestScore = newTop;
    }

    getTop() {
        return this.top;
    }

    setTop(newTop) {
        this.top = newTop;
    }

}
