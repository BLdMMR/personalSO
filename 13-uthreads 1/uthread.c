#include <stdint.h>

#define STACK_SIZE (8*4096)

typedef struct uthread {
    uint64_t sp;
    void* stack;
} UTHREAD, *PUTHREAD;

void context_switch(PUTHREAD currThread, PUTHREAD nextThread);