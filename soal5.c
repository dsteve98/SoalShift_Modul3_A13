#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
printf("%d",argc);
for(int i=1;i<argc;i++)printf("%s",argv[i]);
}
