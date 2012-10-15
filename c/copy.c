#include<stdio.h>
#include<stdlib.h>
void push(int item,int *rear ,int Q[],int l,int no);
void pop(int *front ,int Q[],int l,int no,int *rear);
int main()
{
	int NumberOfQ,*Q,LengthOfQ,*front,*rear,choice,QNumber,i,item;
	printf("\nEnter the number of Queues ");
	scanf("%d",&NumberOfQ);
	printf("\nEnter length of each Queue ");
	scanf("%d",&LengthOfQ);
	Q=(int *)malloc(sizeof(Q)*LengthOfQ*NumberOfQ);
	rear=(int *)malloc(sizeof(rear)*NumberOfQ);
	front=(int *)malloc(sizeof(rear)*NumberOfQ);
	for(i=0;i<NumberOfQ;i++)
	{
		rear[i]=i*LengthOfQ;
		front[i]=i*LengthOfQ;
	}
	while(1)
	{
		printf("\nSelect operation \n1.PUSH\n2.POP\n3.QUIT ");
		scanf("%d",&choice);
		system("clear");
		if(choice == 3)
			exit(0);
		do
		{
			printf("\nEnter Queue number ");
			scanf("%d",&QNumber);
		}while(QNumber>NumberOfQ);
		switch(choice)
		{
			case 1:
				printf("\nEnter the item to be pushed ");
				scanf("%d",&item);
				push(item,&rear[QNumber-1],Q,LengthOfQ,QNumber);
				break;
			case 2:
				pop(&front[QNumber-1],Q,LengthOfQ,QNumber,&rear[QNumber-1]);
				break;
		}
	}
}

void push(int item,int *rear,int Q[],int l,int no)
{
	if(*rear==(l*(no)))
		printf("\nQueue Full!!!!!!!!Cant push!!!!!");
	else
	{
		printf("\nPushing %d to Queue ",item);
		Q[(*rear)++]=item;
	}
}

void pop(int *front,int Q[],int l,int no,int *rear)
{
	if(*front==l*(no))
	{
		printf("\nQueue empty!!!!!! Cant POP ");
		*rear=l*(no-1);
		*front=l*(no-1);
	}
	else
		printf("\nPOPped %d !!!!!!!",Q[(*front)++]);
}
