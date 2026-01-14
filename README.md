# Console 2048 - FMI Project

A classic console-based implementation of the 2048 game, developed as a course project for the "Introduction to Programming" practicum at Sofia University, FMI.

## Features
* **Customizable Board Size:** Choose any size between 4x4 and 10x10.
* **Score Tracking:** Real-time scoring based on tile merges.
* **Leaderboard System:** Saves the top 5 scores in separate text files for each board size.
* **Configurable Settings:** Loads basic constraints from an external `config.txt` file.

## How to Run
1. Ensure `config.txt` is in the same directory as the executable.
2. Compile all `.cpp` files together (e.g., `g++ main.cpp game.cpp leaderboard.cpp -o 2048`).
3. Run the generated executable.

## Controls
* `w` - Move Up
* `a` - Move Left
* `s` - Move Down
* `d` - Move Right
* `q` - Quit current game

## Project Structure
* `main.cpp` - Entry point and menu management.
* `game.cpp` - Core game logic (movement, merging, board initialization).
* `leaderboard.cpp` - File I/O for saving and displaying high scores.
* `helpers.h` - Function declarations and shared constants.
* `config.txt` - External configuration file.

## Author
* **Name:** Kristina Stoyanova
* **Faculty Number:** 3MI0600635
* **Compiler:** VCC
