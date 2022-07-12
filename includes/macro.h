/*
** EPITECH PROJECT, 2022
** macro.h
** File description:
** .h file
*/

#ifndef MACRO_H_
    #define MACRO_H_

    #include "curses.h"
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <getopt.h>
    #include <dirent.h>
    #include <time.h>

    #define ERROR_FILE 84
    #define ERROR_ARG 84
    #define UNCORRECT_SIZE 84
    #define UNCORRECT_FORMAT 84
    #define UNCORRECT_KEY 84

    #define DEFAULT_SETTINGS 1
    #define CUSTOM_SETTINGS 0

    #define WINDOW_SIZE_ROWS 50
    #define WINDOW_SIZE_COLS 190

    #define RESIZE_MESSAGE "RESIZE THE WINDOW AT FULLSCREEN TO PLAY"

#endif /* !MACRO_H_ */
