#include<stdio.h>
#define MOD(n) (n % 100000007)

int main()
{
    int t, initTax, slot1, slot2, k;
    long long int previous;
    long long int n;

    long long int krecent[200], kproducts[200];
    int previous_slot = -1, current_slot = 0, i;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d%d%lld", &initTax, &slot1, &slot2, &k, &n);

        current_slot = current_slot % k;

        previous = krecent[current_slot] = kproducts[current_slot] = initTax;
        n--;
        while(n)
        {
            if(slot1 != 0)
            {
                previous = MOD(previous + 1);
                slot1--;
            }
            else if(slot2 != 0)
            {
                previous = MOD(previous * 2);
                slot2--;
            }
            else
            {
                previous = kproducts[current_slot];
            }
            previous_slot = current_slot;
            current_slot = (current_slot + 1) % k;
            if(krecent[current_slot]!= 0)
                kproducts[current_slot] = MOD(previous * kproducts[previous_slot] / krecent[current_slot]) ;
            else
                kproducts[current_slot] = 0;
            krecent[current_slot] = previous;
            n--;
        }
        if(n <= (slot1 + slot2 + 1))
            printf("%lld\n", previous);
        else
            printf("%lld\n", kproducts[current_slot]);
    }
    return 0;
}
