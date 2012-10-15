#include<stdio.h>
void invert(float matrix[10][10],float inverse[10][10],int n);
main()
{
	float matrix[10][10],inverse[10][10];
	int n,i,j;
	printf("\nEnter the order ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%f",&matrix[i][j]);
			if(i==j)
				inverse[i][j]=1;
			else
				inverse[i][j]=0;
		}

	printf("%d",n);
	invert(matrix,inverse,n);

}

void invert(float matrix[10][10],float inverse[10][10],int n)
{
	int i,j,k,l;
	
	for(i=0;i<n;i++)	
	{

		int t=matrix[i][i];
		for(l=n-1;l>=0;l--)
		{
			matrix[i][l]/=t;
			inverse[i][j]/=t;
		}
		for(j=0;j<n;j++)
		{
			if(j!=n && matrix[i][j]>0)
				for(k=0;k<n;k++)
				{
					matrix[j][k]=matrix[j][k]-(matrix[i][j]*matrix[i][k]);
					inverse[j][k]=inverse[j][k]-(matrix[i][j]*inverse[i][k]);
				}
			else if(j!=n && matrix[i][j]<0)
				for(k=0;k<n;k++)
				{
				        matrix[j][k]=matrix[j][k]+(matrix[i][j]*matrix[i][k]);
					inverse[j][k]=inverse[j][k]+(matrix[i][j]*inverse[i][k]);
				}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("\t%f\t",matrix[i][j]);
	}
}


