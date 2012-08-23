#include<stdio.h>
#include<stdlib.h>
struct node
{
	int number;
	struct node *next;
};
typedef struct node node;
node head[10];
int list[100];
void insert(int element,int pass);
int bucket(int element,int pass);
int calDigit(int max);
void getList();
main()
{
	int lt,i,j,max=0,num;
	printf("\nEnter the number of elements ");
	scanf("%d",&lt);
	for(i=0;i<10;i++)
		head[i].next=NULL;
	for(i=0;i<lt;i++)
	{
		printf("\nEnter the number %d ",i+1);
		scanf("%d",&num);
		if(num<0)
		{
			printf("\nNegetive numbers not allowed!! ");
			i--;
			continue;
		}
		if(num>max)
			max=num;
		insert(num,1);
	}
	max=calDigit(max);
	for(i=2;i<=max;i++)
	{
		getList();
		for(j=0;j<lt;j++)
			insert(list[j],i);

	}
	getList();
	for(i=0;i<lt;i++)
		printf("%d\t",list[i]);
}
	
void insert(int element,int pass)
{
	int b=bucket(element,pass);
	node *temp=head[b].next,*temp2;
	temp2=(node *)malloc(sizeof(temp2));
	temp2->number=element;
	temp2->next=NULL;
	if(temp!=NULL)
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=temp2;
	}
	else
		head[b].next=temp2;
}

int bucket(int element,int pass)
{
	int i=0,pow=1;
	for(i=0;i<pass;i++)
		pow=pow*10;
	return ((element%pow)*10/pow);
}

int calDigit(int max)
{
	int i=1;
	while(max)
	{
		max=max/10;
		i++;
	}
	return i;
}

void getList()
{
	int index=0,i;
	node *temp;
	for(i=0;i<10;i++)
	{
		temp=head[i].next;
		while(temp!=NULL)
		{
			list[index++]=temp->number;
			temp=temp->next;
		}
	}
}

