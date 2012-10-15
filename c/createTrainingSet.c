#include<stdio.h>
struct house
{
	int size;
	float cost;
}h;
int main()
{
	int n,i;
	FILE *fp=fopen("data","w");
	printf("\nEnter the number of items ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter size and cost ");
		scanf("%d%f",&h.size,&h.cost);
		fwrite(&h,sizeof(h),1,fp);
	}
	fclose(fp);
}
