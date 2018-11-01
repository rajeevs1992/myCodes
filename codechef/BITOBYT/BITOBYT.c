#include<stdio.h>
int main()
{
    int t,n,i;
    unsigned long bit=1, nibble=0, byte=0;
    int nextphase=1, nextstep;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        bit = 1;
        nibble = 0;
        byte = 0;
        nextstep = 2;
        nextphase = 1;
        i = 0;
        while(1)
        {
            if(i+nextstep >= n)
            {
                printf("%lu %lu %lu\n", bit, nibble, byte);
                break;
            }
            else
            {
                i = i+nextstep;
                switch(nextphase)
                {
                    case 1:
                    {
                        nibble = bit;
                        bit = 0;
                        nextstep = 8;
                        nextphase = 2;
                    }
                    break;
                    case 2:
                    {
                        byte = nibble;
                        nibble = 0;
                        nextstep = 16;
                        nextphase = 3;
                    }
                    break;
                    case 3:
                    {
                        bit += (byte*2);
                        byte = 0;
                        nextstep = 2;
                        nextphase = 1;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
