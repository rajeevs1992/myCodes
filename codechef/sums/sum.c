#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int calc(char a,char b)
{
    int t;
    t = a-48;
    switch(b)
    {
        case 'M': return t*1000;break;
        case 'A': return t*100;break;
        case 'C': return t*10;break;
        case 'S': return t*1;break;
    }
}
int decode(char s[])
{
    int i,j,l,sum=0,t;
    l=strlen(s);
    i=0;
    while(i<l)
    {
        if(isdigit(s[i]) && isalpha(s[i+1]))
        {
            sum += calc(s[i],s[i+1]);
            i+=2;
        }
        else
        {
            sum += calc('1',s[i]);
            i++;
        }
    }
    return sum;
}

char str2[100];
char * encode(int n)
{   
    int t,i=0,j=0,p=1000;
    char MACS[5]="MACS";
    while(p)
    {
         t=n/p;
         n=n-(t*p);
         if(t)
         {
            if(t>1)
            {
                str2[i++]=t+48;
                str2[i++]=MACS[j];
            }
            else
                str2[i++]=MACS[j];
         }
         p=p/10;
         j++;
    }
    return str2;
}
int main()
{
    int i,j,num1,num2;

    char str[1000];
    scanf("%s",str);
    num1 = decode(str);
    scanf("%s",str);
    num2 = decode(str);
    printf("%s\n",encode(num1+num2));
}
