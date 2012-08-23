#include<stdio.h>
main()
{
	FILE *fp;
	fp=fopen("/dev/sdc1","w");
	fclose(fp);
}
