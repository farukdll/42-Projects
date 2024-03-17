const ball = document.getElementById('ball');

const leftPaddle = document.getElementById('leftPaddle');
const rightPaddle = document.getElementById('rightPaddle');

const playerScoreElement = document.getElementById('player-score');
const computerScoreElement = document.getElementById('computer-score');

let ballX = 620;
let ballY = 340;

let ballXSpeed = 5;
let ballYSpeed = 5;

let leftPaddleY = 300;
let rightPaddleY = 300;

let leftPaddleYStart = 300;
let rightPaddleYStart = 300;

let playerScore = 0;
let computerScore = 0;

let ballInPlay = false;

let ballColor = { r: 255, g: 153, b: 204 };

const endScore = parseInt(prompt('How many scores should the game end?'));

document.addEventListener('keydown', (e) => {
    if ((e.key === 'w' || e.key === 'W') && leftPaddleY > 0) {
        leftPaddleY -= 50;
    } else if ((e.key === 's' || e.key === 'S') && leftPaddleY < 600) {
        leftPaddleY += 50;
    }
});

document.addEventListener('keyup', (e) => {
    if ((e.key === 'w' || e.key === 'W') && leftPaddleY > 0) {
        leftPaddleY -= 80;
    } else if ((e.key === 's' || e.key === 'S') && leftPaddleY < 600) {
        leftPaddleY += 80;
    }
});

function scoreReset() {
    playerScore = 0;
    computerScore = 0;
    playerScoreElement.textContent = '0';
    computerScoreElement.textContent = '0';
}

function handleLose() {
    if (playerScore === endScore || computerScore === endScore) {
        console.log(`player score: ${playerScore}, computer score ${computerScore}`);
        scoreReset();
        resetBall();
        ballColorReset();
        ballInPlay = false;

        if (!ballInPlay) {
            window.location.href = '/finish-match';
        }
    }
}

function updateGame() {
    ballX += ballXSpeed;
    ballY += ballYSpeed;

    if (ballY > rightPaddleY + 70) {
        rightPaddleY += 15;
    } else if (ballY < rightPaddleY + 70) {
        rightPaddleY -= 15;
    }

    if (ballX <= 0 || ballX >= 1230) {
        if (ballX <= 0) {
            computerScore += 1;
            computerScoreElement.textContent = computerScore;
            ballColorReset();
        } else {
            playerScore += 1;
            playerScoreElement.textContent = playerScore;
            ballColorReset();
        }

        handleLose();
        resetBall();
        ballInPlay = false;
    }

    if (ballY <= 0 || ballY >= 680) {
        ballYSpeed = -ballYSpeed;
    }

    if (
        (ballX <= 40 && ballY >= leftPaddleY && ballY <= leftPaddleY + 100) ||
        (ballX >= 1190 && ballY >= rightPaddleY && ballY <= rightPaddleY + 100)
    ) {
        ballXSpeed *= 1.2;
        ballYSpeed *= 1.2;
        ballXSpeed = -ballXSpeed;
        changeBallColor();
    }

    leftPaddle.style.top = leftPaddleY + 'px';
    rightPaddle.style.top = rightPaddleY + 'px';

    ball.style.left = ballX + 'px';
    ball.style.top = ballY + 'px';

    requestAnimationFrame(updateGame);
}

function resetBall() {
    ballX = 620;
    ballY = 340;

    ballXSpeed = 5;
    ballYSpeed = 5;

    ballInPlay = true;

    leftPaddleY = leftPaddleYStart;
    rightPaddleY = rightPaddleYStart;

    ballColor = { r: 255, g: 153, b: 204 };
}

function changeBallColor() {
    ballColor.r = Math.max(ballColor.r - 20, 0);
    ballColor.g = Math.max(ballColor.g - 20, 0);
    ballColor.b = Math.max(ballColor.b - 20, 0);

    ball.style.backgroundColor = `rgb(${ballColor.r}, ${ballColor.g}, ${ballColor.b})`;
}

function ballColorReset() {
    ballColor = '#efefef';
    ball.style.backgroundColor = ballColor;
}

updateGame();