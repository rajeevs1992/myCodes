#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *input;
void E();
void A();
void T();
void F();
void B();
void error();
int main()
{
    char str[50],l;
    printf("Enter the string ");
    scanf("%s",str);
    str[strlen(str)]='~';
    input=str;
    E();
    if(input[0]=='~')
        printf("\nAccepted \n");
    else
        error();
    return 0;
}

void E()
{
    if(input[0]=='~')
        return;
    T();
    A();
}
void A()
{
    if(input[0]=='~')
        return;
    if(input[0]=='+')
    {
        input++;
        T();
        A();
    }
}
void T()
{
    if(input[0]=='~')
        return;
    F();
    B();
}
void B()
{
    if(input[0]=='~')
        return;
    if(input[0]=='*')
    {
        input++;
        F();
        B();
    }
}
void F()
{
    if(input[0]=='~')
        return;
    if(input[0]=='(')
    {
        input++;
        E();
        if(input[0]==')')
            input++;
    }
    else if(input[0]=='i')
        input++;
    else
        error();
}
void error()
{
    printf("\nInvalid \n");
    exit(1);
}
