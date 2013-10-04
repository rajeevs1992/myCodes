#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[100][101];
int compare(const void* a, const void* b)
{
    const char *ia = (const char *)a;
    const char *ib = (const char *)b;
    return strcmp(ia, ib);
}
int winner(int n)
{   
    int i,j;
    qsort(&str,n,sizeof(str[0]),compare);
    for(i=0;i<n;i++)
    {
        if(str[i][0] == 0)
            return 0;
        else if(strcmp(str[i],str[i+1]) == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int n,player=1,i,j,l;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s",str[i]);
    while(winner(n))
    {
        if(player == 0)
            player = 1;
        else
            player = 0;
        for(i=0;i<n;i++)
        {
           // printf("%s\t",str[i]);
            l=strlen(str[i]);
            for(j=0;j<l;j++)
                str[i][j]=str[i][j+1];
            str[i][j]=0;
        }
    }
    if(player == 0)
        printf("Holmes\n");
    else
        printf("Watson\n");
    return 0;
}
