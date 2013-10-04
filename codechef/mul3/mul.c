#include<stdio.h>
#include<limits.h>

#define gc getchar_unlocked
int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
int main()
{
    int n,q,array[100001]={0},i,j,a,b,m;
    unsigned long long int c=ULLONG_MAX,t;
    n=read_int();
    n=n&~(1<<n);
    q=read_int();
    while(q--)
    {
        m=read_int();
        a=read_int();
        b=read_int();
        i=a;
        if(m==0)
        {
            while(i<=b)
            {
                array[i] = (array[i]+1)%3;
                if(array[i]==0)
                    c=1<<i|c;
                else
                    c=(~(1<<i))&c;
                i++;
            }
        }
        else
        {
            if(a==b)
                if(c>>a&1)
                {
                    printf("1\n");
                    continue;
                }
                else
                {
                    printf("1\n");
                    continue;
                }
            t=c;
            t=t<<a;
            t=t>>(a+b-1);
            for(j=0;t>0;j++)
                t=t&t-1;
            printf("%d\n",j);
        }

    }
    return 0;
}
