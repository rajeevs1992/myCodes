import math
l=[]
t=int(raw_input())
while t>0:
    n=raw_input().split()
    m=(int(n[0])-1)%1000000007
    n=(int(n[1])-1)%1000000007
    w=1
    for i in range(m+1,m+n+1):
        w=(w*i)%1000000007
    w=w/math.factorial(n)
    print w%1000000007
    t=t-1
