// Game Configuration
const LEVELS = {
    1: { discs: 3, minMoves: 7 },
    2: { discs: 4, minMoves: 15 },
    3: { discs: 5, minMoves: 31 },
    4: { discs: 6, minMoves: 63 },
    5: { discs: 7, minMoves: 127 }
};

// Game State
let gameState = {
    currentLevel: 1,
    gameActive: false,
    players: {
        1: {
            rods: [[], [], []],
            selectedRod: 0,
            pickedDisc: null,
            pickedFromRod: null,
            moves: 0,
            time: 0,
            points: 0,
            completed: false,
            completionTime: null,
            completionMoves: null
        },
        2: {
            rods: [[], [], []],
            selectedRod: 0,
            pickedDisc: null,
            pickedFromRod: null,
            moves: 0,
            time: 0,
            points: 0,
            completed: false,
            completionTime: null,
            completionMoves: null
        }
    },
    timers: {
        1: null,
        2: null
    },
    totalLevelsCompleted: 0
};

// DOM Elements
const levelSelect = document.getElementById('level');
const startBtn = document.getElementById('startBtn');
const guideToggle = document.getElementById('guideToggle');
const guide = document.getElementById('guide');
const resultModal = document.getElementById('resultModal');
const gameOverModal = document.getElementById('gameOverModal');
const nextLevelBtn = document.getElementById('nextLevelBtn');
const restartBtn = document.getElementById('restartBtn');
const restartGameBtn = document.getElementById('restartGameBtn');

// Event Listeners
startBtn.addEventListener('click', startGame);
guideToggle.addEventListener('click', toggleGuide);
nextLevelBtn.addEventListener('click', nextLevel);
restartBtn.addEventListener('click', restartLevel);
restartGameBtn.addEventListener('click', restartGame);
document.addEventListener('keydown', handleKeyPress);

// Toggle Guide
function toggleGuide() {
    guide.classList.toggle('active');
    guideToggle.classList.toggle('active');
}

// Initialize Game
function initializeGame() {
    const numDiscs = LEVELS[gameState.currentLevel].discs;

    // Reset player states
    for (let player = 1; player <= 2; player++) {
        gameState.players[player].rods = [[], [], []];
        gameState.players[player].selectedRod = 0;
        gameState.players[player].moves = 0;
        gameState.players[player].time = 0;
        gameState.players[player].completed = false;
        gameState.players[player].completionTime = null;
        gameState.players[player].completionMoves = null;

        // Initialize first rod with discs (largest at bottom)
        for (let i = numDiscs; i >= 1; i--) {
            gameState.players[player].rods[0].push(i);
        }

        // Update UI
        updateGameBoard(player);
        updateStats(player);
    }

    gameState.gameActive = true;
    resultModal.classList.remove('active');
    clearAllTimers();
    startTimers();
}

// Start Game
function startGame() {
    gameState.currentLevel = parseInt(levelSelect.value);
    gameState.totalLevelsCompleted = 0;
    initializeGame();
}

// Handle Keyboard Input
function handleKeyPress(e) {
    if (!gameState.gameActive) return;

    // Player 1 Controls: Q(0), W(1), E(2), Space(pick/place)
    const player1Controls = {
        'q': 0,
        'w': 1,
        'e': 2,
        ' ': 'action'
    };

    // Player 2 Controls: U(0), I(1), O(2), Enter(pick/place)
    const player2Controls = {
        'u': 0,
        'i': 1,
        'o': 2,
        'Enter': 'action'
    };

    const keyLower = e.key.toLowerCase();

    if (keyLower in player1Controls) {
        e.preventDefault();
        if (player1Controls[keyLower] === 'action') {
            performAction(1);
        } else {
            selectRod(1, player1Controls[keyLower]);
        }
    }

    if (keyLower in player2Controls || e.key === 'Enter') {
        const key = e.key === 'Enter' ? 'Enter' : keyLower;
        if (key in player2Controls) {
            e.preventDefault();
            if (player2Controls[key] === 'action') {
                performAction(2);
            } else {
                selectRod(2, player2Controls[key]);
            }
        }
    }
}

// Select Rod
function selectRod(player, rodIndex) {
    gameState.players[player].selectedRod = rodIndex;
    updateSelectedRodDisplay(player);
    updateRodSelection(player);
}

// Update Selected Rod Display
function updateSelectedRodDisplay(player) {
    const rodNames = ['Rod A', 'Rod B', 'Rod C'];
    const display = document.getElementById(`selected${player}`);
    display.textContent = `Selected: ${rodNames[gameState.players[player].selectedRod]}`;
}

// Update Rod Selection Visual
function updateRodSelection(player) {
    const rods = document.querySelectorAll(`#board${player} .rod`);
    rods.forEach((rod, index) => {
        rod.classList.remove('selected');
        if (index === gameState.players[player].selectedRod) {
            rod.classList.add('selected');
        }
    });
}

// Perform Action (Pick/Place)
function performAction(player) {
    const selectedRod = gameState.players[player].selectedRod;
    const rods = gameState.players[player].rods;
    const statusEl = document.getElementById(`status${player}`);

    // If no disc is picked
    if (gameState.players[player].pickedDisc === null) {
        // Try to pick a disc from the selected rod
        if (rods[selectedRod].length === 0) {
            showStatus(player, 'This rod is empty!', 'error');
            return;
        }

        // Pick the top disc from selected rod
        const disc = rods[selectedRod].pop();
        gameState.players[player].pickedDisc = disc;
        gameState.players[player].pickedFromRod = selectedRod;
        showStatus(player, `Picked disc ${disc}`, 'info');
    } else {
        // A disc is already picked, try to place it
        const pickedDisc = gameState.players[player].pickedDisc;
        const pickedFromRod = gameState.players[player].pickedFromRod;

        // Cannot place on the same rod
        if (selectedRod === pickedFromRod) {
            showStatus(player, 'Cannot place on the same rod!', 'error');
            return;
        }

        // Check if placement is valid
        // Rule: Only a SMALLER disc (lower number) can be placed on a LARGER disc (higher number)
        const targetRod = rods[selectedRod];
        
        if (targetRod.length > 0) {
            const topDisc = targetRod[targetRod.length - 1];
            // If picked disc is larger (bigger number) than top disc on target rod, it's INVALID
            if (pickedDisc > topDisc) {
                showStatus(player, `❌ Disc ${pickedDisc} is too large for disc ${topDisc}!`, 'error');
                return;
            }
        }

        // Valid move - place the disc
        rods[selectedRod].push(pickedDisc);
        gameState.players[player].moves++;
        gameState.players[player].pickedDisc = null;
        gameState.players[player].pickedFromRod = null;

        showStatus(player, `✓ Placed disc ${pickedDisc}`, 'success');
    }

    updateGameBoard(player);
    updateStats(player);
    checkWinCondition(player);
}

// Show Status Message
function showStatus(player, message, type) {
    const statusEl = document.getElementById(`status${player}`);
    statusEl.textContent = message;
    statusEl.className = `status ${type}`;
}

// Update Game Board Display
function updateGameBoard(player) {
    for (let rod = 0; rod < 3; rod++) {
        const container = document.getElementById(`rod-${player}-${rod}`);
        container.innerHTML = '';

        // Iterate in REVERSE order so largest disc is at bottom, smallest at top
        const rods = gameState.players[player].rods[rod];
        for (let i = rods.length - 1; i >= 0; i--) {
            const disc = rods[i];
            const discEl = document.createElement('div');
            discEl.className = `disc disc-${disc}`;
            discEl.textContent = disc;
            
            // Highlight if this rod is selected and has discs
            if (rod === gameState.players[player].selectedRod && gameState.players[player].pickedDisc === null) {
                discEl.classList.add('selectable');
            }
            
            container.appendChild(discEl);
        }
    }

    // Show picked disc indicator if a disc is picked
    const pickedIndicator = document.getElementById(`picked${player}`);
    if (gameState.players[player].pickedDisc !== null) {
        const pickedDisc = gameState.players[player].pickedDisc;
        const rodName = ['Rod A', 'Rod B', 'Rod C'][gameState.players[player].pickedFromRod];
        pickedIndicator.innerHTML = `
            <div class="picked-disc-indicator">
                Holding: <span class="disc-badge disc-${pickedDisc}">${pickedDisc}</span> from ${rodName}
            </div>
        `;
    } else {
        pickedIndicator.innerHTML = '';
    }
}

// Update Stats Display
function updateStats(player) {
    document.getElementById(`moves${player}`).textContent = gameState.players[player].moves;
    document.getElementById(`points${player}`).textContent = gameState.players[player].points;
}

// Start Timers for Both Players
function startTimers() {
    for (let player = 1; player <= 2; player++) {
        if (gameState.timers[player]) clearInterval(gameState.timers[player]);

        gameState.timers[player] = setInterval(() => {
            gameState.players[player].time++;
            updateTimerDisplay(player);
        }, 1000);
    }
}

// Update Timer Display
function updateTimerDisplay(player) {
    const time = gameState.players[player].time;
    const minutes = Math.floor(time / 60);
    const seconds = time % 60;
    const timerEl = document.getElementById(`timer${player}`);
    timerEl.textContent = `${String(minutes).padStart(2, '0')}:${String(seconds).padStart(2, '0')}`;
}

// Clear All Timers
function clearAllTimers() {
    for (let player = 1; player <= 2; player++) {
        if (gameState.timers[player]) {
            clearInterval(gameState.timers[player]);
            gameState.timers[player] = null;
        }
    }
}

// Check Win Condition
function checkWinCondition(player) {
    const rods = gameState.players[player].rods;
    const lastRod = rods[2];
    const numDiscs = LEVELS[gameState.currentLevel].discs;

    // Check if all discs are on the last rod in correct order
    if (lastRod.length === numDiscs) {
        let isValid = true;
        for (let i = 0; i < lastRod.length; i++) {
            if (lastRod[i] !== i + 1) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            completeLevel(player);
        }
    }
}

// Complete Level for Player
function completeLevel(player) {
    if (gameState.players[player].completed) return;

    gameState.players[player].completed = true;
    gameState.players[player].completionTime = gameState.players[player].time;
    gameState.players[player].completionMoves = gameState.players[player].moves;

    // Calculate points
    const minMoves = LEVELS[gameState.currentLevel].minMoves;
    const moves = gameState.players[player].moves;
    const time = gameState.players[player].time;
    let points = 1000;

    // Points based on moves
    const moveRatio = minMoves / moves;
    points = Math.floor(points * moveRatio);

    // Points based on time (bonus for fast completion)
    if (time < 60) points += 200;
    else if (time < 120) points += 100;
    else if (time < 300) points += 50;

    gameState.players[player].points += points;

    showStatus(player, '🎉 Level Complete!', 'success');

    // Check if both players have completed
    if (gameState.players[1].completed && gameState.players[2].completed) {
        endLevel();
    }
}

// End Level and Show Results
function endLevel() {
    gameState.gameActive = false;
    clearAllTimers();

    // Display results
    const player1Result = document.getElementById('player1Result');
    const player2Result = document.getElementById('player2Result');
    const winner = document.getElementById('winner');

    player1Result.innerHTML = `
        <h3>Player 1</h3>
        <p><strong>Time:</strong> ${formatTime(gameState.players[1].completionTime)}</p>
        <p><strong>Moves:</strong> ${gameState.players[1].completionMoves}</p>
        <p><strong>Points Earned:</strong> ${gameState.players[1].points}</p>
    `;

    player2Result.innerHTML = `
        <h3>Player 2</h3>
        <p><strong>Time:</strong> ${formatTime(gameState.players[2].completionTime)}</p>
        <p><strong>Moves:</strong> ${gameState.players[2].completionMoves}</p>
        <p><strong>Points Earned:</strong> ${gameState.players[2].points}</p>
    `;

    // Determine winner
    let winnerText = '';
    if (gameState.players[1].points > gameState.players[2].points) {
        winnerText = '🏆 Player 1 Wins This Round!';
    } else if (gameState.players[2].points > gameState.players[1].points) {
        winnerText = '🏆 Player 2 Wins This Round!';
    } else {
        winnerText = '🤝 It\'s a Tie!';
    }
    winner.textContent = winnerText;

    // Show results modal
    resultModal.classList.add('active');

    // Check if all levels completed
    if (gameState.currentLevel === 5) {
        nextLevelBtn.style.display = 'none';
        setTimeout(showGameOver, 2000);
    } else {
        nextLevelBtn.style.display = 'inline-block';
    }
}

// Next Level
function nextLevel() {
    gameState.currentLevel++;
    gameState.totalLevelsCompleted++;
    initializeGame();
}

// Restart Level
function restartLevel() {
    initializeGame();
}

// Restart Game
function restartGame() {
    gameState.currentLevel = 1;
    gameState.totalLevelsCompleted = 0;
    gameState.players[1].points = 0;
    gameState.players[2].points = 0;
    gameOverModal.classList.remove('active');
    resultModal.classList.remove('active');
    levelSelect.value = '1';
}

// Show Game Over
function showGameOver() {
    const finalResults = document.getElementById('finalResults');
    const player1Total = gameState.players[1].points;
    const player2Total = gameState.players[2].points;

    let winner = '';
    if (player1Total > player2Total) {
        winner = '🏆 Player 1 is the Ultimate Champion! 🏆';
    } else if (player2Total > player1Total) {
        winner = '🏆 Player 2 is the Ultimate Champion! 🏆';
    } else {
        winner = '🤝 It\'s a Perfect Tie! Both Players are Champions! 🤝';
    }

    finalResults.innerHTML = `
        <p><strong>Final Scores:</strong></p>
        <p>Player 1: ${player1Total} Points</p>
        <p>Player 2: ${player2Total} Points</p>
        <p style="margin-top: 15px; font-size: 1.2em; color: #27ae60;">${winner}</p>
    `;

    resultModal.classList.remove('active');
    gameOverModal.classList.add('active');
}

// Format Time
function formatTime(seconds) {
    const mins = Math.floor(seconds / 60);
    const secs = seconds % 60;
    return `${String(mins).padStart(2, '0')}:${String(secs).padStart(2, '0')}`;
}

// Initialize on page load
document.addEventListener('DOMContentLoaded', () => {
    levelSelect.value = '1';
    updateSelectedRodDisplay(1);
    updateSelectedRodDisplay(2);
});
