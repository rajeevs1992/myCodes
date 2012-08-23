#include<stdio.h>
#include<stdlib.h>
void sort(int arr[],int);
int calMode(int arr[],int);
int main()
{
	int arr[50],n,i,sum=0;
	float avg,median,mode;
	printf("\nEnter number of elements ");
	scanf("%d",&n);
	printf("\nEnter array ");
	for(i=0;i<n;i++)
	{
		printf("\n%d  ",i+1);
		scanf("%d",&arr[i]);
	}
	sort(arr,n);
	for(i=0;i<n;i++)
		sum+=arr[i];
	avg=sum/(float)n;
	median=(n%2==0)?(arr[(n/2)]+arr[(n/2)-1])/2.0:arr[(n-1)/2];
	mode=calMode(arr,n);
	printf("\nMean is %.3f\nmedian is %.3f \nMode is %.3f\n",avg,median,mode);
	return 0;
}
int calMode(int arr[],int lt)
{
	int i,c=1,t=0,mode;
	for(i=0;i<lt;i++)
	{
		if(arr[i]==arr[i+1])
			c++;
		else if(c>t)
		{
			t=c;
        	c=1;
			mode=arr[i];
		}
		else if(c==t)
			mode=0;
	}
	return mode;
}

void sort(int arr[],int lt)
{
	int i,j;
	for(i=0;i<lt;i++)
		for(j=0;j<lt-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				int t=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=t;
			}
		}
}


