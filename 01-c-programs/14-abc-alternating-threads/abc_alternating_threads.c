#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
//output must be ABC or CBA
sem_t s1,s2,s3;
int first=1;
void init(){
    sem_inti(&s1,0,1);
    sem_init(&s2,0,0);
    sem_init(&s3,0,0);
}

void *TA(void *arg){

    while(1){

        sem_wait(&s1);
        printf("A");
        if(first){
            first=0;
            sem_post(&s2);
            sem_wait(&s3);
            sem_post(&s1);
        }
        else{
            first=1;sem_post(&s3);
        }

    }


}


void *TB(void *arg){

    sem_wait(&s2);
    printf("B");
    sem_post(&s1);
}

void *TC(void *arg){

    while(1){

        sem_wait(&s1);
        printf("C");
        if(first){
            first=0;
            sem_post(&s2);
            sem_wait(&s3);
            sem_post(&s1);
        }
        else{
            first=1;sem_post(&s3);
        }

    }


}
