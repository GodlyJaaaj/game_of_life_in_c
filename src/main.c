/*
** EPITECH PROJECT, 2023
** game_of_life_in_c
** File description:
** game_of_life_in_c
*/

#include "game_of_life.h"

int main(int argc, char **argv)
{
    srand(time(NULL));

    initscr();
    noecho();
    cbreak();
    mousemask(ALL_MOUSE_EVENTS, NULL);

    curs_set(FALSE);
    keypad(stdscr, true);
    nodelay(stdscr, TRUE);

    game_of_life *game = init_struct(LINES, COLS);

    game_loop(game);

    endwin();
    free_struct(game);
    return 0;
}
