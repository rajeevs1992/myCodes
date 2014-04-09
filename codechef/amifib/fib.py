t=int(raw_input())
l=[0,1]
while t>0:
    n=int(raw_input())
    a=l[-2]
    b=l[-1]
    if n>l[-1]:
        c=a+b
        while n>=c:
            l.append(c)
            a=b
            b=c
            c=a+b
        if n==l[-1]:
            print "IsFibo"
        else:
            print "IsNotFibo"
    else:
        if n in l:
            print "IsFibo"
        else:
            print "IsNotFibo"
    t=t-1
