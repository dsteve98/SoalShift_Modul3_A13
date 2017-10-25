#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread
#include <sys/wait.h>
#include <unistd.h>

pthread_t tid[2];
void *readandcount( void *arg ){
    unsigned long i = 0;
    pthread_t id = pthread_self();
    if(pthread_equal(id,tid[0]))
    {
          
    }
    if(pthread_equal(id,tid[1]))
    {
          
    }
    if
}

int main(int argc, char *argv[]){
char temp[50];
sprintf(temp,"grep Novel.txt %s",argv[1])
system(temp);

}
