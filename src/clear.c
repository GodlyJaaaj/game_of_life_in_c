/*
** EPITECH PROJECT, 2023
** game_of_life_in_c
** File description:
** clear.c
*/

#include "game_of_life.h"

void clear_map(game_of_life *game)
{
    for (int i = 0; i < game->nb_rows; i++) {
        memset(game->map[i], ' ', game->nb_cols);
    }
}
