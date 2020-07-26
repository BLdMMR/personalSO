#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>

#define BUFFSIZE 256

char cmd[BUFFSIZE] = {'.', '/'};
char output[BUFFSIZE];

char * trim(char *str) {
    while (*str && isspace(*str))
        ++str;
    size_t len = strlen(str);
    for (size_t idx = len - 1; idx >= 0; --idx) {
        if (!isspace(str[idx])) {
            str[idx + 1] = '\0';
            break;
        }
    }
    return str;
}

void extractOutputFile(char * cmdline, char* redirChar, char* outputfile) {
    char* outf = trim(redifChar + 1);
    strcpt(outputFile, outf);
    *redirChar = '\0';
    trim(cmdline);
}

int main () {
    for(;;) {
        printf("> ");
        fgets(&cmd[2], BUFFSIZE - 2, stdin);
        char * nl = strchr(&cmd[2], '\n');

        if (nl) *nl = 0;

        if (strcmp(cmd + 2, "exit") == 0) 
            break;
        
        output[0] = '\0';
        char *redir = strchr(cmd , '>');
        if (redir) {
            extractOutputFile(cmd, redir, output);
        }

        pid_t pid = fork();
        if (pid == 0) {
            if (output[0]) {
                int fd = open(output, O_CREAT | O_RDWR, 0666);
                if (fd >= 0) {
                    dup2(fd, 1);
                    close(fd);
                }
            }

            execlp(cmd, cmd + 2, NULL);
            perror("exec failed");
            exit(1);
        }
        else {
            int status;

            waitpid(pid, &status, 0);
            if (WIFEXTED(status)){
                printf("res: %d\n", WEXITSTATUS(status));
            }
            else {
                printf("end\n");
            }
        }
    }
    return 0;
}