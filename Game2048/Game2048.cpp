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
* Main file that manages the application flow and configuration.
*
*/

#include <iostream>
#include <fstream>
#include "helpers.h"

bool loadConfig(int& minS, int& maxS, int& maxNick, int& leadCount) {
    std::ifstream file("config.txt");
    if (!file.is_open()) {
        return false;
    }

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
    std::cout << "1. Start Game\n";
    std::cout << "2. Leaderboard\n";
    std::cout << "3. Exit\n";
    std::cout << "Choice: ";
}

void handleStartGame(int minS, int maxS, int maxNick) {
    char nickname[101];
    int size;

    std::cout << "Enter nickname: ";
    std::cin >> nickname;

    do {
        std::cout << "Board size (" << minS << "-" << maxS << "): ";
        std::cin >> size;
    } while (size < minS || size > maxS);

    std::cout << "Game starts for " << nickname << "...\n";
}

int main() {
    int minSize = 0;
    int maxSize = 0;
    int maxNickLen = 0;
    int leaderboardCount = 0;

    if (!loadConfig(minSize, maxSize, maxNickLen, leaderboardCount)) {
        std::cerr << "Error: Config file not found!\n";
        return 1;
    }

    int choice;
    bool isRunning = true;

    while (isRunning) {
        showMenu();

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            handleStartGame(minSize, maxSize, maxNickLen);
        }
        else if (choice == 2) {
            std::cout << "Leaderboard not implemented yet.\n";
        }
        else if (choice == 3) {
            isRunning = false;
        }
    }

    return 0;
}
