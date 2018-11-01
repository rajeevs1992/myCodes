#include<stdio.h>

int digitsum(unsigned long num)
{
    int sum = 0;
    while(num)
    {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}

int minimize(unsigned long num, unsigned long d)
{
    int a = minimize(num);
    int b = minimize(num + d);
}

int main()
{
    return 0;
}
