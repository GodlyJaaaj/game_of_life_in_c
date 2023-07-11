/*
** EPITECH PROJECT, 2023
** game_of_life_in_c
** File description:
** save_to_file.c
*/

#include "game_of_life.h"
#include "fcntl.h"
#include "unistd.h"

void save_to_file(game_of_life *game)
{
    echo();

    char buffer[50] = {0};
    char file_name[100] = {0};

    do {
        clear();
        mvprintw(0, 0, "Do you want to save the current map in a file ? (y/n)");
        scanw("%s", buffer);
    } while (buffer[0] != 'n' && buffer[0] != 'y');
    if (buffer[0] == 'n') return;

    clear();
    mvprintw(0, 0, "Enter file name: ");
    scanw("%s", file_name);

    int fd;
    if ((fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, S_IRUSR | S_IWUSR))) {
        for (int i = 0; i < game->nb_rows; i++) {
            write(fd, game->map[i], game->nb_cols);
            write(fd, "\n", 1);
        }
    } else {
        exit(84);
    }

    close(fd);
    noecho();
}