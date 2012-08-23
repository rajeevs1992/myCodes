#include<stdio.h>
main()
{
	int no;
	while(1)
	{
	input:
		printf("\nEnter the number :");
		scanf("%d",&no);
		if (no<0)
			goto input;
		no==1?printf("\nNot prime and not composite!\n"):prime(no);
	}
}

void prime(int no)
{
	int flag=1,i;
	for(i=2;i<no/2;i++)
	{
		flag=1;
		if(no%i==0)
		{
			flag=0;
			printf("\nComposite!\n");
			break;
		}
	}
	if(flag==1)
		printf("\nPrime\n");
}
