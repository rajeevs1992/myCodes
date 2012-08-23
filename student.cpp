#include<iostream>
#include<string.h>
using namespace std;
class student
{
	public:
	
	char name[25];
	int marks[5];
	int total;
	float avg;
	void getdata()
	{
		total=0;
		cout<<"\nEnter name of the student ";
		cin>>name;
		cout<<"\nEnter marks in 5 subjects ";
		for(int i=0;i<5;i++)
		{
			cin>>marks[i];
			total+=marks[i];
		}
		avg=total/5;
	}
};

void display(char name[],student list[],char limit)
{
	student temp=list[0];
	cout<<"\nMarks of "<<name<<" :\n";
	for(int i=0;i<limit;i++)
	{
		if(strcmp(name,list[i].name)==0)
		{
			for(int j=0;j<5;j++)
				cout<<" "<<list[i].marks[j];
			cout<<"\nTotal :"<<list[i].total;
		}
		if(list[i].total>temp.total)
			temp=list[i];
	}
	cout<<"\nMarks of topper "<<temp.name<<" :\n";
	for(int i=0;i<5;i++)
		cout<<" "<<temp.marks[i];
	cout<<"\nTotal : "<<temp.total;
}

main()
{
	student list[10];
	char name[25];
	int limit;
	cout<<"\nEnter the number of students ";
	cin>>limit;
	for(int i=0;i<limit;i++)
		list[i].getdata();
	cout<<"\nEnter name to be searched ";
	cin>>name;
	display(name,list,limit);
}

