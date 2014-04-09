from math import log
t=int(raw_input())
while t>0:
    t=t-1
    a=raw_input().split()
    l=int(a[0])
    d=int(a[1])
    s=int(a[2])
    c=int(a[3])
    ans = log(s)+(d-1)*log(c+1)
    l = log(l)
    if ans<l:
        print "DEAD AND ROTTING"
    else:
        print "ALIVE AND KICKING"

