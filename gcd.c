#include<stdio.h>
void gcd(int,int);
int t1,t2;

void main()
{
	int a,b;
	printf("\nEnter the nos ");
	scanf("%d%d",&a,&b);
	t1=a;
	t2=b;
	gcd(a,b);
}
//GCD using Euclid's Algorithm
void gcd(int a,int b)
{
	if(a==0)
	{
		printf("\nGCD is %d and LCM is %d",b,t1*t2/b);
		exit(0);
	}
	a>=b?gcd(a%b,b):gcd(b%a,a);
}

