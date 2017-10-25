#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    pthread_t thread[argc];
    int num[argc];
    for(int i=1;i<argc;i++){
    num[i] = atoi(argv[i]);
    }
    for(int i=1;i<argc;i++){
    printf("%d\n",num[i]);
    }
}
