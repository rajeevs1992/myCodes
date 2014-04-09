#include<stdio.h>
struct map
{
    int count;
    int indices[15000];
};
int main()
{
    int t,i,j;
    char ch,p[15000],key[26];
    scanf("%d",&t);
    while(t--)
    {
        ch=getchar();
        i=0;
        while(ch!=10 || ch!=EOF)
        {
            p[i++]=ch;
            ch=getchar();
        }
        p[i]=0;
        puts(p);

        
    }
    
    
    return 0;
}
