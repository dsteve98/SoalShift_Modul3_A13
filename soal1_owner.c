#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

void main()
{
    key_t key = 1234;
    int choice;
    int it;
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    int *senjata = shmat(shmid, NULL, 0);
    char nama[7][10]={"MP4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE","\0"};

    senjata[0] = 0;
    senjata[1] = 0;
    senjata[2] = 0;
    senjata[3] = 0;
    senjata[4] = 0;
    senjata[5] = 0;

    printf("0.Exit\n1.List\n2.Supply\n");

    while(scanf("%d",&choice)){
        if(choice==0) break;
        if(choice==1){
            for(it=0;it<6;it++){
            printf("%s\t%d\n",nama[it],senjata[it]);
            }
        }
        else if(choice==2){
            char comp[10];
            int total;
            scanf("%s%d",comp,&total);
            for(it=0;it<6;it++){
                if(!strcmp(comp,nama[it])){
                senjata += total;
                break;
                }
            }
        }

    }

    shmdt(senjata);
    shmctl(shmid, IPC_RMID, NULL);
}
