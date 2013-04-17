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
        read(pipefd[0],&buf,12);
        write(2,&buf,12);
        _exit(0);
    }
    if(fork()==0)
    {
        close(pipefd[1]);
        read(pipefd[0],&buf,12);
        write(2,&buf,12);
        _exit(0);
    }
    if(fork()==0)
    {
        close(pipefd[1]);
        read(pipefd[0],&buf,12);
        write(2,&buf,12);
        _exit(0);
    }
    close(pipefd[0]);
    char *s="Hello world\n";
    write(pipefd[1],s,12);
    write(pipefd[1],s,12);
    write(pipefd[1],s,12);
    exit(0);
}    
