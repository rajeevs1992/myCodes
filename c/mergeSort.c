#include<stdio.h>
void mergesort(int a[],int low,int high)
{
	int mid=(low+high)/2;
	if(high-low!=0)
	{
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void merge(int a[],int low,int mid,int high)
{
	int i=low,j=mid+1,k=0,array[10];
	while(i<=mid && j<=high)
		array[k++]=(a[i]<=a[j])?a[i++]:a[j++];
	while(i<=mid)
		array[k++]=a[i++];
	while(j<=high)
		array[k++]=a[j++];
	i=low;
	j=0;
	while(i<=high)
		a[i++]=array[j++];
}

main()
{
	int a[20],n,i;
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	mergesort(a,0,4);
	for(i=0;i<5;i++)
		printf("%d\t",a[i]);
}

