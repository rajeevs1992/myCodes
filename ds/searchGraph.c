#include<stdio.h>
char visited[50];
char adjacency[50][50];
int n;
void create();
void dfs(int v);
void bfs(int v);

main()
{
	int vertex,ch;
	create();
	printf("\nEnter Mode\t1.DFS\t2.BFS\nChoice : ");
	scanf("%d",&ch);
	printf("\n Enter the starting vertex ");
	scanf("%d",&vertex);
	switch(ch)
	{
	case 1:
		dfs(vertex);
		for(vertex=1;vertex<=n;vertex++)
			if(visited[vertex]==0)
				dfs(vertex);
		break;
	case 2:
		bfs(vertex);
		for(vertex=1;vertex<=n;vertex++)
			if(visited[vertex]==0)
				bfs(vertex);
		break;
	default:
		printf("\nInvalid input ");
		break;
	}
}

void create()
{
	int i,j,origin,destn,max;
	printf("\nEnter the number of vertex ");
	scanf("%d",&n);
	max=n*(n-1);
	for(i=1;i<=max;i++)
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
			adjacency[origin][destn]=1;
	}
	for(i=1;i<=n;i++)
		visited[i]=0;
}

void dfs(int v)
{
	int w;
	printf("Visited %d \n",v);
	visited[v]=1;
	for(w=1;w<=n;w++)
		if(adjacency[v][w]==1 && visited[w]==0)
			dfs(w);
}

void bfs(int v)
{
	int i,j,queue[50],rear=0,front=0;
	queue[rear++]=v;
	visited[v]=1;
	while(rear > front)
	{
		i=queue[front++];
		printf("Visited %d \n",i);
		for(j=1;j<=n;j++)
			if(adjacency[i][j]==1 && visited[j]==0)
			{
				visited[j]=1;
				queue[rear++]=j;
			}
	}
}

