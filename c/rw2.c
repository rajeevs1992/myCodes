#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
sem_t mutex1,mutex2,readBlock,writeBlock,writePending;
pthread_t t[3];
int readcount=0,writecount=0;
int getid()
{   
    int i;
    for(i=0;i<3;i++)
        if(pthread_equal(pthread_self(),t[i]))
            return i+1;
}
void *reader()
{
    while(1)
    {
    sem_wait(&writePending);
    sem_wait(&readBlock);
    sem_wait(&mutex1);
    readcount++;
    if(readcount==1)
        sem_wait(&writeBlock);
    sem_post(&mutex1);
    sem_post(&readBlock);
    sem_post(&writePending);
    printf("\n%d is reading\n",getid());
    sleep(1);
    sem_wait(&mutex1);
    readcount--;
    if(readcount==0)
        sem_post(&writeBlock);
    sem_post(&mutex1);
    sleep(1);
    }
}
void *writer()
{
    while(1)
    {
    sem_wait(&mutex2);
    writecount++;
    if(writecount==1)
        sem_wait(&readBlock);
    sem_post(&mutex2);
    sem_wait(&writeBlock);
    printf("\n\t%d is writing\n",getid());
    sleep(1);
    sem_post(&writeBlock);
    sem_wait(&mutex2);
    writecount--;
    if(writecount==0)
        sem_post(&readBlock);
    sem_post(&mutex2);
    sleep(1);
    }
}

int main()
{
    printf("\n");
    sem_init(&mutex1,0,1);
    sem_init(&mutex2,0,1);
    sem_init(&readBlock,0,1);
    sem_init(&writeBlock,0,1);
    sem_init(&writePending,0,1);
    pthread_create(&t[0],NULL,reader,NULL);
    pthread_create(&t[1],NULL,writer,NULL);
    pthread_create(&t[2],NULL,writer,NULL);

    pthread_join(t[0],NULL);
    pthread_join(t[1],NULL);
  //  pthread_join(t[2],NULL);


    return 0;
}
