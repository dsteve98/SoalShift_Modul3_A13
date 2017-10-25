#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread
#include <sys/wait.h>
#include <unistd.h>

void *print_message_function( void *ptr );

int main(int argc, char *argv[]){
pthread_t thread1, thread2;
const char *message1 = argv[1];
const char *message2 = argv[2];
int iret1, iret2;

iret = pthread_create(&thread1,NULL, print_message_function, (void*) message1);
if(iret1)
{
    fprintf(stderr,"Error - pthread_create() return code : %d\n",iret1);
    exit(EXIT_FAILURE);
}

}
