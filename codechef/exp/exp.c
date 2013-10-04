#include<stdio.h>
#include<string.h>
long int eval1(char str[1000])
{
    char *num;
    long int n=0;
    num=strtok(str,"+");
    while(num!=NULL)
    {
        n+=atoi(num);
        num=strtok(NULL,"+");
    }
    return n;
}
long int eval2(char str[1000])
{
    char *num;
    long int n=1;
    num=strtok(str,"*");
    while(num!=NULL)
    {
        n*=atoi(num);
        num=strtok(NULL,"+");
    }
    return n;
}
int main()
{
    long int min=0,max=1,i=0,j=0;
    char str[100000]={0},str2[100000],ch;
    do
    {
        ch = getchar();
        str2[j++]=ch;
        if(ch=='*'||ch==EOF)
        {
            str[i]=0;
            max*=eval1(str);
            memset(str,0,1000);
            i=0;
        }
        else
            str[i++]=ch;
    }while(ch!=10);
    str2[j-1]=0;
    i=j=0;
    do
    {
        ch = str2[j++];
        if(ch=='+'||ch==0)
        {
            str[i]=0;
            min+=eval2(str);
            memset(str,0,1000);
            i=0;
        }
        else
            str[i++]=ch;
    }while(ch!=0);
    printf("%ld %ld\n",max,min);
}
