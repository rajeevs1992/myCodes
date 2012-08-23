#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<limits.h>
#include<string.h>
main()
{
	char files[20];
	char destn[20];
	int i=0;
	printf("Parent %d\n",getpid());
	for(i=0;i<3;i++)
	{
		gets(files);
		if(fork()==0)
		{
			int a=INT_MAX;
			while(a--);
			sprintf(destn,"dir/%s",files);
			FILE *rp=fopen(files,"r");
			FILE *dp=fopen(destn,"w");
			char ch='1';
			printf("Child %d file:%s\n",getpid(),files);
			while(ch>0)
			{
				ch=fgetc(rp);
				fputc(ch,dp);
			}
			fputc(EOF,dp);
			fclose(rp);
			fclose(dp);
			_exit(0);
		}
	}
}

ÿÿ