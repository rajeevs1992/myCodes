#include<stdio.h>
#include<math.h>
void sine(double ,double );
void cosine(double ,double );
void exponent(double ,double );
main()
{
	unsigned char ch;
	double x,accuracy;
	printf("\nSelect series\n1.sine\n2.cosine\n3.exponent : ");
	scanf("%d",&ch);
	printf("\nEnter the value of x ");
	scanf("%lf",&x);
	if(ch==1||ch==2)
		x*=M_PI/180;
	printf("\nEnter the accuracy ");
	scanf("%lf",&accuracy);
	switch(ch)
	{
		case 1:
			sine(x,accuracy);
			break;
		case 2:
			cosine(x,accuracy);
			break;
		case 3:
			exponent(x,accuracy);
			break;
	}
}
void sine(double x,double accuracy)
{
	int n=1;
	double term=x,sin=0,k=1;
	while(k>accuracy)
	{
		sin+=term;
		term*=(-x)*x/((n+2)*(n+1));
		k=term<0?-term:term;
		n+=2;
	}
	printf("\nsin value is %lf \n",sin);
}
void cosine(double x,double accuracy)
{
	int n=0;
	double term=1,cos=0,k=1;
	while(k>accuracy)
	{
		cos+=term;
		term*=(-x)*x/((n+2)*(n+1));
		k=term<0?-term:term;
		n+=2;
	}
	printf("\ncos value is %lf \n",cos);
}
void exponent(double x,double accuracy)
{
	int n=1;
	double term=x,exp=0;
	while(term>accuracy)
	{
		exp+=term;
		term*=x/n++;
	}
	printf("\ne^%lf is %lf \n",x,exp);
}

Output:
rajeevs@rajeev:~/myFiles/programs$ cc series.c
rajeevs@rajeev:~/myFiles/programs$ ./a.out

Select series
1.sine
2.cosine
3.exponent : 1

Enter the value of x 30

Enter the accuracy .0000001

sin value is 0.500000 

