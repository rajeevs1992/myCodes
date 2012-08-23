#include<stdio.h>
struct house
{
	int size;
	float cost;
}h;
float trainingSet[50][2],learningRate;
int m;
void populateTrainingSet()
{
	int i=0;
	FILE *fp=fopen("TrainingSet","r");
	while(fread(&h,sizeof(h),1,fp)!=0)
	{
		trainingSet[i][0]=h.size;
		trainingSet[i][1]=h.cost;
		printf("%f %f \n",trainingSet[i][0],trainingSet[i][1]);
		i++;
	}
	m=i;
}
float hypothesis(float x,float x0,float x1)
{
	return (x0+(x*x1));
}

float der_x0(float x0,float x1)
{
	int i=0;
	float sum=0;
	for(i=0;i<m;i++)
		sum+=hypothesis(trainingSet[i][0],x0,x1)-trainingSet[i][1];
	sum=sum/m;
	printf("%f",sum);
	return sum;
}
float der_x1(float x0,float x1)
{
	int i=0;
	float sum=0;
	for(i=0;i<m;i++)
		sum+=(hypothesis(trainingSet[i][0],x0,x1)-trainingSet[i][1])*trainingSet[i][0];
	sum=sum/m;
	return sum;
}
void gradientDescent(float x0,float x1)
{
	float a=x0,b=x1,temp0,temp1;
	temp0=x0-(learningRate*der_x0(x0,x1));
	temp1=x1-(learningRate*der_x1(x0,x1));
	x0=temp0;
	x1=temp1;
	printf("x0=%f\tx1=%f\n",x0,x1);
	getchar();
	temp0=a-x0;
	temp1=b-x1;
	temp0=temp0<0?temp0*-1:temp0;
	temp1=temp1<0?temp1*-1:temp1;
	if(temp1<.001&&temp0<.001)
	{
		printf(" %f %f\n ",x0,x1);
		exit(0);
	}
	gradientDescent(x0,x1);
}

int main()
{
	populateTrainingSet();
	printf("\nEnter the learning rate ");
	scanf("%f",&learningRate);	
	gradientDescent(0,0);
}
