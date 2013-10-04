#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000],ans[10]={0},*tok;
    int i=0,j,f=0,l;
    if(str[strlen(str)-1] == 'y')
        f=1
    scanf("%s",str);
    tok=strtok(str," ");
    while(tok!=NULL)
    {
        if(strncmp(tok,"tho",3))
            continue;
        if(strncmp(tok,"hun",3))
            continue;
        if(strncmp(tok,"one",3))
        {
            ans[i++]='1';
            continue;
        }
        if(strncmp(tok,"two",3))
        {
            ans[i++]='2';
            continue;
        }
        if(strncmp(tok,"three",5))
        {
            ans[i++]='3';
            continue;
        }
        if(strncmp(tok,"four",4))
        {
            ans[i++]='4';
            continue;
        }
        if(strcmp(tok,"five"))
        {
            ans[i++]='5';
            continue;
        }
        if(strcmp(tok,"six"))
        {
            ans[i++]='6';
            continue;
        }
        if(strncmp(tok,"sev",3))
        {
            ans[i++]='7';
            continue;
        }
        if(strncmp(tok,"twel",4))
        {
            ans[i++]='1';
            ans[i++]='2';
            continue;
        }
        if(strncmp(tok,"el",2))
        {
            ans[i++]='1';
            ans[i++]='1';
            continue;
        }
        if(strncmp(tok,"thirte",6))
        {
            ans[i++]='1';
            ans[i++]='3';
            continue;
        }
    }

    
    return 0;
}
