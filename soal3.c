#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread
#include <sys/wait.h>


int flag = 0;
int statlohan = 100;
int statkepiting = 100;

void *Lohan()
{
     
}
void *Kepiting()
{
     
}
int main()
{
     pthread_t thread1, thread2;//inisialisasi awal
	int  iret1, iret2;

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
	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL);

     //
     // 

     exit(EXIT_SUCCESS);
}


