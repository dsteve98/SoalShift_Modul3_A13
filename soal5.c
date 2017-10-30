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
          int num =0;
          char word[];
          char *string;
            
          FILE *in_file = foprien("words.txt","r");
          if(in_file == NULL)
           {
                printf("Error file missing\n");
                exit(-1);
           }
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
