#include <ctest.h>
#include <iostream>
#include <libchessviz/figure_rules.h>
#include <libchessviz/open_game.h>
#include <libchessviz/print_board.h>

using namespace std;

char boardrr[board_size][board_size]
        = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
           {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
           {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

motion motion;

CTEST(read_txt, simple_read_file)
{
    FILE* file = fopen("test.txt", "r");
    char result[6];
    fgets(result, 6, file);
    fclose(file);

    const char expected[6] = {'e', '2', '-', 'e', '4'};

    ASSERT_STR(result, expected);
}

CTEST(quiet_step_suite, step_size_false)
{
    string step = "Nb1-c3B";
    convertFigure(step, motion);
    bool result = checkStep(step, motion, boardrr, true, false);

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, quiet_running_true)
{
    string step = "e2-e4";
    convertFigure(step, motion);
    bool result = checkStep(step, motion, boardrr, true, false);

    ASSERT_TRUE(result);
}

CTEST(quiet_step_suite, quiet_running_false2)
{
    string step = "Be1'e4";
    convertFigure(step, motion);
    bool result = checkStep(step, motion, boardrr, true, false);

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, small_type)
{
    string step = "nb1-c3";
    convertFigure(step, motion);
    bool result = checkStep(step, motion, boardrr, true, false);

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, move_from_empty_cell)
{
    string step = "e3-e4";
    convertFigure(step, motion);
    bool result = checkStep(step, motion, boardrr, true, false);

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, going_out_of_field)
{
    string step = "e0-e2";
    convertFigure(step, motion);
    bool result = checkStep(step, motion, boardrr, true, false);

    ASSERT_FALSE(result);
}

CTEST(pawn_step, type_is_true)
{
    string step = "e2-e3";
    convertFigure(step, motion);
    bool result = checkStep(step, motion, boardrr, true, false);

    ASSERT_TRUE(result);
}

CTEST(king_step, type_is_false)
{
    string step = "Ke2-e3";
    convertFigure(step, motion);
    bool result = checkStep(step, motion, boardrr, true, false);

    ASSERT_FALSE(result);
}

CTEST(queen_step, stepping_over_is_false)
{
    string step = "Qd1-d4";
    convertFigure(step, motion);
    bool result = checkStep(step, motion, boardrr, true, false);

    ASSERT_FALSE(result);
}

CTEST(rook_step, stepping_over_is_false)
{
    string step = "Ra1-a4";
    convertFigure(step, motion);
    bool result = checkStep(step, motion, boardrr, true, false);

    ASSERT_FALSE(result);
}

CTEST(bishop_step, step_is_false)
{
    string step = "Bc1-e3";
    convertFigure(step, motion);
    bool result = checkStep(step, motion, boardrr, true, false);

    ASSERT_FALSE(result);
}
