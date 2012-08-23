#include<stdio.h>
int Det2x2(int *);
void inverse(int matrix[10][10],int n,int det);
int * Cofactor(int *,int ,int,int );
int  Det(int *,int,int,int);
void main()
{
	int i,j,order,Mat[10][10],det=0;
	printf("Enter the rows OR columns of the matrix :\n");
	scanf("%d",&order);
	for(i=0;i<order;i++,printf("\n"))
		for(j=0;j<order;j++)
			scanf("%d",&Mat[i][j]);
	printf("%d",Det(Mat,0,0,order));
	invert(Mat,order,Det(Mat,0,0,order));
}
void invert(int matrix[10][10],int n,int det)
{
	float inv[10][10];
	char i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			inv[j][i]=pow(-1,i+j)*Det(Cofactor(matrix,i,j,n),i,j,n-1)/det;
	for (i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d ",inv[i][j]);
	}
}

int Det(int *M,int i,int j,int n)
{
	int det=0;
	if(n==2)
		return Det2x2(M);
	else if(n==1)
		return *M;
	else
		for(j=0;j<n;j++)
			 det+=pow(-1,j)*(*(M+j))*Det(Cofactor(M,0,j,n),i,j,n-1);
	return det;	
}
int Det2x2(int *M)
{
	return (*M)*(*(M+11))-(*(M+1))*(*(M+10));
}
int * Cofactor(int *M,int i,int j,int n)
{
	int k,l,p=0,q=0,*Mat[10][10];
	for(k=0;k<n;k++)
	{
		if(i!=k)
		{
		for(l=0;l<n;l++)
			if(l!=j)
				Mat[p][q++]=*(M+10*k+l);	
		}
		p++;q=0;
	}
	return Mat;
}
