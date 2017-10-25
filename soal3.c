#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread
#include <sys/wait.h>
#include <unistd.h>


int flag = 0;
int statlohan = 100;
int statkepiting = 100;

void *Lohan()
{
    while(flag==0){
        statlohan -= 15;
        if(statlohan<=0||statlohan>100||statkepiting<=0||statkepiting>100||flag==1){
            flag=1;
            break;
        }
        sleep(10);
    }
}
void *Kepiting()
{
     while(flag==0){
        statkepiting -= 10;
        if(statlohan<=0||statlohan>100||statkepiting<=0||statkepiting>100||flag==1){
            flag=1;
            break;
        }
        sleep(20);
    }
}
void *Makan()
{
    int choice;
    while(flag==0){
        printf("********************\n");
        printf("Lohan\t%d\nKepiting\t%d\n",statlohan,statkepiting);
        printf("1 for lohan, 2 for kepiting\n");
        scanf("%d",&choice);
        if(choice==1) statlohan += 10;
        else if(choice==2) statkepiting += 10;

        if(statlohan<=0||statlohan>100||statkepiting<=0||statkepiting>100||flag==1){
            flag=1;
            break;
        }
    }
}


int main()
{
     pthread_t thread1, thread2, thread3;//inisialisasi awal
	int  iret1, iret2, iret3;

     iret1 = pthread_create( &thread1, NULL, Lohan, NULL);
     if(iret1)//jika gagal
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
         exit(EXIT_FAILURE);
     }
	

     iret2 = pthread_create( &thread2, NULL, Kepiting, NULL);
     if(iret2)//jika gagal
     {
	 
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
         exit(EXIT_FAILURE);
     }
	
     iret3 = pthread_create( &thread3, NULL, Makan, NULL);
     if(iret3)//jika gagal
     {
	 
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
         exit(EXIT_FAILURE);
     }


    pthread_join( thread1, NULL);
	pthread_join( thread2, NULL);
    pthread_join( thread3, NULL);
    
    printf("GAME OVER\n");
     //
     // 

     exit(EXIT_SUCCESS);
}


