/*
** EPITECH PROJECT, 2023
** game_of_life_in_c
** File description:
** edit_mode.c
*/

#include "game_of_life.h"

void print_edit_mode(void)
{
    mvprintw(0, 0, "%s", EDIT);
}

void manage_input(int *x, int *y, int key, game_of_life *game)
{
    MEVENT event;
    char **temp;
    switch (key) {
        case KEY_MOUSE:
            if (getmouse(&event) == OK) {
                if (event.bstate & BUTTON1_CLICKED) {
                    move((*y = event.y), (*x = event.x));
                    refresh();
                }
            } break;
        case KEY_UP:
            (*y - 1 >= 0 ? move(--(*y), *x) : 0);
            break;
        case KEY_DOWN:
            (*y + 1 < game->nb_rows ? move(++(*y), *x) : 0);
            break;
        case KEY_LEFT:
            (*x - 1 >= 0 ? move(*y, --(*x)) : 0);
            break;
        case KEY_RIGHT:
            (*x + 1 < game->nb_cols ? move(*y, ++(*x)) : 0);
            break;
        case 'x':
        case 'X':
            game->map[*y][*x] = 'X';
            break;
        case 'w':
        case 'W':
            game->map[*y][*x] = ' ';
            break;
        case 'n':
            dinguerie(game);
            break;
        case 'm':
            temp = game->map;
            game->map = game->map_copy;
            game->map_copy = temp;
            break;
        case 's':
            save_to_file(game);
            break;
        case 'c':
            clear_map(game);
            break;
        default:
            break;
    }
    refresh();
}

void edit_mode(game_of_life *game)
{
    int key = 0;
    int x = 0;
    int y = 0;

    move(0, 0);

    while(key != 'q') {
        manage_input(&x, &y, key, game);
        print_map_n(game);
        print_edit_mode();
        move(y, x);
        refresh();
        key = getch();
    }
}

void check_edit_mode(int key, game_of_life *game)
{
    if (key == 'e') {
        nodelay(stdscr, FALSE);
        curs_set(TRUE);

        edit_mode(game);

        nodelay(stdscr, TRUE);
        curs_set(FALSE);
    }
}