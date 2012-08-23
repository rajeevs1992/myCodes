#include<stdio.h>
#include<iostream>
using namespace std;
main()
{
	int *b,a;
	void *v;
	a=1;
	b=&a;
	v=&a;
	cout<<*b<<*(int *)v;
}

