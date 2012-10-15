#include<stdio.h>
int a[10];
void qs(int i,int j)
{
	int pivot,index,k;
	index=findpivot(i,j);
	if(index!=-1)
	{
		pivot=a[index];
		k=partition(i,j,pivot);
		qs(i,k-1);
		qs(k,j);
	}
}

int partition(int i,int j,int pivot)
{
	int l=i,r=j;
	do
	{
		int t=a[l];
		a[l]=a[r];
		a[r]=t;
		while(a[l]<pivot)
			l++;
		while(a[r]>=pivot)
			r--;
	}
	while(l<=r);
	return l;
}

int findpivot(int i,int j)
{
	int first=a[i],k;
	for(k=i+1;k<=j;k++)
		if(a[k]>first)
			return k;
		else if(a[k]<first)
			return i;
	return -1;
}

main()
{
	int n,i;
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	qs(0,4);
	for(i=0;i<5;i++)
		printf("%d\t",a[i]);
}
