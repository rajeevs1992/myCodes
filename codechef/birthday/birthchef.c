#include<stdio.h>
#include<string.h>
int has_7(char* c)
{   
 //   printf("%s\n",c);
    int i;
    for(i=0;c[i]!=0;i++)
        if(c[i]=='7')
            return 1;
    return 0;
}
void addone(char str[])
{
    int l=strlen(str),k,j,carry=1;
    j=l;
    do
    {
        --j;
        if(str[j] == '9' && carry == 1)
        {
            carry = 1;
            str[j] = '0';
        }
        else if(j == -1 && carry == 1)
        {
            str[l+1] = 0;
            for(k=l;k>=0;k--)
            {
                str[k] = str[k-1];
            }
            l++;
            str[0] = '1';
            carry = 0;
        }
        else
        {
            str[j] = str[j] + carry;
            carry = 0;
        }
    }while(carry != 0);
//    printf("%s\t",str);
}            
int main()
{
    int n,i=0,adder=1,j=0;
    char c[102]="1",p[102];
    scanf("%d",&n);
    while(n--)
    {
    scanf("%s",p);
    while(1)
    {
        i = i+adder;
        if(i==1337+1)
            i=1;
        else if(i==0)
            i=1337;
        if(strcmp(c,p)==0)
        {
            printf("%d\n",i);
            break;
        }
        if(has_7(c) && div(c))
        {
            adder = adder*-1;
        }
       printf("%d\t",i);
       addone(c);
       j=(j+1)%7;
    }
    }
}

