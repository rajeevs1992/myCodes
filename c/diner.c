#include<pthread.h>
#include<stdio.h>
pthread_t phil[5];
static int chopstick[]={1,1,1,1,1};
pthread_mutex_t lock;
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
        pthread_mutex_lock(&lock);
        if(chopstick[id] && chopstick[(id+1)%5])
        {
            chopstick[id]=0;
            chopstick[(id+1)%5]=0;
            pthread_mutex_unlock(&lock);
            printf("%d is eating\n",id+1);
            sleep(1);
            pthread_mutex_lock(&lock);
            chopstick[id]=1;
            chopstick[(id+1)%5]=1;
            pthread_mutex_unlock(&lock);
            sleep(1);
        }
        else
        {
            pthread_mutex_unlock(&lock);
            printf("%d is thinking \n",id+1);
            sleep(1);
        }
    }
}
int main()
{
    int i;
    pthread_mutex_init(&lock,NULL);
    for(i=0;i<5;i++)
        pthread_create(&phil[i],NULL,start,NULL);
    for(i=0;i<5;i++)
        pthread_join(phil[i],NULL);
    return 0;
}
Output:
3 is thinking 
4 is eating
1 is thinking 
5 is thinking 
2 is eating
3 is thinking 
