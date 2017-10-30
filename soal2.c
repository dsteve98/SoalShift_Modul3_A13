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
        if (scoreplayer[1]==10||scoreplayer[2]==10||mcplayer[1]==16||mcplayer[2]==16){
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
        for(int a=0;a<4;a++){
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
        }
        status=2;
    }
}

void *mineplacing2(){
    while(1){
        while(status!=2); 
        if(scoreplayer[1]==10||scoreplayer[2]==10||mcplayer[1]==16||mcplayer[2]==16){
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
        for(int a=0;a<4;a++){
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
        }
        status=3;
    }
}

void minechecking1(){
    while(1){
        while(status!=3);
        if(scoreplayer[1]==10||scoreplayer[2]==10||mcplayer[1]==16||mcplayer[2]==16){
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
        for(int a=0;a<4;a++){
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
            }
            if(scoreplayer[1]==10||scoreplayer[2]==10||mcplayer[1]==16||mcplayer[2]==16){
                status=4;
                break;
            }
        }
        status=4;
    }
}

void minechecking2(){
    while(1){
        while(status!=4);
        if(scoreplayer[1]==10||scoreplayer[2]==10||mcplayer[1]==16||mcplayer[2]==16){
            status=4;
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
        for(int a=0;a<4;a++){
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
            }
            if(scoreplayer[1]==10||scoreplayer[2]==10||mcplayer[1]==16||mcplayer[2]==16){
                status=4;
                break;
            }
        }
        status=1;
    }
}

