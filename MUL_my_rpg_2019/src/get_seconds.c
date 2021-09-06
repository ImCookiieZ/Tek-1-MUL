/*
** EPITECH PROJECT, 2019
** Marcel Taubert - > get_seconds.c
** File description:
** sldfj
*/

#include "../include/all_includes.h"

float get_seconds(sfTime time)
{
    double seconds = time.microseconds / 1000000.0;
    return seconds;
}