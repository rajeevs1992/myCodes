#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
int main()
{
    char *PHIL,i,j;
    const int segment_size=20;
    int segment_id=shmget((key_t)getpid(),segment_size,0666|IPC_CREAT);
    PHIL=(char *)shmat(segment_id,0,0);
    strcpy(PHIL,"00000");
    for(i=0;i<5;i++)
        if(fork()==0)
        {   
            printf("\n");
            while(1)
            {
                if(PHIL[i]=='1' && PHIL[(i+1)%5]=='1')
                {
                    PHIL[i]=PHIL[(i+1)%5]='0';
                    printf("\nPhilosopher %d is eating \n",i);
                    sleep(1);
                    PHIL[i]=PHIL[(i+1)%5]='1';
                    sleep(1);
                }
                else
                {
                    printf("\tPhilosopher %d is thinking \n",i);
                    sleep(1);
                }
            }
        }
    return 0;
}
