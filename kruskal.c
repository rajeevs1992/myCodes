#include<stdio.h>
#include<stdlib.h>
#define MAX 20
struct edge
{
	int u;
	int v;
	int weight;
	struct edge *link;
}*front =NULL;

int father[MAX];
struct edge tree[MAX];
int n;
int wt_tree=0;
int count=0;

void make_tree();
void create_graph();
void insert_tree(int i,int j,int wt);
void insert_pque(int i,int j,int wt);
struct edge *del_pque();
main()
{
	int i;
	create_graph();
	make_tree();
	printf("\nEdges to be included in spanning tree are :\n");
	for(i=1;i<=count;i++)
	{
		printf("%d->",tree[i].u);
		printf("%d\n",tree[i].v);
	}
}

void create_graph()
{
	int i,wt,max_edges,origin,destn;
	printf("\nEnter num of edges ");
	scanf("%d",&n);
	max_edges=n*(n-1)/2;
	for(i=1;i<=max_edges;i++)
	{
		printf("\nEnter an edge:<origin> <destn>(0 0 to stop) ");
		scanf("%d%d",&origin,&destn);
		if (origin==0 && destn ==0)
			break;
		if(origin > n || destn > n|| origin <=0 || destn <=0)
		{
			printf("\nInvalid edge ");
			i--;
		}
		else
		{
			printf("\nEnter cost of edge %d----%d ",origin,destn);
			scanf("%d",&wt);
			insert_pque(origin,destn,wt);
			insert_pque(destn,origin,wt);
		}
	}
	if(i<n-1)
	{
		printf("\nSpanning tree not possible \n");
		exit(1);
	}
}

void make_tree()
{
	struct edge *tmp;
	int node1,node2,root_n1,root_n2;
	while(count<n-1)
	{
		tmp=del_pque();
		node1=tmp->u;
		node2=tmp->v;
		printf("n1->%d",node1);
		printf("n2->%d",node2);
		while(node1>0)
		{
			root_n1=node1;
			node1=father[node1];
		}
		while(node2>0)
		{
			root_n2=node2;
			node2=father[node2];
		}
		printf("rootn1=%d ",root_n1);
		printf("rootn2=%d ",root_n2);
		if(root_n1!=root_n2)
		{
			insert_tree(tmp->u,tmp->v,tmp->weight);
			wt_tree=wt_tree+tmp->weight;
			father[root_n2]=root_n1;
		}
	}
}

void insert_tree(int i,int j,int wt)
{
	count++;
	tree[count].u=i;
	tree[count].v=j;
	tree[count].weight=wt;
}

void insert_pque(int i,int j,int wt)
{
	struct edge *tmp,*q;
	tmp=(struct edge *)malloc(sizeof(struct edge));
	tmp->u=i;
	tmp->v=j;
	tmp->weight=wt;
	if(front == NULL || tmp->weight<front->weight)
	{
		tmp->link=front;
		front=tmp;
	}
	else
	{
		q=front;
		while(q->link !=NULL && q->link->weight <=tmp->weight)
			q=q->link;
		tmp->link=q->link;
		q->link=tmp;
		if(q->link==NULL)
			tmp->link=NULL;
	}
}

struct edge *del_pque()
{
	struct edge *tmp;
	tmp=front;
	front=front->link;
	return tmp;
}

Output
rajeevs@rajeev:~/myFiles/programs/myCodes$ cc kruskal.c 
rajeevs@rajeev:~/myFiles/programs/myCodes$ ./a.out

Enter num of edges 6

Enter an edge:<origin> <destn>(0 0 to stop) 1 3 14 

Enter cost of edge 1----3 
Enter an edge:<origin> <destn>(0 0 to stop) 1 4 9

Enter cost of edge 1----4 
Enter an edge:<origin> <destn>(0 0 to stop) 1 2 5

Enter cost of edge 1----2 
Enter an edge:<origin> <destn>(0 0 to stop) 2 4 11

Enter cost of edge 2----4 
Enter an edge:<origin> <destn>(0 0 to stop) 2 6 3

Enter cost of edge 2----6 
Enter an edge:<origin> <destn>(0 0 to stop) 1 5 7

Enter cost of edge 1----5 
Enter an edge:<origin> <destn>(0 0 to stop) 3 4 2

Enter cost of edge 3----4 
Enter an edge:<origin> <destn>(0 0 to stop) 3 5 8

Enter cost of edge 3----5 
Enter an edge:<origin> <destn>(0 0 to stop) 4 5 4

Enter cost of edge 4----5 
Enter an edge:<origin> <destn>(0 0 to stop) 4 6 6

Enter cost of edge 4----6 
Enter an edge:<origin> <destn>(0 0 to stop) 5 6 19

Enter cost of edge 5----6 
Enter an edge:<origin> <destn>(0 0 to stop) 0 0
Edges to be included in spanning tree are :
3->4
2->6
4->5
1->2
4->6

