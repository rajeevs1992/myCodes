#include<stdio.h>
#include<string.h>
void swap(char *x,char *y)
{
	char temp=*x;
	*x=*y;
	*y=temp;
}
void permut(char *a,int i,int n)
{
	int j;
	if(i==n)
		printf("%s \n",a);
	else
		for(j=i;j<=n;j++)
		{
			swap((a+i),(a+j));
			permut(a,i+1,n);
			swap((a+i),(a+j));
		}
}
int main()
{
	char a[20];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a);
	    permut(a,0,strlen(a)-1);
    }
}
