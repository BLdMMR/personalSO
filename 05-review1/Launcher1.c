#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFSIZE 256

char cmf[BUFFSIZE] = {'.', '/'};

int main() {
    for (;;) {
        
        printf("> ");
        fgets(&cmd[2], BUFFSIZE - 2, stdin);
        char *n1 = strchr(&cmd[2], '\n');
        if (n1) *n1 = 0;

        if (strcmp(cmd + 2, "exit") == 0) {
            break;
        }

        pid_t pid = fork();
        if (pid == 0) {
            execlp(cmd, cmd + 2, NULL);
            perror("exec failed");
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                printf("res: %d\n", WEXITSTATUS(status));
            } else {
                printf("end\n");
            }
        }
    }
    return 0;
}