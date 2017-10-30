#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread
#include <sys/wait.h>
#include <unistd.h>

int status = 0;
int minearea[3][17];
int mcplayer[3];
int scoreplayer[3];
char playername[3][20];

void checkscore(){
    printf("%s : %d\n%s : %d\n",playername[1],scoreplayer[1],playername[2],scoreplayer[2]);
}

void *mineplacing1(){
    while(1){
        while(status!=1); 
        if (scoreplayer[1]==10||scoreplayer[2]==10||mcplayer[1]==16){
            status=2;
            break;
        }
        system("clear");
        printf("%s's turn\n",playername[1]);
        printf("1 -> Check Score\nOther number -> Place Mine\n");
        int choice;
        scanf("%d",&choice);
        while(choice == 1){
            checkscore();
            printf("1 -> Check Score\nOther number -> Place Mine\n");
            scanf("%d",&choice);
        }
        int a;
        for(a=0;a<4;a++){
            printf("place #%d mine in field number (1-16, number 0 if done)\n",a+1);
            int temp;
            scanf("%d",&temp);
            if(temp==0) break;
            else if(minearea[1][temp]>=1){
                printf("area has been planted or checked.\n");
                a--;
            }
            else {
                minearea[1][temp]=1;
                mcplayer[1]++;
            }
            if(scoreplayer[1]==10||scoreplayer[2]==10||mcplayer[1]==16){
                status=2;
                break;
            }
        }
        status=2;
    }
}

void *mineplacing2(){
    while(1){
        while(status!=2); 
        if(scoreplayer[1]==10||scoreplayer[2]==10||mcplayer[2]==16){
            status=3;
            break;
        }
        system("clear");
        printf("%s's turn\n",playername[2]);
        printf("1 -> Check Score\nOther number -> Place Mine\n");
        int choice;
        scanf("%d",&choice);
        while(choice == 1){
            checkscore();
            printf("1 -> Check Score\nOther number -> Place Mine\n");
            scanf("%d",&choice);
        }
        int a;
        for(a=0;a<4;a++){
            printf("place #%d mine in field number (1-16, number 0 if done)\n",a+1);
            int temp;
            scanf("%d",&temp);
            if(temp==0) break;
            else if(minearea[2][temp]>=1){
                printf("area has been planted or checked.\n");
                a--;
            }
            else {
                minearea[2][temp]=1;
                mcplayer[2]++;
            }
            if(scoreplayer[1]==10||scoreplayer[2]==10||mcplayer[2]==16){
                status=3;
                break;
            }
        }
        status=3;
    }
}

void *minechecking1(){
    while(1){
        while(status!=3);
        if(scoreplayer[1]==10||scoreplayer[2]==10||mcplayer[2]==16){
            status=4;
            break;
        }
        system("clear");
        printf("%s's turn\n",playername[1]);
        printf("1 -> Check Score\nOther number -> Check Mine\n");
        int choice;
        scanf("%d",&choice);
        while(choice == 1){
            checkscore();
            printf("1 -> Check Score\nOther number -> Place Mine\n");
            scanf("%d",&choice);
        }
        int a;
        for(a=0;a<4;a++){
            printf("check #%d mine in field number (1-16)\n",a+1);
            int temp;
            scanf("%d",&temp);
            if(minearea[2][temp]==1){
                printf("the area has mine planted.\n");
                scoreplayer[2]++;
                minearea[2][temp]=2;
            }
            else if (minearea[2][temp]==2){
                printf("the area has been checked.\n");
                a--;
            }
            else {
                minearea[2][temp]=2;
                printf("safe.\n");
                scoreplayer[1]++;
                mcplayer[2]++;
            }
            if(scoreplayer[1]==10||scoreplayer[2]==10){
                status=4;
                break;
            }
        }
        status=4;
    }
}

void *minechecking2(){
    while(1){
        while(status!=4);
        if(scoreplayer[1]==10||scoreplayer[2]==10||mcplayer[1]==16){
            status=1;
            break;
        }
        system("clear");
        printf("%s's turn\n",playername[2]);
        printf("1 -> Check Score\nOther number -> Check Mine\n");
        int choice;
        scanf("%d",&choice);
        while(choice == 1){
            checkscore();
            printf("1 -> Check Score\nOther number -> Place Mine\n");
            scanf("%d",&choice);
        }
        int a;
        for(a=0;a<4;a++){
            printf("check #%d mine in field number (1-16)\n",a+1);
            int temp;
            scanf("%d",&temp);
            if(minearea[1][temp]==1){
                printf("the area has mine planted.\n");
                scoreplayer[1]++;
                minearea[1][temp]=2;
            }
            else if (minearea[2][temp]==2){
                printf("the area has been checked.\n");
                a--;
            }
            else {
                minearea[1][temp]=2;
                printf("safe.\n");
                scoreplayer[2]++;
                mcplayer[1]++;
            }
            if(scoreplayer[1]==10||scoreplayer[2]==10){
                status=1;
                break;
            }
        }
        status=1;
    }
}

int main(){
    pthread_t trd[5];
    printf("Insert Player 1 name :");
    scanf("%s",playername[1]);
    printf("Insert Player 2 name :");
    scanf("%s",playername[2]);
    pthread_create(&trd[0],NULL,&mineplacing1,NULL);
    pthread_create(&trd[1],NULL,&mineplacing2,NULL);
    pthread_create(&trd[2],NULL,&minechecking1,NULL);
    pthread_create(&trd[3],NULL,&minechecking2,NULL);
    status=1;
 
    for(int iter=0;iter<4;iter++){
        pthread_join(trd[iter],NULL);
    }
    checkscore();
    if(scoreplayer[1]>scoreplayer[2]) printf("%s win!\n",playername[1]);
    else if(scoreplayer[1]<scoreplayer[2]) printf("%s win!\n",playername[2]);
    else printf("Tie\n");
}
