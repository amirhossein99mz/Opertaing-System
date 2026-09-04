#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

int *vet,i;

void adder(void *arg){

    int i=*(int *)arg;

   
    while(k!=0){
 
        if(k<n/2)sum_wait(&sem[i+k]);
   
        vet[i]+=vet[i+k];
        k/=2;

       if(i>=k){sem_post(&sem[i]);break;}


    }

    return NULL;
}



int array_sum(int *v,int N){



    pthread_t th[N/2];

    
    for(int i=0;i<N/2;i++)sem_init(&sem[i],0,0);
 
    for(int i=0;i<N/2;i++)pthread_create(&tid[i],NULL,adder,&i);
    for(int i=0;i<N/2;i++)pthread_join(tid[i],NULL);

    for(int i=0;i<N/2;i++)sem_destory(&sem[i]);


}
