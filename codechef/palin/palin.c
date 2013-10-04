#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    int n,i,j,l,k,carry,t;
    char str[1000001],c=0;
    long num;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",str);
        carry=1;
        while(1)
        {
            carry = 1;
            l = strlen(str);
            j=l;
            printf("%s\n",str);
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

            t=1;
            if(str[l-1]!='0')
            for(j=0;j<l/2;j++)
            {
                if(str[j] != str[l-j-1])
                {
                    t = 0;
                    break;
                }
            }
            else
                t=0;

            if(t == 1)
            {
                printf("%s\n",str);
                break;
            }
        }
    }
}
