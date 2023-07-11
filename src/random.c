/*
** EPITECH PROJECT, 2023
** game_of_life_in_c
** File description:
** random.c
*/

#include "game_of_life.h"

void dinguerie(game_of_life *game)
{
    if (!game) return;

    for (int i = 0; i < game->nb_rows; i++) {
        for (int j = 0; j < game->nb_cols; j++) {
            if (rand() % 2) {
                game->map[i][j] = 'X';
            } else {
                game->map[i][j] = ' ';
            }
        }
    }
}
