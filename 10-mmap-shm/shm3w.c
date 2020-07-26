#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("text.txt", 88);

    int shmid = shmget(key, 4096, 0666 | IPC_CREAT);

    void * ptr = shmat(shimd, NULL, 0);

    strcpy(ptr, "ISEL - LEIC - SO");

    shmdt(ptr);

    return 0;
}
