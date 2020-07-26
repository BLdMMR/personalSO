#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main() {
    int res = write(3, "HELLO, WORLD!", 14);
    if (res = -1) {
        perror("Write error: ");
        exit(1);
    }
    else {
        fprintf(stderr, "res = %d\n", res);
    }
    return 0;
}