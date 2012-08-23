#include<stdio.h>
#include<stdlib.h>
#define SIZE(n) (n+8-(n%8))/8
main(char argc,char *argv[])
{
	int upper=atoi(argv[1])+1,temp,i;
	unsigned char list[SIZE(upper)];
	for(temp=0;temp<SIZE(upper);list[temp++]=0);
	printf("\nEnter list ");
	scanf("%d",&temp);
	while(temp<upper)
	{
		list[temp/8]=list[temp/8]|(1<<temp%8);
		scanf("%d",&temp);
	}
	for(temp=0;temp<SIZE(upper);temp++)
		for(i=0;i<8;i++)
			if(list[temp]&(1<<i))
				printf("%d\t",temp*8+i);
	printf("\n");
}
