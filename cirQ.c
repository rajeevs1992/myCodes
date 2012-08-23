#include<stdio.h>
#define MAXLENGTH 50
struct queue
{
	int queue[MAXLENGTH];
	int front=0;
	int rear=-1;
}q;
struct queue push(struct queue q,int element);
struct queue pop(struct queue q);
main()
{
	int n,element;
	printf("\n1.Push\n2.Pop\n3.Exit\nChoice ");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("\nEnter the element ");
			scanf("%d",&element);
			queue=push(queue,element);
			break;
		case 2:
			element=pop(queue);
			printf("\nPopped %d\n",element);
			break;
	}
}

struct queue push(struct queue q,int element)
{
	if(q.rear+1==front)
		printf("\nQueue full ");
	else
	{
		int pos=
struct queue pop(struct queue q);
	
