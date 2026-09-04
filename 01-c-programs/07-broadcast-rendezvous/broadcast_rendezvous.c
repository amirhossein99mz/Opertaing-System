#include <semaphore.h>

int br_rec(void);
void br_send(int x);

int n=0;
int value;
sem_t mutex;
sem_t sync;

void initialization(){
    sem_init(&mutex,0,1);
    sem_init(&sync,0,0);
}

int br_rec(void){

    sem_wait(&mutex);
    n++;
    sem_post(&mutex);
 
    sem_wait(&sync);
 
    return value;
}

void br_send(int x){
    sem_wait(&mutex);
    value=x;
    for(int i=0;i<n;i++)sem_post(&sync);
    n=0;
    sem_post(&mutex);
}
