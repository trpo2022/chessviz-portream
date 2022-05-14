#pragma once

#include <string>

#define board_size 8

struct motion {
    int y1;
    int x1;
    int y2;
    int x2;
};

int countFigure(std::string line, int num_line, char edge);

void convertFigure(std::string line, motion& motion);

void printBoard(char boardrr[board_size][board_size]);

void loadingAnimation(int move_cnt);

void takeStep(
        char* step1,
        char* step2,
        int& board_line_pos,
        int& board_column_pos,
        int& board_line_pos2,
        int& board_column_pos2,
        int move_cnt_load,
        char boardrr[board_size][board_size]);

void turnFigure(
        int x1, int y1, int x2, int y2, char boardrr[board_size][board_size]);
