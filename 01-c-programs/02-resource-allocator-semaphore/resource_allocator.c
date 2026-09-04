#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10

int resources[M] = {0};   // 0 = free, 1 = used

sem_t empty, mutex;

int request(void)
{
    int i;

    sem_wait(&empty);
    sem_wait(&mutex);

    for (i = 0; i < M; i++) {
        if (!resources[i]) {
            resources[i] = 1;
            break;
        }
    }

    sem_post(&mutex);

    return i;
}

void release(int i)
{
    sem_wait(&mutex);

    resources[i] = 0;

    sem_post(&mutex);
    sem_post(&empty);
}

int main(void)
{
    sem_init(&empty, 0, M);
    sem_init(&mutex, 0, 1);

    return 0;
}
