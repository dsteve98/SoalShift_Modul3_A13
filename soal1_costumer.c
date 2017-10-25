#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

void main()
{
        key_t key = 1234;

        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        int *senjata = shmat(shmid, NULL, 0);

        printf("%d--%d\n", senjata[0], senjata[1]);
        senjata[0] = 30;
        senjata[1] = 40;

        sleep(5);

        printf("%d--%d\n", senjata[0], senjata[1]);
        shmdt(senjata);
        shmctl(shmid, IPC_RMID, NULL);
}
