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
* File containing the game board logic and visualization.
*
*/

#include <iostream>
#include <cstdlib>
#include "helpers.h"

void initBoard(int board[BOARD_MAX][BOARD_MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }
}

void printBoard(int board[BOARD_MAX][BOARD_MAX], int size, int score) {
    std::cout << "\nScore: " << score << "\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                std::cout << ".\t";
            }
            else {
                std::cout << board[i][j] << "\t";
            }
        }
        std::cout << "\n\n";
    }
}

void addRandomTile(int board[BOARD_MAX][BOARD_MAX], int size) {
    int emptyRows[BOARD_MAX * BOARD_MAX];
    int emptyCols[BOARD_MAX * BOARD_MAX];
    int count = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                emptyRows[count] = i;
                emptyCols[count] = j;
                count++;
            }
        }
    }

    if (count > 0) {
        int index = std::rand() % count;
        int r = emptyRows[index];
        int c = emptyCols[index];
        board[r][c] = (std::rand() % 10 == 0) ? 4 : 2;
    }
}