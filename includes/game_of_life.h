/*
** EPITECH PROJECT, 2023
** game_of_life_in_c
** File description:
** game_of_life.h
*/

#pragma once

#define EDIT "EDIT MODE"

#include "ncurses.h"
#include "malloc.h"
#include <stdlib.h>
#include "time.h"
#include "stddef.h"
#include "string.h"

typedef struct game_of_life {
    char **map;
    char **map_copy;
    long nb_cols;
    long nb_rows;
    int frame_rate;
    int update_per_second;
} game_of_life;

//STRUCT
game_of_life *init_struct(long nb_rows, long nb_cols);
void free_struct(game_of_life *game);

//GAME LOOP
void game_loop(game_of_life *game);
void process(game_of_life *game);
short get_neighbors(int y, int x, game_of_life *game);

//PRINT MAP
void print_map_n(game_of_life *game);

//EDIT MODE
void check_edit_mode(int key, game_of_life *game);
//DINGUERIE
void dinguerie(game_of_life *game);

//SAVE TO FILE
void save_to_file(game_of_life *game);

// CLEAR MAP
void clear_map(game_of_life *game);
