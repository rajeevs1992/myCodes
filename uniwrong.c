#include<stdio.h>
#define CUBE(n) n*n*n
int armstrong(int n);
int prime(int n);
int main()
{
	int n,i;
	printf("\nEnter number ");
	scanf("%d",&n);
	if(armstrong(n))
		for(i=1;i<=n;i++)
			if(prime(i))
				printf("%d ",i);
	else
		printf("\nNot Armstrong ");
}

int armstrong(int n)
{
	int temp=n,t,sum=0;
	while(n)
	{
		t=n%10;
		sum+=CUBE(t);
		n=n/10;
	}
	if(sum==temp)
		return 1;
	return 0;
}

int prime(int n)
{
	int i;
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	for(i=2;i<=n/2;i++)
		if(n%i==0)
			return 0;
	return 1;
}


