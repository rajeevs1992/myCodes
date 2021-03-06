#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t mutex,writeBlock;
int readCount=0;
void *reader(void *arg){
    int id=(int)arg;
    while(1)    {
    sem_wait(&mutex);
    readCount++;
    if(readCount==1)
        sem_wait(&writeBlock);
    sem_post(&mutex);
    printf("%d is reading\n",id);
    sleep(1);
    sem_wait(&mutex);
    readCount--;
    if(readCount==0)
        sem_post(&writeBlock);
    sem_post(&mutex);
    sleep(1);
    }
}
void *writer(void *arg){
    int id=(int)arg;
    while(1)    {
    sem_wait(&writeBlock);
    printf("\t%d is writing\n",id);
    sleep(1);
    sem_post(&writeBlock);
    sleep(1);
    }
}
int main(){
    printf("\n");
    pthread_t t[3];
    sem_init(&mutex,0,1);
    sem_init(&writeBlock,0,1);
    pthread_create(&t[2],NULL,reader,(void *)3);
    pthread_create(&t[0],NULL,reader,(void *)1);
    pthread_create(&t[1],NULL,writer,(void *)2);
    pthread_join(t[0],NULL);
    pthread_join(t[1],NULL);
    pthread_join(t[2],NULL);
    return 0;
}

