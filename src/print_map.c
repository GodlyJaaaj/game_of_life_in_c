/*
** EPITECH PROJECT, 2023
** game_of_life_in_c
** File description:
** print_map.c
*/

#include "game_of_life.h"

void print_map_n(game_of_life *game)
{
    if (!game) return;

    char **map = game->map;
    long nb_rows = game->nb_rows;

    for (int i = 0; i < nb_rows; i++) {
        mvprintw(i, 0, "%s", map[i]);
    }
    mvprintw(1, 0, "%d FPS %ld x %ld", game->frame_rate, game->nb_cols, game->nb_rows);
}
