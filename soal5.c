#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
printf("%d",argc);
printf("%s",argv[0]);
printf("%s",argv[1]);
}
