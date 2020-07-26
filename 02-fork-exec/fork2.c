#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int a = 1234;

int main() {

    int res;

    printf("Process: %d\n", getpid());
    printf("Parent: %d\n", getppid());

    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process: %d\n", getpid());
        printf("Child parent: %d\n", getppid());

        a += 1111;
    } else {
        printf("Parent process: %d\n", getpid());
        printf("Parent parent: %d\n", getppid());
    }

    for(int i = 0; i < 8; ++i) {
        printf("[%d] var at address %p with value %d\n",
            getpid(), (void *)&a, a);
        ++a;
        sleep(1);
    }
    if (pid == 0) {
        exit(88);
    }

    else {
        getchar();
        waitpid(pid, &res, 0);
        if (WIFEXITED(res)) {
            printf("Child result: %d\n", WEXITSTATUS(res));
        }
        getchar();
    }

    return 0;

}