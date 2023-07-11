/*
** EPITECH PROJECT, 2023
** game_of_life_in_c
** File description:
** game_loop.c
*/

#include "game_of_life.h"

void game_loop(game_of_life *game)
{
    // FRAMERATE
    clock_t start_time = clock();
    clock_t clock2 = clock();

    int nb_operations = 0;
    int counter = 0;
    //

    int key;

    while ((key = getch()) != 'q') {

        //FRAMERATE
        clock_t end_time = clock();
        if ((double)(end_time - start_time) / CLOCKS_PER_SEC > 1.0) {
            start_time = clock();
            game->frame_rate = nb_operations;
            nb_operations = 0;
        }
        //
        if ((double)(end_time - clock2) / CLOCKS_PER_SEC > (1.0 / game->frame_rate)) {
            clock2 = clock();
            print_map_n(game);
            refresh();
            if (counter > game->update_per_second) {
                counter = 0;
                process(game);
            }
            counter++;
        }
        check_edit_mode(key, game);
        nb_operations++;

    }
}
