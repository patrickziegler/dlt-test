#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 100

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
        char receive_str[BUF_SIZE] = "";
        close(fd[1]);
        read(fd[0], receive_str, BUF_SIZE);
        close(fd[0]);
        printf("%s\n", receive_str);
        exit(EXIT_SUCCESS);
    }

    else {
        char send_str[] = "ok";
        close(fd[0]);
        write(fd[1], send_str, strlen(send_str));
        close(fd[1]);
        exit(EXIT_SUCCESS);
    }
}
