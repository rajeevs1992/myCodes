#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,count=0;
    char str[27],seed[27],begin='A';
    scanf("%d",&n)
    scanf("%s",str);
    for(i=0;i<n;i++)
        seed[i] = begin++;
    for(i=0;i<n;i++)
        for(j=n-1;j>=0;j--)
        {   
            begin=str[j];
            for(k=0;seed[j]<'Z'+1;k++)
            {
                count++;
                seed[j]=begin++;
                if(strcmp(seed,str))
                {   
                    printf("%d\n",count);
                    return 0;
                }
            }
            
        }
    return 0;
}
