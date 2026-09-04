#include<semaphore.h>
sem_t meR;
sem_t meW;
int nR=0;

void init(){

   sem_init(&meR,0,0);
   sem_init(&meW,0,1);

}


void writer(){

    sem_wait(&meW);
    WRITE();
    sem_post(&meR);

}


void reader(){

    sem_wait(&meR);
    nR++;
    sem_post(&meR);
  
   
    READ();


    sem_wait(&meR);
    nR--;

    if(!nR)sem_post(&meW);
    else sem_post(&meR);

}
