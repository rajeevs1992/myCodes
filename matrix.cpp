#include<iostream>
#include<math.h>
using namespace std;
int det22(int **mat22);
int Det(int **mat,int order);
int **minor(int **mat,int order,int i);


int Det(int **mat,int order)
{
	int det=0;
	if(order==2)
		return det22(mat);
	else if(order==1)
		return mat[0][0];
	else
		for(int i=0;i<order;i++)
			det+=pow(-1,i)*mat[0][i]*Det(minor(mat,order,i),order-1);
}

int ** minor(int **mat,int order,int i)
{
	int **temp,l=0;
	for(int j=1;j<order;j++)
	{
		for(int k=0;k<order;k++)
			if(k!=i)
				temp[j][l++]=mat[j][k];
		l=0;
	}
	return temp;
}


		
int det22(int **mat22)
{
	int det=(mat22[0][0]*mat22[1][1])-(mat22[1][0]*mat22[0][1]);
	return det;
}
int main()
{
	int **matrix,det,m;
	cout<<"\nEnter the order of matrix\n ";
	cin>>m;
	matrix=new int*[m];
	for (int i=0;i<m;i++)
		for (int j=0;j<m;j++)
			cin>>matrix[i][j];
	det=Det(matrix,m);
	cout<<det;
}
