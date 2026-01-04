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
* File containing the game board logic and movement implementations.
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
        board[emptyRows[index]][emptyCols[index]] = (std::rand() % 10 == 0) ? 4 : 2;
    }
}

bool moveLeft(int board[BOARD_MAX][BOARD_MAX], int size, int& score) {
    bool moved = false;
    for (int i = 0; i < size; i++) {
        int lastPos = 0;
        for (int j = 1; j < size; j++) {
            if (board[i][j] != 0) {
                int col = j;
                while (col > lastPos && board[i][col - 1] == 0) {
                    board[i][col - 1] = board[i][col];
                    board[i][col] = 0;
                    col--;
                    moved = true;
                }
                if (col > lastPos && board[i][col - 1] == board[i][col]) {
                    board[i][col - 1] *= 2;
                    score += board[i][col - 1];
                    board[i][col] = 0;
                    lastPos = col;
                    moved = true;
                }
            }
        }
    }
    return moved;
}

bool moveRight(int board[BOARD_MAX][BOARD_MAX], int size, int& score) {
    bool moved = false;
    for (int i = 0; i < size; i++) {
        int lastPos = size - 1;
        for (int j = size - 2; j >= 0; j--) {
            if (board[i][j] != 0) {
                int col = j;
                while (col < lastPos && board[i][col + 1] == 0) {
                    board[i][col + 1] = board[i][col];
                    board[i][col] = 0;
                    col++;
                    moved = true;
                }
                if (col < lastPos && board[i][col + 1] == board[i][col]) {
                    board[i][col + 1] *= 2;
                    score += board[i][col + 1];
                    board[i][col] = 0;
                    lastPos = col;
                    moved = true;
                }
            }
        }
    }
    return moved;
}

bool moveUp(int board[BOARD_MAX][BOARD_MAX], int size, int& score) {
    bool moved = false;
    for (int j = 0; j < size; j++) {
        int lastPos = 0;
        for (int i = 1; i < size; i++) {
            if (board[i][j] != 0) {
                int row = i;
                while (row > lastPos && board[row - 1][j] == 0) {
                    board[row - 1][j] = board[row][j];
                    board[row][j] = 0;
                    row--;
                    moved = true;
                }
                if (row > lastPos && board[row - 1][j] == board[row][j]) {
                    board[row - 1][j] *= 2;
                    score += board[row - 1][j];
                    board[row][j] = 0;
                    lastPos = row;
                    moved = true;
                }
            }
        }
    }
    return moved;
}

bool moveDown(int board[BOARD_MAX][BOARD_MAX], int size, int& score) {
    bool moved = false;
    for (int j = 0; j < size; j++) {
        int lastPos = size - 1;
        for (int i = size - 2; i >= 0; i--) {
            if (board[i][j] != 0) {
                int row = i;
                while (row < lastPos && board[row + 1][j] == 0) {
                    board[row + 1][j] = board[row][j];
                    board[row][j] = 0;
                    row++;
                    moved = true;
                }
                if (row < lastPos && board[row + 1][j] == board[row][j]) {
                    board[row + 1][j] *= 2;
                    score += board[row + 1][j];
                    board[row][j] = 0;
                    lastPos = row;
                    moved = true;
                }
            }
        }
    }
    return moved;
}

bool canMove(int board[BOARD_MAX][BOARD_MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) return true;
            if (i < size - 1 && board[i][j] == board[i + 1][j]) return true;
            if (j < size - 1 && board[i][j] == board[i][j + 1]) return true;
        }
    }
    return false;
}