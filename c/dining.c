#include<stdio.h>
#include<pthread.h>
#define NUM 5
pthread_t phil[NUM]
pthread_mutex_t lock1;
int get_tid();
void *start()
{
	
	
}

int main()
{
	int i=0;
	pthread_mutex_init(&lock1,NULL);
	for(i=0;i<NUM;i++)
		pthread_create(&phil[i],NULL,start,NULL);
	for(i=0;i<NUM;i++)
		pthread_join(phil[i],NULL);
	return 0;
}
int get_tid()
{
	int i=0;
	for(i=0;i<NUM;i++)
	{
		if(pthread_equal(pthread_self(),phil[i]))
			return i+1;
	}
}
