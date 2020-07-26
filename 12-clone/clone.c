#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int clone(int (fn *)(void *), void* stack, int flags, void* arg, ...);

#define STACK_SIZE 256 (32*1024)

int num = 6;

int child_func(void* arg) {
    printf("Child pid: %d\n", getpid());
    num += 2;
    printf("Child num: %d\n", num);
}

int main() {
    int child_id;

    printf("Parent pid: %d\n", getpid());

    child_id = clone(child_func, malloc(STACK_SIZE) + STACK_SIZE, 0 , NULL);

    if (child_id == -1) {
        perror("failed to clone");
        exit(1);
    }

    if (waitpid(-1, NULL, __WCLONE)==-1) {
        perror("failed to wait");
        exit(2);
    }

    printf("parent num: %D\n", num);
    return 0;
}