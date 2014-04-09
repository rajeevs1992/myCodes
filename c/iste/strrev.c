#include<stdio.h>
#include<string.h>
int main()
{
    int l,i,f=0;
    char str[50],t;
    printf("Enter String ");
    scanf("%s",str);
    l=strlen(str);
    for(i=0;i<l/2;i++)
    {
        t=str[i];
        str[i]=str[l-i-1];
        str[l-i-1]=t;
    }
    printf("%s\n",str);
}    
