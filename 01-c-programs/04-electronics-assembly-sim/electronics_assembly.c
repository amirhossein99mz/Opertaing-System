#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_CARDS 6
#define MAX_CHASSIS 10

sem_t empy_cards,full_cards,empty_chasis,full_chasis;



static void *Electronics(void *arg){

    while(1){

        sem_wait(&empty_cards);
        sem_wait(&empty_cards);
        printf("[E] [E]\n");
        sem_post(&full_cards);
        sem_post(&full_cards);
    }



    return NULL;
}
static void *Mechancis(void *arg){

    while(1){

        sem_wait(&empty_chasis);
        printf("[M]\n");
        sem_post(&full_chasis);
    }
    return NULL;
}
static void *Assembly(void *arg){

    while(1){
       sem_wait
       sem_wait
       sem_wait
 
       printf("[A] <-- [E] + [E] + [M]\n");
       sem_post
       sem_post
       sem_post
    }

    return NULL;
}   

int main(int argc,char *argv[]){

    sem_init(&empty_cards,0,MAX_CARDS);
    sem_init(&empty_chasis,0,MAX_CHASIS);
    sem_init(&full_cards,0,0);
    sem_init(&full_cards,0,0);

    phtead_t t1,t2,t3;

    pthread_create(&t1,NULL,Electronics,NULL);
    pthread_create(&t2,NULL,Mechancis,NULL);
    pthread_create(&t3,NULL,Assembly,NULL);

    sem_destroy(&empty_cards);
    sem_destroy(&empty_chasis);
    sem_destroy(&full_cards);
    sem_destroy(&full_chasis);

}
