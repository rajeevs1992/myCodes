#include<stdio.h>
#include<ctype.h>
struct student
{
	char admn_no[10];
	char dept[5];
	char name[20];
	char sem;
	int mark[5];
}s;
char getch()
{
	system("stty raw");
	char ch=getchar();
	system ("stty cooked");
	return ch;
}
void writeToFile(struct student s,char filename[])
{
		FILE *fp;
		fp=fopen(filename,"a");
		fwrite(&s,sizeof(s),1,fp);
		fclose(fp);
}
void showdata(struct student s)
{
	printf("\nName %s\nAdmission No %s\nDept %s\nSemester %d\n",s.name,s.admn_no,s.dept,s.sem);
}

void displayFullData()
{
	FILE *fp;
	fp=fopen("data","r");
	while(fread(&s,sizeof(s),1,fp))
		printf("\nName %s\nAdmission No %s\nDept %s\nSemester %d\n",s.name,s.admn_no,s.dept,s.sem);
	fclose(fp);
	getch();
}
void search()
	{
		printf("\nSearch by\n'N'ame\n'A'dmn No\n ");
		FILE *fp;
		char key[20];
		fp=fopen("data","r");
		switch(tolower(getch()))
		{
			case 'n':
				printf("\nEnter name ");
				gets(key);
				while(fread(&s,sizeof(s),1,fp))
				{
					if(strcmp(s.name,key)==0)
					{
						showdata(s);
						getch();
					}
				}
				break;
			case 'a':		
				printf("\nEnter admission number ");
				gets(key);
				while(fread(&s,sizeof(s),1,fp))
					if(strcmp(s.admn_no,key)==0)
					{
						showdata(s);
						getch();
					}
			}	
}
void getdata()
{
	system("clear");
	int i=0;
	printf("\nEnter admission number :");
	gets(s.admn_no);
	printf("\nEnter name ");
	gets(s.name);
	printf("\nEnter Department ");
	gets(s.dept);
	printf("\nEnter semester ");
	scanf("%d",&s.sem);
	printf("\nEnter marks in 5 subjects ");
	for(i=0;i<5;i++)
		scanf("%d",&s.mark[i]);
	writeToFile(s,"data");
}
void del()
{
	char key[25];
	FILE *fp,*temp;
	fp=fopen("data","r");
	printf("\nAvalable admission numbers ");
	while(fread(&s,sizeof(s),1,fp))
		printf("\n%s",s.admn_no);
	printf("\nEnter admission number of student to be deleted ");
	gets(key);
	fseek(fp,0,SEEK_SET);
	temp=fopen("temp","a");
	while(fread(&s,sizeof(s),1,fp))
		if(strcmp(key,s.admn_no)!=0)
			fwrite(&s,sizeof(s),1,temp);
	fclose(fp);
	fclose(temp);
	remove("data");
	rename("temp","data");
}
void sort()
{
	FILE *fp,*temp;
	struct student t[50];
	int i=0;
	fp=fopen("data","r");
	temp=fopen("sorted","wa");
	while(fread(&t[i++],sizeof(t[i]),1,fp));
	int j,k;
	for(j=0;j<i;j++)
		for(k=0;k<i-1;k++)
			if(strcmp(t[k].admn_no,t[k+1].admn_no)<0)
			{
				t[49]=t[k];
				t[k]=t[k+1];
				t[k+1]=t[49];
			}
	for(j=0;j<i;j++)
		fwrite(&t[j],sizeof(t[j]),1,temp);
	fclose(fp);
	fclose(temp);
	remove("data");
	rename("sorted","data");
	getch();
}

void main()
{
	while(1)
{
	system("clear");
	printf("\n1.Add new student\n2.Search\n3.Delete\n4.Show Full file\n5.Sort\n6.Exit :");
	switch(getch())
	{
		case '1':
			getdata();
			break;
		case '2':
			search();
			break;
		case '3':
			del();
			break;
		case '4':
			displayFullData();
			break;
		case '6':
			printf("\n");
			exit(0);
		case '5':
			sort();
			break;
		default:printf("\nInvalid input");
	}
}
}
