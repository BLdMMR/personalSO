#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    int pipefd[2];

    pipe(pipefd);

    pid_t pid = fork();

    if (pid == 0) {
        close(pipefd[0]);

        printf("Child running...\n");
        sleep(3);

        printf("Child writing... \n");
        write(pipefd[1], "Hello", 6);

        exit(77);
    }
    else {
        close(pipefd[1]);
        printf("Parent proceeding... \n");

        printf("Parent reading... \n");
        char data[6];
        read(pipefd[0], data, 6);

        printf("Parent recieved: %s\n", data);

        waitpid(pid, NULL, 0);
    }
    return 0;
}