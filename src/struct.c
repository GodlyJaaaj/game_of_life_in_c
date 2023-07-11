/*
** EPITECH PROJECT, 2023
** game_of_life_in_c
** File description:
** struct.c
*/

#include "game_of_life.h"

game_of_life *init_struct(long nb_rows, long nb_cols)
{
    game_of_life *game = (game_of_life *) malloc(sizeof(game_of_life));
    if (!game) exit(84);

    game->nb_rows = nb_rows;
    game->nb_cols = nb_cols;
    game->frame_rate = 1000;
    game->update_per_second = 50;

    //MAP
    game->map = (char **) malloc(sizeof(char *) * (nb_rows + 1));
    if (!game->map) exit(84);

    for (int i = 0; i < nb_rows; i++) {
        game->map[i] = (char *) malloc(sizeof(char) * (nb_cols + 1));
        if (!game->map[i]) exit(84);
        memset(game->map[i], ' ', (nb_cols + 1));
    }

    //MAP COPY
    game->map_copy = (char **) malloc(sizeof(char *) * (nb_rows + 1));
    if (!game->map_copy) exit(84);

    for (int i = 0; i < nb_rows; i++) {
        game->map_copy[i] = (char *) malloc(sizeof(char) * (nb_cols + 1));
        if (!game->map_copy[i]) exit(84);
        memset(game->map_copy[i], ' ', (nb_cols + 1));
    }

    game->map[nb_rows] = NULL;
    game->map_copy[nb_rows] = NULL;
    return game;
}

void free_struct(game_of_life *game)
{
    for (int i = 0; i < game->nb_rows; i++) {
        free(game->map[i]);
        free(game->map_copy[i]);
    }
    free(game->map);
    free(game->map_copy);
    free(game);
}
