#include<stdio.h>
main()
{
	int n,i=1,j=1,wt,C[10][10],D[10],V=0,S=2,VmS=0;
	printf("\nEnter the number of vertices ");
	scanf("%d",&n);
	while(i!=0 && j!=0)
	{
		printf("\nEnter the edge and weight ");
		scanf("%d%d%d",&i,&j,&wt);
		C[i][j]=wt;
	}
	for(i=2;i<=n;i++)
		D[i]=C[1][i];
	for(i=1;i<=n;i++)
		V=V|1<<i;
	for(i=0;i<n;i++)
	{
		wt=0;
		for(j=1;j<=n;j++)
		{
			if((((~(V>>1))<<1)^S)>>j)
				if(
