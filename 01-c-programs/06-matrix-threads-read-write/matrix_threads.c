#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define R 10

sem_t sem[R-1];
int matrix[R][R];

pthread_t tid[R];   
int id[R];       


void *readd(void *arg){

    int i = *(int *)arg;

    if(i > 0) sem_wait(&sem[i-1]);

    for(int j=0; j<R; j++)scanf("%d", &matrix[i][j]);

    if(i < R-1) sem_post(&sem[i]);

    pthread_exit(0);
}


void *writee(void *arg){

    int i = *(int *)arg;

    if(i > 0) sem_wait(&sem[i-1]);

    for(int j=0; j<R; j++)printf("%d", matrix[i][j]);

    if(i < R-1) sem_post(&sem[i]);

    pthread_exit(0);
}


int main(int argc, char *argv[]){

    for(int i=0; i<R-1; i++)sem_init(&sem[i], 0, 0);

    for(int i=0; i<R; i++){
        id[i] = i;
        pthread_create(&tid[i], NULL, readd, &id[i]);
    }

    for(int i=0; i<R; i++)pthread_join(tid[i], NULL);  
    

    for(int i=0; i<R-1; i++)sem_destroy(&sem[i]);





    for(int i=0; i<R-1; i++)sem_init(&sem[i], 0, 0);

    for(int i=0; i<R; i++){
        id[i] = i;
        pthread_create(&tid[i], NULL, writee, &id[i]);
    }

    for(int i=0; i<R; i++)pthread_join(tid[i], NULL); 
    

    for(int i=0; i<R-1; i++)sem_destroy(&sem[i]);

    return 0;
}
