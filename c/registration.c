#include<stdio.h>
#define SIZE(n) (n+8-(n%8))/8
struct regno
{
	char district;
	char series[2];
	char numbers[SIZE(9999)];
}user;

int main(char argc,char *argv[])
{
	if(argc==1)
		printf("\nUsage : check <district_code> <series> <number> ");
	else
	{
		FILE *fp=fopen("reg","rab");
		while(fread(&s,sizeof s,1,fp))
			if(s.district==atoi(argv[1]))
				if(!strcmp(series,argv[2]))
					if(s.numbers[atoi(argv[3])]

}
		
	
