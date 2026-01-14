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
* File managing the persistence of top scores.
*
*/

#include <iostream>
#include <fstream>
#include "helpers.h"

void getFileName(int size, char* fileName) {
    fileName[0] = 'l'; fileName[1] = 'e'; fileName[2] = 'a'; fileName[3] = 'd';
    fileName[4] = '_'; fileName[5] = (size / 10) + '0'; fileName[6] = (size % 10) + '0';
    fileName[7] = '.'; fileName[8] = 't'; fileName[9] = 'x'; fileName[10] = 't';
    fileName[11] = '\0';
}

void updateLeaderboard(int size, const char* name, int score) {
    char fileName[15];
    getFileName(size, fileName);

    char names[MAX_TOP][101];
    int scores[MAX_TOP] = { 0 };
    int count = 0;

    std::ifstream in(fileName);
    if (in.is_open()) {
        while (count < MAX_TOP && in >> names[count] >> scores[count]) {
            count++;
        }
        in.close();
    }

    if (count < MAX_TOP || score > scores[MAX_TOP - 1]) {
        int pos = count < MAX_TOP ? count : MAX_TOP - 1;
        while (pos > 0 && score > scores[pos - 1]) {
            for (int i = 0; i < 101; i++) names[pos][i] = names[pos - 1][i];
            scores[pos] = scores[pos - 1];
            pos--;
        }
        for (int i = 0; i < 101; i++) names[pos][i] = name[i];
        scores[pos] = score;
        if (count < MAX_TOP) count++;
    }

    std::ofstream out(fileName);
    for (int i = 0; i < count; i++) {
        out << names[i] << " " << scores[i] << "\n";
    }
    out.close();
}

void showLeaderboard(int size) {
    char fileName[15];
    getFileName(size, fileName);
    std::ifstream in(fileName);
    std::cout << "\n--- TOP SCORES FOR " << size << "x" << size << " ---\n";
    if (!in.is_open()) {
        std::cout << "No records yet.\n";
        return;
    }
    char name[101];
    int score, rank = 1;
    while (in >> name >> score) {
        std::cout << rank++ << ". " << name << ": " << score << "\n";
    }
    in.close();
}