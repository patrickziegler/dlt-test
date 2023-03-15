/* Copyright (C) 2023 Patrick Ziegler
 *
 * This programm reads a line from stdin,
 * prefixes it with a configurable string
 * and prints the result to stdout
 *
 * Usage:
 * echo "ok" | ./reader -p test
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 100

int main(int argc, char* argv[])
{
    char prefix[] = "reader";
    if (argc > 2 && strcmp(argv[1], "-p") == 0) {
        strcpy(prefix, argv[2]);
    }
    char input[BUF_SIZE] = "";
    read(STDIN_FILENO, input, BUF_SIZE);
    printf("%s: %s", prefix, input);
    exit(EXIT_SUCCESS);
}
