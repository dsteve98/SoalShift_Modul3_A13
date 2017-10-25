#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread
#include <sys/wait.h>
#include <unistd.h>

int ans;
void* factorial(void* fac){
    int fct=(int)fac;
    for(int a=1;a<=fct;a++) 
    {
    ans=ans*a;
    printf("Hasil %d! = %d\n",fct, ans);
    }
}

int main(int argc, char *argv[]){
    pthread_t thread[argc];
    int num;
    for(int i=1;i<argc-1;i++){
        num = atoi(argv[i]);
        pthread_create(thread[i],NULL,&factorial,(void *)num);
    }
    for(int i=1;i<argc-1;i++){
        pthread_join(thread[i],NULL);
    }
}
