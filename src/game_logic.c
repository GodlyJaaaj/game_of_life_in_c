/*
** EPITECH PROJECT, 2023
** game_of_life_in_c
** File description:
** game_logic.c
*/

#include "game_of_life.h"

short get_neighbors(int y, int x, game_of_life *game)
{
    short neighbors = 0;
    if (y - 1 >= 0) {
        if (x - 1 >= 0 && game->map[y - 1][x - 1] == 'X')
            neighbors++;
        if (game->map[y - 1][x] == 'X')
            neighbors++;
        if (x + 1 < game->nb_cols && game->map[y - 1][x + 1] == 'X')
            neighbors++;
    }
    if (x - 1 >= 0 && game->map[y][x - 1] == 'X')
        neighbors++;
    if (x + 1 < game->nb_cols && game->map[y][x + 1] == 'X')
        neighbors++;
    if (y + 1 < game->nb_rows) {
        if (x - 1 >= 0 && game->map[y + 1][x - 1] == 'X')
            neighbors++;
        if (game->map[y + 1][x] == 'X')
            neighbors++;
        if (x + 1 < game->nb_cols && game->map[y + 1][x + 1] == 'X')
            neighbors++;
    }
    return neighbors;
}

void process(game_of_life *game)
{
    for (int i = 0; i < game->nb_rows; i++) {
        for (int j = 0; j < game->nb_cols; j++) {
            short neighbors = get_neighbors(i, j, game);
            if (neighbors == 3 && game->map[i][j] == ' ')
                game->map_copy[i][j] = 'X';
            if ((neighbors < 2 || neighbors > 3) && game->map[i][j] == 'X')
                game->map_copy[i][j] = ' ';
            if (game->map[i][j] == 'X' && (neighbors == 2 || neighbors == 3))
                game->map_copy[i][j] = 'X';
        }
    }

    char **temp = game->map;
    game->map = game->map_copy;
    game->map_copy = temp;

    for (int i = 0; i < game->nb_rows; i++) {
        memset(temp[i], ' ', game->nb_cols);
    }
}
