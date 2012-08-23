#include<stdio.h>

void quicksort(int arr[],int i,int j)
{
	int pivotindex,k,pivot;
	pivotindex=findpivot(arr,i,j);
	if(pivotindex!-1)
	{
		pivot=arr[pivotindex];
		k=partition(arr,i,j,pivot);
		quicksort(arr,i,k-1);
		quicksort(arr,k,j);
	}
}

int findpivot(int arr[],int i,int j)
{
	int first=arr[i],k;
	for(k=i+1;k<=j;k++)
		if(first!=A[k])
			return A[k]<first?i:k;
	return -1;
}
int partition(int arr[],int i,int j,int piv)
{
	int l=i,r=j,temp;
	do
	{
		temp=arr[l];
		arr[l]=arr[r];
		arr[r]=temp;
		while(arr[l]<piv)
			l++;
		while(arr[r]>=piv)
			r--;
	}while(l<=r);
	return l;
}
main()
{
	int arr[10],n,i;
	printf("\nEnter limit ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quicksort(arr,0,n-1);
}
