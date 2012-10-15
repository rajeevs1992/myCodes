#include<stdio.h>
void pushdown(int *A,int first,int last);
void heapsort(int *A,int n);
void display(int *A,int n);
void swap(int *A,int a,int b);
main()
{
	int A[100],n,i;
	printf("\nEnter the number of elements ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	heapsort(A,n);
	display(A,n);
}

void heapsort(int *A,int n)
{
	int i;
	for(i=n/2;i>=1;i--)
		pushdown(A,i,n);
	for(i=n;i>=2;i--)
	{
		swap(A,1,i);
		pushdown(A,1,i-1);
	}
}
void pushdown(int *A,int first,int last)
{
	int r=first;
	while(r<=last/2)
	{
		if(last==2*r)
		{
			if(A[r]>A[2*r])
			{
				swap(A,r,2*r);
				r=last;
			}
		}
		else
		{
			if(A[r]>A[2*r] && A[2*r]<=A[2*r +1])
			{
				swap(A,r,2*r);
				r=2*r;
			}
			else if(A[r]>A[2*r+1] && A[2*r+1]<A[2*r])
			{
				swap(A,r,2*r+1);
				r=2*r+1;
			}
			else
				r=last;
		}
	}
}

void display(int *A,int n)
{
	int i=0;
	printf("\n");
	for(i=0;i<n;i++)
		printf("\t%d",A[i]);
	printf("\n");
}

void swap(int *A,int a,int b)
{
	int t=A[a];
	A[a]=A[b];
	A[b]=t;
}
