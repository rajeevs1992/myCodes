#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
typedef struct node node;
main()
{
	int arr[50],n,i,j,k,max=0,tens=1,temp,bucket;
	node table[10],*tempNode,*data;
	printf("\nEnter the limit ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]>max)
			max=arr[i];
	}
	for(i=0;i<10;i++)
	{
		table[i].data=0;
		table[i].next=NULL;
	}
	while(max)
	{
		for(i=0;i<n;i++)
		{
			temp=arr[i];
			bucket=(temp/tens)%10;
			if(table[bucket].next!=NULL)
			{
				tempNode=table[bucket].next;
				while(tempNode->next!=NULL)
					tempNode=tempNode->next;
				data=(node *)malloc(sizeof(node));
				data->data=temp;
				data->next=NULL;
				tempNode->next=data;
			}
			else
			{
				data=(node *)malloc(sizeof(node));
				data->data=temp;
				data->next=NULL;
				table[bucket].next=data;
			}
		}
		tens=tens*10;
		max=max/10;
		k=0;
		for(j=0;j<10;j++)
		{
			if(table[j].next!=NULL)
			{
				tempNode=table[j].next;
				while(tempNode!=NULL)
				{
					arr[k++]=tempNode->data;
					tempNode=tempNode->next;
				}
			}
			table[j].data=0;
			table[j].next=NULL;
		}
	}
	for(i=0;i<n;i++)
			printf("%d\t",arr[i]);
}
