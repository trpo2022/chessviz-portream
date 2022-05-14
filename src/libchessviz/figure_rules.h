#pragma once

#include <libchessviz/print_board.h>

bool king_step(
        char boardrr[board_size][board_size], motion motion, bool error_output);

bool queen_step(
        char boardrr[board_size][board_size], motion motion, bool error_output);

bool rook_step(
        char boardrr[board_size][board_size], motion motion, bool error_output);

bool knight_step(
        char boardrr[board_size][board_size], motion motion, bool error_output);

bool bishop_step(
        char boardrr[board_size][board_size], motion motion, bool error_output);

bool pawn_step(
        std::string step,
        char boardrr[board_size][board_size],
        motion motion,
        bool error_output,
        bool silent,
        bool checkmate);

bool checkStep(
        std::string step,
        motion motion,
        char boardrr[board_size][board_size],
        bool output,
        int flag);
