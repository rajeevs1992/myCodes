#include<stdio.h>
char array[50],lt,token;
void binarySearch(char lower,char upper,char mid);
main()
{
	char i;
	printf("\nEnter limit ");
	scanf("%d",&lt);
	for(i=0;i<lt;scanf("%d",&array[i++]));
	printf("\nEnter the item to be searched for ");
	scanf("%d",&token);
	binarySearch(0,lt-1,(0+lt-1)/2);
}

void binarySearch(char lower,char upper,char mid)
{
	if(mid<lower||mid>upper)
	{
		printf("\nNot Found!!!!!\n");
		return;
	}
	array[mid]==token?printf("\nFound at position %d\n ",mid+1)	:array[mid]>token?binarySearch(lower,mid-1,(lower+mid-1)/2):binarySearch(mid+1,upper,(mid+1+upper)/2);
}
