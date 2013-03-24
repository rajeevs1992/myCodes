#include<stdio.h>
#include<pthread.h>
pthread_t T[3];
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
}
int main()
{
    
}
