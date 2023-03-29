
// uvodny script
// sources: https://www.youtube.com/watch?v=D-dtyO44ANA, https://www.youtube.com/watch?v=T-xfEbDORng, https://www.youtube.com/watch?v=AaGK-fj-BAM, https://www.youtube.com/watch?v=7Azlj0f9vas&t=2585s
var canvas = document.getElementById("canvas");
var ctx = canvas.getContext("2d");

var homeScreen = 0;
var exitScreenMenu = 0;
var exitScreenSettings = 0;
var exitScreen = 0;
var exitScreenGameOver = 0;
var end = false;
var turnOn = 1;
var turnOff = 0;

var imgExit = document.createElement("img");
imgExit.setAttribute("src", "../model/screens/screen_pictures/exit.png");
var imgOn = document.createElement("img");
imgOn.setAttribute("src", "../model/screens/screen_pictures/on.png");
var imgOff = document.createElement("img");
imgOff.setAttribute("src", "../model/screens/screen_pictures/off.png");

var node = new Node("#FFA01B"); 
var home = new Home("white", 30); 
var board = new Background("lightgreen", 30); 
var snake = new Snake("#F47E2F", 30, 30); 
var food = new Food("#F3453F", 30);
var btnMenu = new Menu("#B8F4B8", 30, imgExit); 
var btnExit = new Exit("#B8F4B8", 30, imgExit, canvas.width/2 - imgExit.width/4, 390, imgExit.width/2, imgExit.height/2); 
var btnExitGameOver = new Exit("#B8F4B8", 30, imgExit, canvas.width - imgExit.width/1.1, canvas.height/1.6, imgExit.width/2.2, imgExit.height/2.2); 
var btnTryAgain = new Again("#B8F4B8", 30); 
var btnResetScore = new ResetScore("#B8F4B8", 30); 
var btnSoundOn = new Sound("#B8F4B8", 30, imgOn, 320, 300, imgOn.width/2, imgOn.height/2); 
var btnSoundOff = new Sound("#B8F4B8", 30, imgOff, 400, 300, imgOff.width/2, imgOff.height/2); 
var btnNewGame = new NewGame("#B8F4B8", 30); 
var btnHow = new How("#B8F4B8", 30); 
var btnSettings = new Settings("#B8F4B8", 30); 
var btnScore = new Score("#B8F4B8", 30); 
var btnHelp = new Help("#B8F4B8", 30); 
var gameOver = new Gameover("#B8F4B8", 30); 
var btnEasy = new Easy();
var btnMedium = new Medium();
var btnHard = new Hard();
var level = new Level();

var pickLevel = new Audio("../controller/sound/pick_level.wav");
var right = new Audio("../controller/sound/right.mp3");
var left = new Audio("../controller/sound/left.mp3");
var up = new Audio("../controller/sound/up.mp3");
var down = new Audio("../controller/sound/down.mp3");
var gameOverSound = new Audio("../controller/sound/dead.wav");
var foodSound = new Audio("../controller/sound/chrum.wav");
var turnOnSound = new Audio("../controller/sound/turnon.wav");

document.addEventListener('keydown', keyControls, false);
canvas.addEventListener("click", clickCanvas, false);

function load() {

    home.drawHome(canvas);
    homeScreen = 1;
    
}

window.addEventListener("load", load, true);