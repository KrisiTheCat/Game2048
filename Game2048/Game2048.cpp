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
* Main file managing application flow and leaderboard access.
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
    file >> key >> minS >> key >> maxS >> key >> maxNick >> key >> leadCount;
    file.close();
    return true;
}

void showMenu() {
    std::cout << "\n--- 2048 GAME ---\n1. Start Game\n2. Leaderboard\n3. Exit\nChoice: ";
}

void handleStartGame(int minS, int maxS, int maxNick) {
    char nickname[101], cmd;
    int size, score = 0, board[BOARD_MAX][BOARD_MAX];
    std::cout << "Nickname: "; std::cin >> nickname;
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
            std::cout << "Game Over! Score: " << score << "\n";
            updateLeaderboard(size, nickname, score);
            break;
        }
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
    int minS, maxS, maxN, leadC;
    if (!loadConfig(minS, maxS, maxN, leadC)) return 1;

    int choice;
    while (true) {
        showMenu();
        if (!(std::cin >> choice)) { std::cin.clear(); std::cin.ignore(1000, '\n'); continue; }
        if (choice == 1) handleStartGame(minS, maxS, maxN);
        else if (choice == 2) {
            int s;
            std::cout << "Size: "; std::cin >> s;
            showLeaderboard(s);
        }
        else if (choice == 3) break;
    }
    return 0;
}