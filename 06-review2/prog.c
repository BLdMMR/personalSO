#include <stdio.h>
#include <stdlib.h>

const int a = 9;

char isel[] = {'I', 'S', 'E', 'L'};

const char * str = "ISEL";

char * str = isel;
char const * str2 = "ISEL";
const char * str2x = "ISEL";
char * const str3 = isel;
char const * const str4 = "ISEL";

int b = 7;

const int z = 99;

int main() {
    int c = 2;
    void * ptr = malloc(1);

    printf("[.rodata] %p\n", &a);
    printf("[.rodata] %p\n", &z);
    printf("[.data] %p\n", &d);
    printf("[local] %p\n", &c);
    printf("[local] %p\n", &ptr);
    printf("[dynamic] %p\n", &ptr);
    printf("[function] %p\n", &main);

    free(ptr);
    return 0;

}