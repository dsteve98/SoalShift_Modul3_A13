#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread
#include <sys/wait.h>
#include <unistd.h>

int status = 0;
int minearea[3][17];
int mcplayer[3];
int scoreplayer[3];

void *mineplacing1(){
    while(1){
        while(status!=1); 
        if(scoreplayer[1]==10||scoreplayer[2]==10||mcplayer[1]==16||mcplayer[2]==16){
            status=2;
            break;
        }
        system("clear");
        for(int a=0;a<4;a++){
            printf("place #%d mine in field number (1-16, number 0 if done)\n",a+1);
            int temp;
            scanf("%d",&temp);
            if(temp==0) break;
            else if(minearea[1][temp]>=1){
                printf("area has been planted or checked");
                a--;
            }
            else minearea[1][temp]=1;
        }
    }
}
