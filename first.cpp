#include<iostream>
using namespace std;
class <template class t> test
{
    char a;
    char b;
    t c;
    public:
    test()
    {
        a='a';
        b='b';
        c='c';
    }
    display()
    {
        cout<<a<<b<<c;
    }
}
int main()
{
    cout<<"Hello world";
    test<int> a;
    a.display();
    return 0;
}
