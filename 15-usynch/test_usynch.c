#include <stdio.h>

#include "include/uthread.h"
#include "include/usynch.h"

EVENT general_event;

void signaling_thread(void *arg) {
    for(int i = 0; i < 8; ++i) {
        printf("working...\n");
        ut_yield();
    }
    ut_event_signal_all(&general_event);
}

void waiting_thread(void *arg) {
    const char * name = (const char *) arg;
    printf("%s: waiting for event\n", name);
    ut_event_wait(&general_event);
    printf("%s: proceeding...\n", name);
}

int main() {
    ut_init();

    ut_event_init(&general_event);

    ut_create(signaling_thread, NULL);
    
    ut_create(waiting_thread, "T1");
    ut_create(waiting_thread, "T2");
    ut_create(waiting_thread, "T3");

    ut_run();

    ut_end();
    return 0;
}