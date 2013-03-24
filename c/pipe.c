#include<unistd.h>
#include<stdio.h>
int main()
{
    int pipefd[2];
    char buf;
    pipe(pipefd);
    if(fork()==0)
    {
        close(pipefd[1]);
        printf("Waiting for input on the pipe \n");
        while(read(pipefd[0],&buf,1)>0)
            write(2,&buf,1);
        _exit(0);
    }
    close(pipefd[0]);
    char *s="Hello world\n";
    write(pipefd[1],s,12);
    printf("Written Hello world onto the pipe \n");
    exit(0);
}    
