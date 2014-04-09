#include<stdio.h>
#include<string.h>
#include<ctype.h>
int verify(char *str)
{
    int i;
    if(strlen(str)!=5)
        return 0;
    if('a'<=str[0] && str[0]<='h' && 'a'<=str[3] && str[3]<='h' && str[2]=='-' && '1'<=str[1] && str[1]<='8' && '1'<=str[4] && str[4]<='8')
            return 1;
    return 0;
}
int main()
{
    int n,diff1,diff2,i;
    unsigned int t;
    char str[11],ch;
    scanf("%u",&t);
    getchar();
    while(t--)
    {
        i=0;
        gets(str);
        diff1=abs(str[0]-str[3]);
        diff2=abs(str[1]-str[4]);
        if(verify(str))
        {
            if((diff1==1 && diff2==2) || (diff1==2 && diff2==1))
                puts("Yes");
            else
                puts("No");
        }
        else
            puts("Error");
    }
    return 0;
}
