#include <semaphore.h>

sem_t mutex[10];
int n_wait[10];

sem_t sync[10];

int main(){

    for(int i=0;i<10;i++){
        n_wait[i]=0;
        sem_init(&sync[i],0,0);
        sem_init(&mutex[i],0,1);
    }

}

void wait_ch(int x){

   sem_wait(&mutex[x]);

   n_wait[x]++;
   sem_post(&mutex[x]);

    sem_wait(&sync[x]);

}

void signal_ch(int x){

    sem_wait(&mutex[x]);
    
    int n=n_wait[x];
    
    for(int i=0;i<n;i++)sem_post(&sync[x]);
   
    sem_post(&mutex[x]);



}
