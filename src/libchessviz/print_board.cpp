#include <iostream>
#include <libchessviz/print_board.h>
#include <unistd.h>

#define loadtime 3

using namespace std;

int countFigure(string line, int num_line, char edge)
{
    int diff = (int)line[num_line] - (int)edge;
    return diff;
}

void convertFigure(string line, motion& motion)
{
    motion.y1 = board_size - countFigure(line, 1, '0');
    motion.x1 = countFigure(line, 0, 'a');
    motion.y2 = board_size - countFigure(line, 4, '0');
    motion.x2 = countFigure(line, 3, 'a');
}

void printBoard(char boardrr[board_size][board_size])
{
    cout << endl;
    for (int i = 0; i < board_size; i++) {
        cout << board_size - i << " | ";
        for (int j = 0; j < board_size; j++)
            cout << boardrr[i][j] << " ";
        cout << endl;
    }
    cout << "  +-----------------" << endl;
    cout << "    a b c d e f g h" << endl;
}

void loadingAnimation(int move_cnt)
{
    if (move_cnt == 1 || move_cnt == 0)
        cout << "Загрузка игры";
                
    else {
        if (move_cnt % 2 != 0)
            cout << "Ход соперника   ";
        if (move_cnt % 2 == 0)
            cout << "Ваш ход    ";
    }
    cout << '-' << flush;
    for (int r = 0; r < loadtime; r++) {
        usleep(100000);
        cout << "\b\\" << flush;
        usleep(100000);
        cout << "\b|" << flush;
        usleep(100000);
        cout << "\b/" << flush;
        usleep(100000);
        cout << "\b-" << flush;
    }
}

void takeStep(
        char* step1,
        char* step2,
        int& board_line_pos,
        int& board_column_pos,
        int& board_line_pos2,
        int& board_column_pos2,
        int move_cnt_load,
        char boardrr[board_size][board_size])
{
    string left = "87654321";
    string bottom = "abcdefgh";
    char line = step1[1];
    char column = step1[0];
    board_line_pos = left.find(line);
    board_column_pos = bottom.find(column);
    char line2 = step2[1];
    char column2 = step2[0];
    board_line_pos2 = left.find(line2);
    board_column_pos2 = bottom.find(column2);
    move_cnt_load++;
    cout << endl;
    loadingAnimation(move_cnt_load);
    cout << endl;
    printBoard(boardrr);
}

void turnFigure(
        int x1, int y1, int x2, int y2, char boardrr[board_size][board_size])
{
    char buf_step = boardrr[x1][y1];
    boardrr[x1][y1] = ' ';
    boardrr[x2][y2] = buf_step;
}
