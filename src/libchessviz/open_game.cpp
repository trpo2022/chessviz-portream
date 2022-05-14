#include <cstddef>
#include <fstream>
#include <iostream>
#include <libchessviz/open_game.h>

using namespace std;

int readCommand(
        string line,
        motion motion,
        int move_cnt,
        char boardrr[board_size][board_size])
{
    int flag;
    size_t format = line.find_first_of("KQRBN");
    size_t format2
            = line.find_first_of("qwrtyuiop{}[]sjkl;'zvnm,./?~!@#$%^&*()_=");
    while (format != string::npos) {
        line.erase(line.begin() + format);
        format = line.find_first_of("KQRBN", format + 1);
    }
    while (format2 != string::npos) {
        flag = 25;
        if (checkStep(line, motion, boardrr, true, flag) == false)
            break;
        line.erase(line.begin() + format2);
        format2 = line.find_first_of(
                "qwrtyuiop{}[]sjkl;'zvnm,./?~!@#$%^&*()_=", format2);
        break;
    }
    if (line.find("x"))
        flag = 13;
    if (line.find("x"))
        flag = 10;
    int t = line.find_first_of("-x");
    int s = line.length();
    int pos_gor1, pos_ver1, pos_gor2, pos_ver2;
    bool output = true;
    char step_start[t], step_end[s];
    for (int i = 0; i < t; i++) {
        step_start[i] = line[i];
    }
    for (int i = t + 1, j = 0; i < s; i++, j++) {
        step_end[j] = line[i];
    }
    takeStep(
            step_start,
            step_end,
            pos_gor1,
            pos_ver1,
            pos_gor2,
            pos_ver2,
            move_cnt,
            boardrr);
    convertFigure(line, motion);
    if (checkStep(line, motion, boardrr, output, flag) == true) {
        turnFigure(pos_gor1, pos_ver1, pos_gor2, pos_ver2, boardrr);
        return 0;
    } else
        return 1;
    move_cnt++;
}

int openNotation(
        string path, motion motion, char boardrr[board_size][board_size])
{
    ifstream notation;
    notation.open(path);

    if (!notation.is_open()) {
        cout << endl;
        cout << "Ошибка считывания сценария партии!" << endl;
        return 44;
    } else {
        string mv;
        int cnt = 0;
        for (notation >> mv; !notation.eof() + 1; notation >> mv) {
            if (readCommand(mv, motion, cnt++, boardrr) != 0)
                break;
        }
        cout << endl;
        loadingAnimation(cnt);
    }
    notation.close(); //закрываем чтение
    return 0;
}
