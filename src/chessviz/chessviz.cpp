#include <iostream>
#include <libchessviz/figure_rules.h>
#include <libchessviz/open_game.h>
#include <libchessviz/print_board.h>

using namespace std;

int main()
{
    system("clear"); //очищаем консоль чтоб было больше места
    motion motion;
    setlocale(LC_ALL, "rus");
    char boardrr[board_size][board_size] // board + array = boardrr
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    string path = "scholars_mate.txt"; //путь к сценарию
    openNotation(path, motion, boardrr);
    cout << endl;
    printBoard(boardrr);
    cout << ' ' << endl;
    return 0;
}
