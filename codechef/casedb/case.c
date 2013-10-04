#include<stdio.h>
#include<string.h>
char str[100][100];
void inc(int j)
{
    int carry=1,j,k,l;
    j=l=strlen(str[p]);
            do
            {
                --j;
                if(str[j] == '1' && carry == 1)
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
}
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s",str[i]);
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(str[i],str[j])==0)
            {
                inc(j)
            }
        }
    }
    for(i=0;i<n;i++)
}

