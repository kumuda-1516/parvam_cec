# 🏯 Tower of Hanoi - 2 Player Game

A competitive two-player Tower of Hanoi game with split-screen display, timers, scoring system, and 5 difficulty levels.

## Features

✨ **Split-Screen Gameplay** - Both players play simultaneously on the same screen
⏱️ **Real-time Timers** - Individual timers for each player
📊 **Points System** - Scoring based on moves and time efficiency
🎮 **5 Difficulty Levels** - Easy (3 discs) to Extreme (7 discs)
⌨️ **Keyboard Controls Only** - No mouse needed!
📖 **Interactive Guide** - Learn how to play with built-in tutorial

## Game Objective

Move all discs from the first rod (Rod A) to the last rod (Rod C) following these rules:
- Only one disc can be moved at a time
- A larger disc cannot be placed on a smaller disc
- Complete the puzzle faster and with fewer moves to earn more points

## Player Controls

### Player 1 (Left Side)
- **Q** - Select Rod A
- **W** - Select Rod B
- **E** - Select Rod C
- **Space** - Pick/Place Disc

### Player 2 (Right Side)
- **U** - Select Rod A
- **I** - Select Rod B
- **O** - Select Rod C
- **Enter** - Pick/Place Disc

## Game Modes

### Level 1: Easy
- 3 Discs
- Minimum: 7 moves
- Great for learning the game mechanics

### Level 2: Medium
- 4 Discs
- Minimum: 15 moves
- Increased complexity

### Level 3: Hard
- 5 Discs
- Minimum: 31 moves
- Requires strategy

### Level 4: Very Hard
- 6 Discs
- Minimum: 63 moves
- Advanced challenge

### Level 5: Extreme
- 7 Discs
- Minimum: 127 moves
- Ultimate test of skill

## Scoring System

Points are calculated based on:
1. **Move Efficiency** - Higher ratio of minimum moves / actual moves = more points
2. **Speed Bonus** - Fast completion time adds bonus points
3. **Cumulative** - Points carry over through all 5 levels
4. **Winner** - Player with most total points at the end wins!

## How to Play

1. **Open the Game** - Open `index.html` in a web browser
2. **Select Difficulty** - Choose a level from the dropdown
3. **Click Start Game** - Begin playing
4. **Play** - Use your assigned keyboard keys to move discs
5. **Compete** - Try to beat your opponent in moves and time
6. **Progress** - Complete all 5 levels to become the champion

## Game Flow

- Both players start with the same puzzle on their side
- Each player moves discs independently
- When a player completes their puzzle, a completion screen shows their stats
- Continue through all 5 levels
- Final game over screen displays the ultimate champion

## Tips for Success

💡 **Optimal Strategy** - Solve in exactly 2^n - 1 moves (where n is number of discs)
⚡ **Speed Runs** - Finish fast to maximize bonus points
🧠 **Mental Math** - Remember: a smaller disc can be placed on a larger disc
🎯 **Focus** - Watch your opponent's progress to stay competitive

## Technical Details

- **HTML5** - Semantic markup structure
- **CSS3** - Modern styling with gradients and animations
- **Vanilla JavaScript** - Pure JS, no dependencies
- **Responsive Design** - Works on different screen sizes

## Browser Compatibility

- Chrome/Chromium
- Firefox
- Safari
- Edge
- Any modern browser supporting ES6 JavaScript

## File Structure

```
tower_of_hanoi/
├── index.html      # Main game HTML
├── styles.css      # Game styling
├── script.js       # Game logic
└── README.md       # This file
```

## Installation

No installation required! Simply:
1. Open `index.html` in your web browser
2. Enjoy the game!

## Keyboard Shortcuts

| Action | Player 1 | Player 2 |
|--------|----------|----------|
| Rod A | Q | U |
| Rod B | W | I |
| Rod C | E | O |
| Pick/Place | Space | Enter |

## Feedback & Tips

- The game saves your progress within each session
- Try to solve each level in the optimal number of moves
- Compete with a friend or family member
- Try speedrunning to maximize bonus points!

---

**Enjoy the game and may the best Tower of Hanoi player win! 🏆**
