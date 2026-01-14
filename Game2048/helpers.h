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
* Header file containing function declarations and global constants.
*
*/

#ifndef HELPERS_H
#define HELPERS_H

const int BOARD_MAX = 10;
const int MAX_TOP = 5;

bool loadConfig(int& minS, int& maxS, int& maxNick, int& leadCount);
void showMenu();
void handleStartGame(int minS, int maxS, int maxNick);

void initBoard(int board[BOARD_MAX][BOARD_MAX], int size);
void printBoard(int board[BOARD_MAX][BOARD_MAX], int size, int score);
void addRandomTile(int board[BOARD_MAX][BOARD_MAX], int size);

bool moveLeft(int board[BOARD_MAX][BOARD_MAX], int size, int& score);
bool moveRight(int board[BOARD_MAX][BOARD_MAX], int size, int& score);
bool moveUp(int board[BOARD_MAX][BOARD_MAX], int size, int& score);
bool moveDown(int board[BOARD_MAX][BOARD_MAX], int size, int& score);
bool canMove(int board[BOARD_MAX][BOARD_MAX], int size);

void updateLeaderboard(int size, const char* name, int score);
void showLeaderboard(int size);

#endif