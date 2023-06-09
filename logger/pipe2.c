/* Copyright (C) 2023 Patrick Ziegler
 *
 * This programm is implementing the following
 * shell command in plain C
 *
 * echo "ok" | ./reader -p test
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int fd[2];
    pid_t cpid;

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    cpid = fork();

    if (cpid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    else if (cpid == 0) {
        close(fd[1]);
        if (dup2(fd[0], STDIN_FILENO)) {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        char *args[] = {
            "./reader",
            "-p", "test", NULL};
        execv(args[0], args);
        perror("execve");
        exit(EXIT_FAILURE);
    }

    else {
        char send_str[] = "ok\n";
        close(fd[0]);
        write(fd[1], send_str, strlen(send_str));
        close(fd[1]);
        exit(EXIT_SUCCESS);
    }
}
