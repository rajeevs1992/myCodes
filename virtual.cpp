#include<iostream>
using namespace std;
class a
{
	public:
		virtual char f() {return 'a';}
	//			char f() {return 'a';}
				char g() {return 'a';}
				char testf() {return f();}
				char testg() {return g();}
};
class b:public a
{
	public:
		char f() {return 'b';}
		char g() {return 'b';}
};
main()
{
	b obj;
	cout<<obj.testf()<<endl<<obj.testg();
}
