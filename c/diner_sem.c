#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
pthread_t phil[5];
static int chopstick[]={1,1,1,1,1};
sem_t lock;
int getid()
{
    int i;
    for(i=0;i<5;i++)
        if(pthread_equal(pthread_self(),phil[i]))
            return i;
}
void *start()
{
    while(1)
    {
        int id=getid();
        sem_wait(&lock);
        if(chopstick[id] && chopstick[(id+1)%5])
        {
            chopstick[id]=0;
            chopstick[(id+1)%5]=0;
            sem_post(&lock);
            printf("%d is eating\n",id+1);
            sleep(1);
            sem_wait(&lock);
            chopstick[id]=1;
            chopstick[(id+1)%5]=1;
            sem_post(&lock);
            sleep(1);
        }
        else
        {
            sem_post(&lock);
            printf("%d is thinking \n",id+1);
            sleep(1);
        }
    }
}
int main()
{
    int i;
    sem_init(&lock,0,1);
    for(i=0;i<5;i++)
        pthread_create(&phil[i],NULL,start,NULL);
    for(i=0;i<5;i++)
        pthread_join(phil[i],NULL);
    return 0;
}
