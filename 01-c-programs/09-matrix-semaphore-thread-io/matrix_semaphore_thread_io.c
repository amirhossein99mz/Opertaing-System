#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define R 4
#define C 4

int matrix[R][C];
int id[R];//row number to pass to the thread
sem_t sem[R-1];
pthread_t thread[R];


void *read_row(void *arg){

    int i=*(*int)arg;
   
    if(i>0)sem_wait(&sem[i-1]);
    
    for(int j=0;j<C;j++)scanf("%d",&matrix[i][j]);
   
    if(i<R-1)sem_post(&sem[i]);

    return NULL;


}


void *read_row(void *arg){

    int i=*(*int)arg;
   
    if(i>0)sem_wait(&sem[i-1]);
    
    for(int j=0;j<C;j++)printf("%d",matrix[i][j]);
   
    if(i<R-1)sem_post(&sem[i]);

    return NULL;


}


int main(int argc, char *argv[]){


    for(int i=0;i<R-1;i++)sem_init(&sem[i],0,0);


    for(int i=0;i<R;i++){
        id[i]=i;
        pthread_create(&thread[i],NULL,read_row,&id[i]);
    }

    for(int i=0;i<R;i++)pthread_join(thread[i],NULL);


    for(int i=0;i<R-1;i++)sem_destroy(&sem[i]);

   

    for(int i=0;i<R-1;i++)sem_init(&sem[i],0,0);


    for(int i=0;i<R;i++){
        id[i]=i;
        pthread_create(&thread[i],NULL,write_row,&id[i]);
    }

    for(int i=0;i<R;i++)pthread_join(thread[i],NULL);


    for(int i=0;i<R-1;i++)sem_destroy(&sem[i]);




    return 0;
}
