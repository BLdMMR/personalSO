#include <stdio.h>
#include <string.h>
#include <ctype.h>

char line[256];

int main() {
    for (;;) {
        char * s = fgets(line, 256, stdin);
        if (!s) {
            break;
        }

        char * nl = strchr(line, '\n');
        if (nl) {
            *nl = '\0';
        }

        for (; *s; ++s) {
            *s = toupper(*s);
        }

        puts(line);
    }
}
