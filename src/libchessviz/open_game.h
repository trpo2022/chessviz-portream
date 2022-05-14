#pragma once

#include <libchessviz/figure_rules.h>
#include <libchessviz/print_board.h>

int readCommand(
        std::string line,
        motion motion,
        int move_cnt,
        char boardrr[board_size][board_size]);

int openNotation(
        std::string path, motion motion, char boardrr[board_size][board_size]);
