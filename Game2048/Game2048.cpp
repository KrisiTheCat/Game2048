/**
*
* Solution to course project # 08
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2025/2026
*
* @author Kristina Stoyanova
* @idnumber 3MI0600635
* @compiler GCC
*
* Main file that manages the application flow and game loop.
*
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "helpers.h"

bool loadConfig(int& minS, int& maxS, int& maxNick, int& leadCount) {
    std::ifstream file("config.txt");
    if (!file.is_open()) return false;
    char key[100];
    file >> key >> minS;
    file >> key >> maxS;
    file >> key >> maxNick;
    file >> key >> leadCount;
    file.close();
    return true;
}

void showMenu() {
    std::cout << "\n--- 2048 GAME ---\n";
    std::cout << "1. Start Game\n2. Leaderboard\n3. Exit\nChoice: ";
}

void handleStartGame(int minS, int maxS, int maxNick) {
    char nickname[101], cmd;
    int size, score = 0, board[BOARD_MAX][BOARD_MAX];
    std::cout << "Nickname: ";
    std::cin >> nickname;
    do {
        std::cout << "Board size (" << minS << "-" << maxS << "): ";
        std::cin >> size;
    } while (size < minS || size > maxS);

    initBoard(board, size);
    addRandomTile(board, size);
    addRandomTile(board, size);

    while (true) {
        printBoard(board, size, score);
        if (!canMove(board, size)) {
            std::cout << "Game Over! Your final score: " << score << "\n";
            break;
        }
        std::cout << "Move (w/a/s/d) or q to quit: ";
        std::cin >> cmd;
        if (cmd == 'q') break;
        bool moved = false;
        if (cmd == 'w') moved = moveUp(board, size, score);
        else if (cmd == 'a') moved = moveLeft(board, size, score);
        else if (cmd == 's') moved = moveDown(board, size, score);
        else if (cmd == 'd') moved = moveRight(board, size, score);

        if (moved) addRandomTile(board, size);
    }
}

int main() {
    std::srand(std::time(0));
    int minSize, maxSize, maxNick, leadCount;
    if (!loadConfig(minSize, maxSize, maxNick, leadCount)) return 1;

    int choice;
    while (true) {
        showMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        if (choice == 1) handleStartGame(minSize, maxSize, maxNick);
        else if (choice == 2) std::cout << "Leaderboard not ready.\n";
        else if (choice == 3) break;
    }
    return 0;
}