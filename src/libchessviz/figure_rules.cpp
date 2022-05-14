#include <iostream>
#include <libchessviz/figure_rules.h>
#include <math.h>

using namespace std;

bool king_step(
        char boardrr[board_size][board_size], motion motion, bool error_output)
{
    if ((boardrr[motion.y1][motion.x1] == 'K')
        || (boardrr[motion.y1][motion.x1] == 'k')) {
        if (!(boardrr[motion.y2][motion.x2] == ' '
              && (abs(motion.y2 - motion.y1) == 1
                  || abs(motion.x2 - motion.x1) == 1))) {
            if (error_output == true)
                cout << "\nНеправильный ход" << endl;
            return false;
        } else
            return true;
        if (error_output == true)
            cout << "\nНеправильный тип фигуры" << endl;
        return false;
    } else
        return true;
}

bool queen_step(
        char boardrr[board_size][board_size], motion motion, bool error_output)
{
    if ((boardrr[motion.y1][motion.x1] == 'Q')
        || (boardrr[motion.y1][motion.x1] == 'q')) {
        if (!(boardrr[motion.y2][motion.x2] == ' '
              && (motion.x1 == motion.x2 || motion.y1 == motion.y2
                  || (abs(motion.y2 - motion.y1)
                      == abs(motion.x2 - motion.x1))))) {
            if (error_output == true)
                cout << "\nНеправильный ход" << endl;
            return false;
        } else
            return true;
        if (error_output == true)
            cout << "\nНеправильный тип фигуры" << endl;
        return false;
    } else
        return true;
}

bool rook_step(
        char boardrr[board_size][board_size], motion motion, bool error_output)
{
    if ((boardrr[motion.y1][motion.x1] == 'R')
        || (boardrr[motion.y1][motion.x1] == 'r')) {
        if (!(boardrr[motion.y2][motion.x2] == ' '
              && (motion.x1 == motion.x2 || motion.y1 == motion.y2))) {
            if (error_output == true)
                cout << "\nНеправильный ход" << endl;
            return false;
        } else
            return true;
        if (error_output == true)
            cout << "\nНеправильный тип фигуры" << endl;
        return false;
    } else
        return true;
}

bool knight_step(
        char boardrr[board_size][board_size], motion motion, bool error_output)
{
    if ((boardrr[motion.y1][motion.x1] == 'N')
        || (boardrr[motion.y1][motion.x1] == 'n')) {
        if (!(boardrr[motion.y2][motion.x2] == ' '
              && (pow(motion.x2 - motion.x1, 2) + pow(motion.y2 - motion.y1, 2))
                      == 5)) {
            if (error_output == true)
                cout << "\nНеправильный ход" << endl;
            return false;
        } else
            return true;
        if (error_output == true)
            cout << "\nНеправильный тип фигуры" << endl;
        return false;
    } else
        return true;
}

bool bishop_step(
        char boardrr[board_size][board_size], motion motion, bool error_output)
{
    if ((boardrr[motion.y1][motion.x1] == 'B')
        || (boardrr[motion.y1][motion.x1] == 'b')) {
        if (!(boardrr[motion.y2][motion.x2] == ' '
              && abs(motion.y2 - motion.y1) == abs(motion.x2 - motion.x1))) {
            if (error_output == true)
                cout << "\nНеправильный ход" << endl;
            return false;
        } else
            return true;
        if (error_output == true)
            cout << "\nНеправильный тип фигуры" << endl;
        return false;
    } else
        return true;
}

bool pawn_step(
        string step,
        motion motion,
        char boardrr[board_size][board_size],
        bool error_output,
        bool silent,
        bool checkmate)
{
    if (boardrr[motion.y1][motion.x1] == ' ' && checkmate == false) {
        if (error_output == true)
            cout << "\nВы не можете взять пустую клетку" << endl;
        return false;
    }

    else if (boardrr[motion.y1][motion.x1] == ' ' && checkmate == true) {
        if (error_output == true)
            cout << "\nШах и мат!!!" << endl;
        return false;
    }

    if ((motion.x1 > 7) || (motion.x1 < 0) || (motion.x2 > 7) || (motion.x2 < 0)
        || (motion.y1 > 7) || (motion.y1 < 0) || (motion.y2 > 7)
        || (motion.y2 < 0)) {
        if (error_output == true)
            cout << "\nВыход за пределы доски" << endl;
        return false;
    }

    if ((boardrr[motion.y1][motion.x1] == 'P')
        || (boardrr[motion.y1][motion.x1] == 'p')) {
        if (!(boardrr[motion.y2][motion.x2] == ' ' && motion.x1 == motion.x2
              && abs(motion.y2 - motion.y1) <= 2)) {
            if (error_output == true)
                cout << "\nПешки двигаются только прямо" << endl;
            return false;
        } else
            return true;
        if (error_output == true)
            cout << "\nНеправильный тип фигуры" << endl;
        return false;
    } else
        return true;
    if (silent) {
        if (motion.x1 != motion.x2) {
            if (error_output == true)
                cout << "\nПешки двигаются только прямо" << endl;
            return false;
        }
        if (boardrr[motion.y1][motion.x1] == ' ') {
            if (error_output == true)
                cout << "\nВы не можете сделать тихий ход на другую фигуру"
                     << endl;
            return false;
        }
        if (boardrr[motion.y1][motion.x1] == 'P') {
            if (motion.y1 == 6) {
                if ((motion.y1 - motion.y2 > 2)
                    || (motion.y1 - motion.y2 < 1)) {
                    if (error_output == true)
                        cout << "\nНачиная с первого хода, пешки могут "
                                "перемещаться на 1-2 клетки"
                             << endl;
                    return false;
                }
                if ((motion.y1 - motion.y2 == 2)
                    && (boardrr[(motion.y1 + motion.y2) / 2][motion.x1]
                        != ' ')) {
                    if (error_output == true)
                        cout << "\nВы не можете переступить" << endl;
                    return false;
                }
            } else {
                if (motion.y1 - motion.y2 != 1) {
                    if (error_output == true)
                        cout << "\nПосле первого хода пешки могут двигаться "
                                "только на 1 клетку вперед"
                             << endl;
                    return false;
                }
            }
        }
        if (boardrr[motion.y1][motion.x1] == 'p') {
            if (motion.y1 == 1) {
                if ((motion.y2 - motion.y1 > 2)
                    || (motion.y2 - motion.y1 < 1)) {
                    if (error_output == true)
                        cout << "\nНачиная с первого хода, пешки могут "
                                "перемещаться на 1-2 клетки"
                             << endl;
                    return false;
                }
                if ((motion.y2 - motion.y1 == 2)
                    && (boardrr[(motion.y1 + motion.y2) / 2][motion.x1]
                        != ' ')) {
                    if (error_output == true)
                        cout << "\nВы не можете переступить" << endl;
                    return false;
                }

            } else {
                if (motion.y2 - motion.y1 != 1) {
                    if (error_output == true)
                        cout << "\nПосле первого хода пешки могут двигаться "
                                "только на 1 клетку вперед"
                             << endl;
                    return false;
                }
            }
        }
    }
    if (silent == false || step[2] == 'x') {
        if (boardrr[motion.y1][motion.x1] == ' ') {
            if (error_output == true)
                cout << "\nВы не можете взять пустую клетку" << endl;
            return false;
        }
        if (abs(motion.x1 - motion.x2) != 1) {
            if (error_output == true)
                cout << "\nВы можете взять только 1 клетку по диагонали в "
                        "стороны"
                     << endl;
            return false;
        }
        if ((boardrr[motion.y1][motion.x1] == 'P')
            && (motion.y1 - motion.y2 != 1)) {
            if (error_output == true)
                cout << "\nВы можете взять только 1 клетку по диагонали в "
                        "стороны"
                     << endl;
            return false;
        }
        if ((boardrr[motion.y1][motion.x1] == 'p')
            && (motion.y2 - motion.y1 != 1)) {
            if (error_output == true)
                cout << "\nВы можете взять только 1 клетку по диагонали в "
                        "стороны"
                     << endl;
            return false;
        }
        if (error_output == true)
            cout << "\nВы не можете атаковать свои фигуры" << endl;
        return false;
    }
    return true;
}

bool checkStep(
        string step,
        motion motion,
        char boardrr[board_size][board_size],
        bool output,
        int flag)
{
    bool error_output, silent, take, checkmate;
    if (output == false)
        error_output = false;
    else
        error_output = true;
    if (flag == 10)
        checkmate = true;
    if (flag == 13) {
        take = true;
        silent = false;
    } else if (flag != 25) {
        take = false;
        silent = true;
    }
    switch (step.size()) {
    case 5:
        if (pawn_step(step, motion, boardrr, error_output, silent, checkmate)
            == false)
            return false;
        break;
    case 6:
        if (checkmate == false) {
            if ((motion.x1 > 7) || (motion.x1 < 0) || (motion.x2 > 7)
                || (motion.x2 < 0) || (motion.y1 > 7) || (motion.y1 < 0)
                || (motion.y2 > 7) || (motion.y2 < 0)) {
                if (error_output == false)
                    cout << "\nВыход за пределы доски" << endl;
                return false;
            }
            if (silent == true) {
                if (output == true)
                    cout << "\nНеизвестный тип шага" << endl;
                return false;
            }
            if (boardrr[motion.y1][motion.x1] == ' ') {
                if (output == true)
                    cout << "\nНачальная клетка пуста" << endl;
                return false;
            }
            if ((boardrr[motion.y2][motion.x2] != ' ') && (step[3] == '-')) {
                if (output == true)
                    cout << "\nВы не можете сделать тихий ход на другую фигуру"
                         << endl;
                return false;
            }
            if ((boardrr[motion.y2][motion.x2] == ' ') && (step[3] == 'x')) {
                if (output == true)
                    cout << "\nВы не можете взять пустую клетку" << endl;
                return false;
            }
            if ((((boardrr[motion.y2][motion.x2] >= 65)
                  && (boardrr[motion.y2][motion.x2] <= 90)))
                || (((boardrr[motion.y2][motion.x2] >= 97)
                     && (boardrr[motion.y2][motion.x2] <= 122)))) {
                if (output == true)
                    cout << "\nВы не можете атаковать свои фигуры" << endl;
                return false;
            }
        }
        if (checkmate == true) {
            if (silent == false) {
                if (output == true)
                    cout << "\nНеправильный мат" << endl;
                return false;
            }
            if (pawn_step(
                        step, motion, boardrr, error_output, silent, checkmate)
                == false)
                return false;
        }
        break;
    case 7:
        error_output = false;
        if (checkmate == false) {
            if (output == true)
                cout << "\nНеправильный шаг" << endl;
            return false;
        }
        if (take != true) {
            if (output == true)
                cout << "\nНеправильный мат" << endl;
            return false;
        }
        if ((((boardrr[motion.y2][motion.x2] >= 65)
              && (boardrr[motion.y2][motion.x2] <= 90)))
            || (((boardrr[motion.y2][motion.x2] >= 97)
                 && (boardrr[motion.y2][motion.x2] <= 122)))) {
            if (output == true)
                cout << "\nВы не можете атаковать свои фигуры" << endl;
            return false;
        }
        if ((knight_step(boardrr, motion, error_output) == false)
            && (king_step(boardrr, motion, error_output) == false)
            && (queen_step(boardrr, motion, error_output) == false)
            && (rook_step(boardrr, motion, error_output) == false)
            && (knight_step(boardrr, motion, error_output) == false))
            return false;
        break;
    default:
        return false;
        break;
    }
    return true;
}
