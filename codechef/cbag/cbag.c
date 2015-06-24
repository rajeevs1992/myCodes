#include<stdio.h>
int main()
{
    int t, n;
    long long int memory, total, prev;
    scanf("%d", &t);
    while(t--)
    {
        total = 0, memory = 0, prev = 0;
        scanf("%d", &n);
        while(n--)
        {
            prev = memory;   
            scanf("%lld", &memory);
            if(memory > prev)
                total += (memory - prev);
        }
        printf("%lld\n", total);
    }
    return 0;
}
