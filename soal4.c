#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread
#include <sys/wait.h>
#include <unistd.h>
#include <stdint.h>

void *factorial(void *fac){
    int *qq = (int *)fac;
    int ctr=*qq,ans=1;
    printf("%d\n",ctr);
}

int main(int argc, char *argv[]){
    pthread_t thd[argc];
    int num[argc],*mun,hhee;
    for(int i=0;i<argc-1;i++){
        num[i] = atoi(argv[i+1]);
        mun=&num[i];
        hhee=*mun;
        printf("%d--%d--%d\n",num[i],*mun,hhee);
        pthread_create(&thd[i],NULL,&factorial,(void *) mun);
    }
    for(int i=0;i<argc-1;i++){
        pthread_join(thd[i],NULL);
    }

}
