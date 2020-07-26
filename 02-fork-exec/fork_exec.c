#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        open("dest.txt", O_CREAT | O_RDWR, 0666);
        execlp("./prog4", "prog4", NULL);
        fprintf(stderr, "Cannot Occur\n");
    }
    else {
        waitpid(pid, NULL, 0);
    }

    return 0;

}
